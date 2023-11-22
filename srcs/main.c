/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:40:55 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/14 22:10:55 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	destroy_img(t_game *game)
{
	if (game->map_img.img)
		mlx_destroy_image(game->mlx, game->map_img.img);
	if (game->noth_img.img)
		mlx_destroy_image(game->mlx, game->noth_img.img);
	if (game->south_img.img)
		mlx_destroy_image(game->mlx, game->south_img.img);
	if (game->east_img.img)
		mlx_destroy_image(game->mlx, game->east_img.img);
	if (game->west_img.img)
		mlx_destroy_image(game->mlx, game->west_img.img);
}

int	finish_game(t_game *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->mlx_window);
	mlx_destroy_display(game->mlx);
	free (game->mlx);
	free_n_exit(game);
	ft_putendl_fd("Hope to see you back soon :)", STDOUT_FILENO);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	check_input(ac, av);
	inicialize(&game);
	if (!get_color_n_textures(&game, av[1]))
		exit_game(&game, "Unable to read fd\n");
	init_graphics(&game);
	game_loop(&game);
	mlx_hook(game.mlx_window, 2, 1L << 0, move_player, &game);
	mlx_hook(game.mlx_window, 17, 1L << 0, finish_game, &game);
	mlx_loop(game.mlx);
	free_n_exit(&game);
}
