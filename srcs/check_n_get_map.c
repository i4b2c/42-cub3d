/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_get_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:48:37 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/16 01:11:42 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_start_coord(t_game *game, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				game->player.player_pos_y = y + 0.5;
				game->player.player_pos_x = x + 0.5;
				game->map[y][x] = '0';
				game->player.play_start_dir = map[y][x];
				get_player_direction(game, game->player.play_start_dir);
			}
		}
	}
}

void	check_inner_map(t_game *game, char **map)
{
	int		i;
	char	**temp;

	i = 0;
	while (map[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (map[++i])
		temp[i] = ft_strdup(map[i]);
	temp[i] = NULL;
	player_start_coord(game, temp);
	check_holes_in_wall(game, temp);
	free_array(temp);
}

void	get_map(t_game *game, int fd)
{
	char	*temp;

	temp = NULL;
	while (game->line != NULL)
	{
		line_empty(game, game->line);
		if (!forbiden(game->line) && !game->is_valid)
			game->is_valid = 4;
		if (!temp)
			temp = ft_strdup(game->line);
		else
			temp = ft_strjoin_free(temp, game->line);
		free (game->line);
		game->line = get_next_line(fd);
	}
	game->map = ft_split(temp, '\n');
	free (temp);
	if (!is_out_wall_closed(game->map) && !game->is_valid)
		game->is_valid = 5;
	if (check_num_players(game->map) != 1 && !game->is_valid)
		game->is_valid = 6;
	check_inner_map(game, game->map);
}

void	first_parse_check(t_game *game, bool map)
{
	if (map == false)
		exit_game(game, "There's no actual map in your file\n");
	if (!game->is_valid && (game->ceiling == -1 || game->floor == -1))
		game->is_valid = 8;
	else if (!game->north || !game->south || !game->east || !game->west)
		game->is_valid = 8;
}

bool	get_color_n_textures(t_game *game, char *file)
{
	int		fd;
	bool	map;

	map = false;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	game->line = get_next_line(fd);
	while (game->line)
	{
		if (!check_line(game))
			map = true;
		if (map == true)
			break ;
		free(game->line);
		game->line = get_next_line(fd);
	}
	first_parse_check(game, map);
	get_map(game, fd);
	overall_parse_check(game);
	close (fd);
	return (true);
}
