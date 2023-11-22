/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 06:36:23 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/16 01:09:28 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_lateral_walls(char *str)
{
	char	*temp;

	temp = ft_strtrim(str, " \t");
	if (temp[0] != ' ' && temp[0] != '\t' && temp[0] != '1')
	{
		free (temp);
		return (false);
	}
	else if (temp[ft_strlen(temp) - 1] != ' ' && temp[ft_strlen(temp) - 1]
		!= '\t' && temp[ft_strlen(temp) - 1] != '1')
	{
		free(temp);
		return (false);
	}
	free (temp);
	return (true);
}

bool	is_out_wall_closed(char **map)
{
	int		last;
	int		i;
	char	**temp;

	last = 0;
	i = -1;
	while (map[last])
		last++;
	temp = malloc(sizeof(char *) * (last + 1));
	while (map[++i])
		temp[i] = ft_strdup(map[i]);
	temp[i] = NULL;
	if (!check_first_last_wall(temp[0])
		|| !check_first_last_wall(temp[last - 1]))
		last = -1;
	i = -1;
	while (temp[++i] && last >= 0)
		if (!check_lateral_walls(temp[i]))
			last = -1;
	free_array(temp);
	if (last >= 0)
		return (true);
	return (false);
}

void	check_holes(t_game *game, char **map, int y, int x)
{
	if (map[y][x + 1] == ' ' || map[y][x + 1] == '\t'
		|| map[y][x + 1] == '\n' || !map[y][x + 1])
		game->is_valid = 7;
	else if (map[y][x - 1] == ' ' || map[y][x - 1] == '\t'
		|| map[y][x - 1] == '\n' || !map[y][x - 1])
		game->is_valid = 7;
	else if (map[y + 1][x] == ' ' || map[y + 1][x] == '\t'
		|| map[y + 1][x] == '\n' || !map[y + 1][x])
		game->is_valid = 7;
	else if (map[y - 1][x] == ' ' || map[y - 1][x] == '\t'
		|| map[y - 1][x] == '\n' || !map[y - 1][x])
		game->is_valid = 7;
}

void	check_holes_in_wall(t_game *game, char **map)
{
	int	x;

	auto int y = 0;
	while (map[y] && !game->is_valid)
	{
		x = 0;
		while (map[y][x] && !game->is_valid)
		{
			if (map[y][x] == '0')
				check_holes(game, map, y, x);
			x++;
		}
		y++;
	}
}

bool	check_first_last_wall(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != '1' && str[i] != ' ' && str[i != '\t'])
			return (false);
	return (true);
}
