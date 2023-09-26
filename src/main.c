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


#include <mlx.h>
#include <stdbool.h>
#include <math.h>

typedef struct s_game
{
    void *mlx;
    void *win;
    void *game_temp;
    void *blank;
    int x_map;
    int y_map;
    int player_x;
    int player_y;
    char **map;
} t_game;

bool is_left_key_pressed = false;
bool is_right_key_pressed = false;
bool is_up_key_pressed = false;
bool is_down_key_pressed = false;
bool is_left_camera = false;
bool is_right_camera = false;
int i = 60;

void draw_pixel(t_game *game, int x, int y, int color)
{
    mlx_pixel_put(game->mlx, game->win, x, y, color);
}

// void draw_vision(t_game *game, int x , int y, int color)
// {
//     while(y > 0)
//         draw_pixel(game,x+9,y--,color);
// }

bool get_pos_map(t_game game, int x_pixel, int y_pixel, int *cor)
{
    // Converta as coordenadas de pixel para coordenadas do mapa
    int x_map = x_pixel / 64;
    int y_map = y_pixel / 64;

    // Verifique se as coordenadas estão dentro dos limites do mapa
    if (x_map >= 0 && x_map < game.x_map && y_map >= 0 && y_map < game.y_map)
    {
        // Verifique se o caractere na posição correspondente no mapa é '1'
        if (game.map[y_map][x_map] == '1')
        {
            if(game.map[(y_pixel - 1) / 64][x_map] == '0' || game.map[(y_pixel + 1) / 64][x_map] == '0'
                && game.map[y_map][(x_pixel - 1) / 64] == '0' || game.map[y_map][(y_pixel + 1) / 64] == '0')
                *cor = 0xFF0000;
            else if(game.map[(y_pixel - 1) / 64][x_map] == '0' || game.map[(y_pixel + 1) / 64][x_map] == '0')
                *cor = 0x00FF00;
            else if(game.map[y_map][(x_pixel - 1) / 64] == '0' || game.map[y_map][(y_pixel + 1) / 64] == '0')
                *cor = 0x0000FF;
            return true; // Encontrou um '1'
        }
    }

    return false; // Não encontrou um '1' ou as coordenadas estão fora dos limites
}

// void render(double distance, double angle_deg,t_game *game)
// {
//     int temp = (angle_deg - i)/3;//63-60/3
//     int temp_distance = 500 - distance;
//     mlx_put_image_to_window(game->mlx,game->win,game->blank,temp*20,temp_distance);
// }


void render(double distance, double angle_deg, t_game *game)
{
    // Suponha que a altura da janela seja 600 pixels
    int window_height = 400;

    // Calcule a coordenada Y para renderizar a imagem
<<<<<<< HEAD
    float temp_y = distance / 721;
=======
    float temp_y = distance / 600;
>>>>>>> fae38a99c13ba114ae66670e2184e5e334e10924
    printf("%f %f\n",distance,temp_y);
    int y = 400 * temp_y;
    int temp = (angle_deg - i);
    int y_temp;
    y_temp = 400 - y;

    // Renderize a imagem em (x, y)
    printf("%d %d\n",y_temp,y);
    while(y <= y_temp)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->blank,(30 - temp) * 20, y);
        y += 20;
   }
    mlx_put_image_to_window(game->mlx, game->win, game->blank,(30 - temp) * 20, y_temp );

}

void draw_line(void *mlx, void *win, int x1, int y1, double angle_deg, int length, int color, t_game *game)
{
    double angle_rad = angle_deg * M_PI / 180.0; // Converter o ângulo de graus para radianos
    int x2 = x1 + (int)(length * cos(angle_rad));
    int y2 = y1 - (int)(length * sin(angle_rad)); // Usamos -sin porque as coordenadas da janela aumentam para baixo

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
<<<<<<< HEAD
        int cor;
        if (get_pos_map((*game), x1, y1,&cor))
=======
        if (get_pos_map((*game), x1, y1))
>>>>>>> fae38a99c13ba114ae66670e2184e5e334e10924
        {
            double distance = sqrt((x1 - game->player_x) * (x1 - game->player_x) + (y1 - game->player_y) * (y1 - game->player_y));
            // printf("%2.f %2.f\n",angle_deg,distance);
            render(distance,angle_deg,game);
<<<<<<< HEAD
            mlx_pixel_put(mlx, game->game_temp, x1, y1, cor);
=======
            mlx_pixel_put(mlx, game->game_temp, x1, y1, 255);
>>>>>>> fae38a99c13ba114ae66670e2184e5e334e10924
            break; // Se encontrou um '1', saia do loop
        }
            mlx_pixel_put(mlx, game->game_temp, x1, y1, color);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_player(t_game *game)
{
    int temp_x;
    int temp_y;

    temp_x = game->player_x;
    while(temp_x < game->player_x + 2)
    {
        temp_y = game->player_y;
        while(temp_y < game->player_y + 2)
        {
            draw_pixel(game,temp_x,temp_y,0xFFFFFF);
            temp_y++;
        }
        temp_x++;
    }
}

void draw_vision(t_game *game)
{
    int j = i;
    while(j < i + 30)
    {
        draw_line(game->mlx,game->win,game->player_x,game->player_y,j,1000,0xFFFFFF,game);
        j++;
    }
}

int update_game(t_game *game)
{
    int cor = 0;
    (void)cor;
    if (is_left_key_pressed && !get_pos_map(*game,game->player_x-1,game->player_y,&cor))
        game->player_x -= 1; // Move the player to the left
<<<<<<< HEAD
    if (is_right_key_pressed && !get_pos_map(*game,game->player_x+1,game->player_y,&cor))
=======
    if (is_right_key_pressed && !get_pos_map(*game,game->player_x+1,game->player_y))
>>>>>>> fae38a99c13ba114ae66670e2184e5e334e10924
        game->player_x += 1; // Move the player to the right
    if (is_up_key_pressed && !get_pos_map(*game,game->player_x,game->player_y-1,&cor))
        game->player_y -= 1;
<<<<<<< HEAD
    if (is_down_key_pressed && !get_pos_map(*game,game->player_x,game->player_y+1,&cor))
=======
    if (is_down_key_pressed && !get_pos_map(*game,game->player_x,game->player_y+1))
>>>>>>> fae38a99c13ba114ae66670e2184e5e334e10924
        game->player_y += 1;
    if(is_right_camera)
    {
        i++;
        if(i > 360)
            i = 0;
    }
    if(is_left_camera)
    {
        i--;
        if(i < -1)
            i = 360;
    }

    mlx_clear_window(game->mlx, game->win); // Clear the window
    mlx_clear_window(game->mlx, game->game_temp); // Clear the window
    draw_vision(game);

    return 0;
}

int key_press(int keycode, t_game *game)
{
    if (keycode == A) // Left arrow key
        is_left_key_pressed = true;
    if (keycode == D) // Right arrow key
        is_right_key_pressed = true;
    if(keycode == W)
        is_up_key_pressed = true;
    if(keycode == S)
        is_down_key_pressed = true;
    if(keycode == 65361)
        is_right_camera = true;
    if(keycode == 65363)
        is_left_camera = true;

    return 0;
}

int key_release(int keycode, t_game *game)
{
    printf("%d\n",keycode);
    if (keycode == A) // Left arrow key
    {
        is_left_key_pressed = false;
    }
    if (keycode == D) // Right arrow key
    {
        is_right_key_pressed = false;
    }
    if(keycode == W)
    {
        is_up_key_pressed = false;
    }
    if(keycode == S)
    {
        is_down_key_pressed = false;
    }
    if(keycode == 65361)
        is_right_camera = false;
    if(keycode == 65363)
        is_left_camera = false;

    return 0;
}

int main(int ac, char **av)
{
    t_game game;

    void *mlx;
    void *mlx_win;
    int x, y;
    int fd;
    char **map;

   // mlx = mlx_init();
    fd = get_x_y(&x, &y, av);
    //mlx_win = mlx_new_window(mlx, x * 64, y * 64, "teste");
    game.map = NULL;
    game.map = get_map(x, y, fd);
    game.x_map = x;
    game.y_map = y;
    close(fd);

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 600, 400, "Simple 2D Game");
    game.game_temp = mlx_new_window(game.mlx,600,400,"teste");
    int temp_x = 1;
    int temp_y = 1;
    game.blank = mlx_xpm_file_to_image(game.mlx,"blank.xpm",&temp_x,&temp_y);
    // render_map(game.mlx, game.win, x, y, game.map);

    game.player_x = 400; // Initial X position of the player
    game.player_y = 300; // Initial Y position of the player

    mlx_hook(game.win, 2, 1L << 0, key_press, &game); // Register key press event
    mlx_hook(game.win, 3, 1L << 1, key_release, &game); // Register key release event

    mlx_loop_hook(game.mlx, &update_game, &game); // Register the update function
    mlx_loop(game.mlx);

    return 0;
}
