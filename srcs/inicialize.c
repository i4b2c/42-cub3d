/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:45:27 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/18 20:25:35 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	inicialize(t_game *game)
{
	game->player.play_start_dir = '\0';
	game->map = NULL;
	game->player.player_pos_x = 0;
	game->player.player_pos_y = 0;
	game->ceiling = -1;
	game->floor = -1;
	game->line = NULL;
	game->north = NULL;
	game->south = NULL;
	game->east = NULL;
	game->west = NULL;
	game->pixel = 0;
	game->player.hit = 0;
	game->is_valid = 0;
	game->line_empty = false;
}

void	get_player_direction2(t_game *game, char c)
{
	if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = PLANE;
		return ;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -PLANE;
		return ;
	}
}

void	get_player_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = PLANE;
		game->player.plane_y = 0;
		return ;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -PLANE;
		game->player.plane_y = 0;
		return ;
	}
	get_player_direction2(game, c);
}
