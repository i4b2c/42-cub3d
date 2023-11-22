/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:24:46 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/15 03:27:30 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_array(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free (split);
}

void	free_n_exit(t_game *game)
{
	if (!game)
		return ;
	if (game->line)
		free (game->line);
	if (game->north)
		free (game->north);
	if (game->south)
		free (game->south);
	if (game->east)
		free (game->east);
	if (game->west)
		free (game->west);
	if (game->map)
		free_array (game->map);
}

int	exit_game(t_game *game, char *error_text)
{
	free(game->mlx);
	free_n_exit(game);
	ft_putendl_fd("Ops, the game crashed", STDERR_FILENO);
	ft_putstr_fd(error_text, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
