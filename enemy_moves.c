/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:39:22 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 17:54:19 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_animations(t_game *game)
{
	if (game->countenemy < 10000)
		return ;
	if (game->memenemy == 0)
		move_left_enemy(game);
	if (game->memenemy == 1)
		move_right_enemy(game);
	game->countenemy = 0;
	adding_to_window(game, 0);
}

void	move_left_enemy(t_game *game)
{
	if (!game->x_en || !game->y_en)
		return ;
	if (game->map[game->x_en][game->y_en - 1] == '1'
	|| game->map[game->x_en][game->y_en - 1] == 'C')
		game->memenemy = 1;
	if (game->map[game->x_en][game->y_en - 1] == '0')
	{
		game->map[game->x_en][game->y_en] = '0';
		game->map[game->x_en][game->y_en - 1] = 'N';
	}
	else if (game->map[game->x_en][game->y_en - 1] == 'P')
	{
		ft_printf("GAME OVER!\n");
		quit(game);
	}
}

void	move_right_enemy(t_game *game)
{
	if (game->map[game->x_en][game->y_en + 1] == '1'
	|| game->map[game->x_en][game->y_en + 1] == 'C')
		game->memenemy = 0;
	if (game->map[game->x_en][game->y_en + 1] == '0')
	{
		game->map[game->x_en][game->y_en] = '0';
		game->map[game->x_en][game->y_en + 1] = 'N';
	}
	else if (game->map[game->x_en][game->y_en + 1] == 'P')
	{
		ft_printf("GAME OVER!\n");
		quit(game);
	}
}
