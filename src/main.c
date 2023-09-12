#include "../include/cub3d.h"

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


int main(int ac, char **av)
{
	void *mlx;
	void *mlx_win;
	int x,y;

	if(ac == 2)
	{
		mlx = mlx_init();
		get_x_y(&x,&y,av);
		mlx_win = mlx_new_window(mlx,x*64,y*64,"teste");
		mlx_pixel_put(mlx,mlx_win,2*64,2*64,255);
		mlx_loop(mlx);
	}
	else
		ft_putstr_fd("Error\n",STDERR_FILENO);
	return 0;
}
