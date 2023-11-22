/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:51:56 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/15 23:00:36 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	final_x_text(t_player_view *player)
{
	int	texture;

	if (!player->wall_side && player->ray_dir_y < 0)
		texture = player->t_x - TILE_SIZE - 1;
	if (player->wall_side && player->ray_dir_x > 0)
		texture = player->t_x - TILE_SIZE - 1;
	else
		texture = player->t_x;
	return (texture);
}

void	get_x_text(t_player_view *player)
{
	double	wall;

	wall = get_wall_side(player);
	player->t_x = (int)(wall * (double)(TILE_SIZE));
	if (!player->wall_side && player->ray_dir_x < 0)
		player->t_x = TILE_SIZE - player->t_x;
	else if (player->wall_side && player->ray_dir_y > 0)
		player->t_x = TILE_SIZE - player->t_x;
}

void	save_sprite(t_game *game)
{
	if (!game->player.wall_side)
	{
		if (game->player.player_pos_x < game->player.map_x)
			game->sprite_img = game->east_img;
		else
			game->sprite_img = game->west_img;
	}
	else
	{
		if (game->player.player_pos_y > game->player.map_y)
			game->sprite_img = game->noth_img;
		else
			game->sprite_img = game->south_img;
	}
	get_x_text(&game->player);
}

double	tex_pos(t_game *game, double y)
{
	double	pos;

	pos = (game->player.start_draw - W_HEIGHT
			/ 2 + game->player.wall_height / 2) * y;
	return (pos);
}

double	tex_step_y(t_game *game)
{
	double	y;

	y = 1.0 * TILE_SIZE / game->player.wall_height;
	return (y);
}
