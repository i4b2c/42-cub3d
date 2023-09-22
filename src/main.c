#include "../include/cub3d.h"

#include <mlx.h>
#include <math.h>

#define WHITE 0xFFFFFF

int	funcao_x(int fd)
{
	char	*s;
	int		x;
	int		temp;

	s = get_next_line(fd);
	x = ft_strlen(s) - 1;
	temp = x;
	free(s);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		x = ft_strlen(s) - 1;
		free(s);
		if (temp != x)
			return (-1);
	}
	return (x);
}

int	funcao_y(int fd)
{
	char	*s;
	int		y;

	y = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		y++;
		free(s);
	}
	return (y);
}

int	get_x_y(int *x, int *y, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	*y = funcao_y(fd);
	fd = open(av[1], O_RDONLY);
	*x = funcao_x(fd);
	fd = open(av[1], O_RDONLY);
	return (fd);
}

char	**get_map(int x, int y, int fd)
{
	char	*s;
	int		k;
	char **map;

	map = malloc(y * sizeof (char *));
	k = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		map[k] = ft_strtrim(s, "\n");
		map[k][x] = 0;
		free(s);
		k++;
	}
	return map;
}

// void put_pixel(void *mlx, void *win, int x, int y, int color)
// {
// 	int x1;
// 	int y1;

// 	x1 = 0;
// 	y1 = 0;
// 	while(x1 < 64)
// 	{
// 		y1 = 0;
// 		while(y1 < 64)
// 		{
// 			mlx_pixel_put(mlx,win,y1*y,x1*x,color);
// 			y1++;
// 		}
// 		x1++;
// 	}
// }

void put_pixel(void *mlx, void *win, int x, int y, int size, int color)
{
    int x1;
    int y1;

    x1 = x;
    while (x1 < x + size)
    {
        y1 = y;
        while (y1 < y + size)
        {
            mlx_pixel_put(mlx, win, x1, y1, color);
            y1++;
        }
        x1++;
    }
}

// void render_init(void *mlx, void *win, int x, int y, char **map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while(map[i])
// 	{
// 		j = 0;
// 		while(map[i][j])
// 		{
// 			write(1,&map[i][j],1);
// 			printf("%d %d %d %d\n",i,j,x,y);
// 			if(map[i][j] == '1')
// 				put_pixel(mlx,win,x,y,64,255);
// 			else
// 				put_pixel(mlx,win,x,y,64,128);
// 			j++;
// 		}
// 		i++;
// 	}
//}


#define COLOR_WALL 255
#define COLOR_EMPTY 128

// Função para determinar a cor com base no valor do mapa
int get_pixel_color(int value) {
    if (value == 1) {
        return COLOR_WALL;
    } else {
        return WHITE;
    }
}

// Função para renderizar o mapa com as cores corretas
void render_map(void *mlx, void *win, int x, int y, char **map) {
    int pixel_size = 64; // Tamanho dos quadrados do mapa

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int color = get_pixel_color(map[i][j] - '0'); // Converte de char para int e determina a cor
            put_pixel(mlx, win, j * pixel_size, i * pixel_size, pixel_size, color);
        }
    }
}

// int main(int ac, char **av)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	int x,y;
// 	int fd;
// 	char **map;

// 	if(ac == 2)
// 	{
// 		mlx = mlx_init();
// 		fd = get_x_y(&x,&y,av);
// 		mlx_win = mlx_new_window(mlx,x*64,y*64,"teste");
// 		map = NULL;
// 		map = get_map(x,y,fd);
// 		close(fd);
// 		fd = open(av[1],O_RDONLY);
// 		render_init(mlx,mlx_win,x,y,map);
// 		//mlx_pixel_put(mlx,mlx_win,2*64,2*64,255);
// 		mlx_loop(mlx);
// 	}
// 	else
// 		ft_putstr_fd("Error\n",STDERR_FILENO);
// 	return 0;
// }

int main(int ac, char **av) {
    void *mlx;
    void *mlx_win;
    int x, y;
    int fd;
    char **map;

    if (ac == 2) {
        mlx = mlx_init();
        fd = get_x_y(&x, &y, av);
        mlx_win = mlx_new_window(mlx, x * 64, y * 64, "teste");
        map = NULL;
        map = get_map(x, y, fd);
        close(fd);

        render_map(mlx, mlx_win, x, y, map);

        mlx_loop(mlx);
    } else {
        ft_putstr_fd("Error\n", STDERR_FILENO);
    }
    return 0;
}
