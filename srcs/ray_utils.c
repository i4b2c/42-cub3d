/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 06:07:13 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/15 23:02:08 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_pixel(t_animation *img, int x, int y)
{
	return (*(unsigned int *)((img->addr
			+ (y * img->line_len) + (x * (img->bpp / 8)))));
}

void	get_wall_height(t_player_view *player)
{
	if (player->wall_side == 0)
		player->perp_wall_dist = player->side_dist_x - player->d_dist_x;
	else
		player->perp_wall_dist = player->side_dist_y - player->d_dist_y;
	player->wall_height = (W_HEIGHT / player->perp_wall_dist);
	player->start_draw = (W_HEIGHT / 2) + (-player->wall_height / 2);
	if (player->start_draw < 0)
		player->start_draw = 0;
	player->end_draw = (W_HEIGHT / 2) + (player->wall_height / 2);
	if (player->end_draw >= W_HEIGHT)
		player->end_draw = W_HEIGHT -1;
}

void	draw_column(t_game *game)
{
	int		x;
	int		y;
	double	step;
	double	pos;

	step = tex_step_y(game);
	pos = tex_pos(game, step);
	y = game->player.start_draw;
	x = game->pixel;
	while (y < game->player.end_draw)
	{
		game->player.t_y = (int)pos & (TILE_SIZE - 1);
		pos += step;
		game->color = get_pixel(&game->sprite_img,
				game->player.t_x, game->player.t_y);
		my_mlx_pixel_put(game, x, y, game->color);
		y++;
	}
	game->player.hit = 0;
}
