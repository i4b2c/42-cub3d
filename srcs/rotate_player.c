/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:07:09 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/15 06:27:14 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	rotate_vec(double x, double y, int flag)
{
	double	new_x;
	double	new_y;

	new_x = x * cos(PI / 2) - y * sin(PI / 2);
	new_y = x * sin(PI / 2) + y * cos(PI / 2);
	if (flag == 'x')
		return (new_x);
	else
		return (new_y);
}

void	rotate_right(t_game *game)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x
		* cos(ROT) - game->player.dir_y * sin(ROT);
	game->player.dir_y = old_dir_x
		* sin(ROT) + game->player.dir_y * cos(ROT);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x
		* cos(ROT) - game->player.plane_y * sin(ROT);
	game->player.plane_y = old_plane_x
		* sin(ROT) + game->player.plane_y * cos(ROT);
	game_loop(game);
}

void	rotate_left(t_game *game)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x
		* cos(-ROT) - game->player.dir_y * sin(-ROT);
	game->player.dir_y = old_dir_x
		* sin(-ROT) + game->player.dir_y * cos(-ROT);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x
		* cos(-ROT) - game->player.plane_y * sin(-ROT);
	game->player.plane_y = old_plane_x
		* sin(-ROT) + game->player.plane_y * cos(-ROT);
	game_loop(game);
}
