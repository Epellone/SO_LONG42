/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:22:23 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 17:56:12 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game game)
{
	int	i;
	int	code;

	code = 1;
	i = -1;
	while (++i < game.widthmap)
	{
		if (game.map[0][i] != '1')
			return (error(code));
		if (game.map[game.heightmap - 1][i] != '1')
			return (error(code));
	}
	i = 1;
	while (i < game.heightmap - 1)
	{
		if (game.map[i][0] != '1')
			return (error(code));
		if (game.map[i][game.widthmap - 1] != '1')
			return (error(code));
		i++;
	}
	return (1);
}

int	check_rectangle(t_game game)
{
	int	i;
	int	j;
	int	code;

	code = 2;
	i = 0;
	j = 0;
	while (i < game.heightmap)
	{
		j = 0;
		while (game.map[i][j] != '\0' && game.map[i][j] != '\n')
			j++;
		if (j != game.widthmap)
			return (error(code));
		i++;
	}
	return (1);
}

int	check_exit_and_player_bool(t_game *game)
{
	int	code;

	code = 3;
	check_exit_and_player(game);
	if (game->check_p != 1 || game->check_n != 1 || game->coin == 0)
		return (error(code));
	return (1);
}

void	check_exit_and_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->heightmap)
	{
		j = -1;
		while (++j < game->widthmap)
		{
			if (game->map[i][j] == 'P')
				game->check_p++;
			if (game->map[i][j] == 'E')
				game->check_n++;
			if (game->map[i][j] == 'C')
				game->coin++;
		}
	}
}

int	check_different(t_game game)
{
	int	i;
	int	j;
	int	code;

	code = 4;
	i = -1;
	while (++i < game.heightmap)
	{
		j = -1;
		while (++j < game.widthmap)
		{
			if (game.map[i][j] != '1' && game.map[i][j] != 'C'
			&& game.map[i][j] != 'N' && game.map[i][j] != 'P'
			&& game.map[i][j] != 'E' && game.map[i][j] != '0')
				return (error(code));
		}
	}
	return (1);
}
