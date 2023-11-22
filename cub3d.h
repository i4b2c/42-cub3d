/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:54:43 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/16 01:15:03 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <stdbool.h>
# include <math.h>

# define A 97
# define S 115
# define D 100
# define W 119

# define ESC 65307
# define RIGHT 65363
# define LEFT 65361

# define NORTH_IMG "./sprites/north_wall.xpm"
# define SOUTH_IMG "./sprites/south_wall.xpm"
# define EAST_IMG "./sprites/east_wall.xpm"
# define WEST_IMG "./sprites/west_wall.xpm"

# define W_HEIGHT 550
# define W_WIDTH 1000
# define TILE_SIZE 64
# define PLANE 0.66

# define PI 3.14159265358979323846

# define MOV 0.2
# define ROT 0.05

typedef struct s_animation
{
	int		line_len;
	int		endian;
	void	*img;
	int		bpp;
	char	*addr;
}			t_animation;

typedef struct s_player_view
{
	float		player_pos_x;
	float		player_pos_y;
	char		play_start_dir;
	double		plane_x;
	double		plane_y;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		ray_dir_x;
	double		ray_dir_y;
	int			step_x;
	int			step_y;
	double		side_dist_x;
	double		side_dist_y;
	double		d_dist_x;
	double		d_dist_y;
	int			hit;
	int			wall_side;
	int			start_draw;
	int			end_draw;
	double		wall_height;
	double		perp_wall_dist;
	int			t_x;
	int			t_y;
}				t_player_view;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_window;
	char			**map;
	int				is_valid;
	int				floor;
	int				ceiling;
	int				wall;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*line;
	int				pixel;
	int				color;
	bool			line_empty;
	t_animation		map_img;
	t_animation		noth_img;
	t_animation		south_img;
	t_animation		east_img;
	t_animation		west_img;
	t_animation		sprite_img;
	t_player_view	player;
}					t_game;

void	check_input(int ac, char **av);
void	inicialize(t_game *game);
bool	get_color_n_textures(t_game *game, char *file);
int		exit_game(t_game *game, char *msg);
void	free_array(char **split);
bool	is_valid_file(char *line);
bool	is_all_numbers(char **colors);
void	line_empty(t_game *game, char *line);
int		exit_error(t_game *game, char *error_text);
void	get_texture(t_game *game, char *line, char c);
bool	split_colors(char **colors, char *line, size_t i);
bool	convert_rgb(t_game *game, char **colors, char c);
void	get_rgb(t_game *game, char *line, char c);
bool	forbiden(char *line);
void	flood_fill(t_game *game, int x, int y, char **str);
bool	is_out_wall_closed(char **map);
bool	check_first_last_wall(char *str);
int		check_num_players(char **map);
bool	overall_parse_check(t_game *game);
bool	check_line(t_game *game);
bool	check_line_again(t_game *game, char *temp);
void	free_n_exit(t_game *game);
void	player_start_coord(t_game *game, char **map);
void	check_inner_map(t_game *game, char **map);
void	get_map(t_game *game, int fd);
bool	get_color_n_textures(t_game *game, char *file);
void	init_graphics(t_game *game);
int		render_backgroung(t_game *game);
void	apply_dda(t_game *game);
void	get_the_ray(t_game *game);
void	get_step_sided(t_game *game);
void	map_pos(t_game *game);
void	get_wall_height(t_player_view *player);
void	get_player_direction(t_game *game, char c);
void	draw_column(t_game *game);
int		game_loop(t_game *game);
void	get_player_direction(t_game *game, char c);
int		move_player(int key, t_game *game);
int		finish_game(t_game *game);
double	rotate_vec(double x, double y, int flag);
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	destroy_img(t_game *game);
void	print_array(char **map);
void	check_holes_in_wall(t_game *game, char **map);
void	check_holes(t_game *game, char **map, int y, int x);
double	tex_step_y(t_game *game);
double	tex_pos(t_game *game, double y);
void	save_sprite(t_game *game);
void	get_x_text(t_player_view *player);
int		final_x_text(t_player_view *player);
double	get_wall_side(t_player_view *player);
#endif