/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:06:42 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 18:16:34 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_map(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

static int	height_map(t_game *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temp[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	map_reading(t_game *game, char **argv)
{
	char	*rdmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (error(5));
	while (1)
	{
		rdmap = get_next_line(game->fd);
		if (height_map(game, rdmap) == 0)
			break ;
	}
	close(game->fd);
	if (!game->map && !game->widthmap)
		return (error(5));
	game->widthmap = width_map(game->map[0]);
	if (!check_rectangle(*game) || !check_exit_and_player_bool(game)
		|| !check_walls(*game) || !check_different(*game))
		return (0);
	return (1);
}
