/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:11:21 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/14 19:53:39 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_img(t_game *game)
{
	if (!game->noth_img.img || !game->east_img.img
		|| !game->west_img.img || !game->south_img.img)
	{
		destroy_img(game);
		exit_game(game, "convert xmp to img just failed\n");
	}
}

void	init_addr(t_game *game)
{
	game->noth_img.addr = mlx_get_data_addr(game->noth_img.img,
			&game->noth_img.bpp, &game->noth_img.line_len,
			&game->noth_img.endian);
	game->east_img.addr = mlx_get_data_addr(game->east_img.img,
			&game->east_img.bpp, &game->east_img.line_len,
			&game->east_img.endian);
	game->west_img.addr = mlx_get_data_addr(game->west_img.img,
			&game->west_img.bpp, &game->west_img.line_len,
			&game->west_img.endian);
	game->south_img.addr = mlx_get_data_addr(game->south_img.img,
			&game->south_img.bpp, &game->south_img.line_len,
			&game->south_img.endian);
}

void	init_xpm_img(t_game *game)
{
	int	tile_size;

	tile_size = TILE_SIZE;
	game->noth_img.img = mlx_xpm_file_to_image
		(game->mlx, NORTH_IMG, &tile_size, &tile_size);
	game->south_img.img = mlx_xpm_file_to_image
		(game->mlx, SOUTH_IMG, &tile_size, &tile_size);
	game->east_img.img = mlx_xpm_file_to_image
		(game->mlx, EAST_IMG, &tile_size, &tile_size);
	game->west_img.img = mlx_xpm_file_to_image
		(game->mlx, WEST_IMG, &tile_size, &tile_size);
	check_img(game);
	init_addr(game);
}

void	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	init_xpm_img(game);
}
