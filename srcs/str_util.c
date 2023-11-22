/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 06:22:00 by acanelas          #+#    #+#             */
/*   Updated: 2023/11/16 01:09:20 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_valid_file(char *line)
{
	int	i;
	int	fd;

	i = ft_strlen(line);
	if (!ft_strnstr(line, ".xpm", i))
		return (false);
	fd = open(line, O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		return (false);
	}
	close(fd);
	return (true);
}

bool	is_all_numbers(char **colors)
{
	int	i;
	int	j;

	i = 0;
	while (colors[i])
	{
		j = 0;
		while (colors[i][j])
		{
			if (!ft_isdigit(colors[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	line_empty(t_game *game, char *line)
{
	int		i;
	bool	is_empty;

	i = -1;
	is_empty = true;
	while (line[++i] && !game->is_valid && is_empty)
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
		{
			is_empty = false;
			if (game->line_empty)
				game->is_valid = 9;
		}
	}
	if (line[i] == '\0')
		game->line_empty = true;
}

void	flood_fill(t_game *game, int x, int y, char **str)
{
	if (str[y][x] == ' ' || (str[y][x] >= 9 && str[y][x] <= 13))
	{
		game->is_valid = 7;
	}
	if (str[y][x] == '1' || game->is_valid)
		return ;
	str[y][x] = '1';
	flood_fill(game, x + 1, y, str);
	flood_fill(game, x - 1, y, str);
	flood_fill(game, x, y + 1, str);
	flood_fill(game, x, y - 1, str);
}
