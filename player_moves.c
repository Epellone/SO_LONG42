/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:45:26 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 17:24:55 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (game->start == 0)
	{
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->img[0], game->y_pac * 60, game->x_pac * 60);
		if (keycode == 65293)
			game->start = 1;
		adding_to_window(game, 1);
	}
	else if (game->start == 1)
	{
		if (keycode == 65307)
			quit(game);
		if (keycode == 119 || keycode == 65362)
			move_up(game);
		if (keycode == 115 || keycode == 65364)
			move_down(game);
		if (keycode == 97 || keycode == 65361)
			move_left(game);
		if (keycode == 100 || keycode == 65363)
			move_right(game);
		return (1);
	}
	return (0);
}

void	move_right(t_game *game)
{
	game->move = 1;
	game->memmove = 1;
	if (game->map[game->x_pac][game->y_pac + 1] == '1')
		return ;
	else if (game->map[game->x_pac][game->y_pac + 1] == '0'
			|| game->map[game->x_pac][game->y_pac + 1] == 'C')
	{
		game->countcoin += (game->map[game->x_pac][game->y_pac + 1] == 'C');
		game->map[game->x_pac][game->y_pac] = '0';
		game->map[game->x_pac][game->y_pac + 1] = 'P';
	}
	else if (game->map[game->x_pac][game->y_pac + 1] == 'N')
		quit(game + ft_printf("GAME OVER!\n") * 0);
	else if (game->map[game->x_pac][game->y_pac + 1] == 'E'
			&& game->countcoin == game->coin)
		quit(game + ft_printf("WIN!\n") * 0);
	game->countmoves++;
	adding_to_window(game, 1);
}

void	move_left(t_game *game)
{
	game->movel = 1;
	game->memmove = 2;
	if (game->map[game->x_pac][game->y_pac - 1] == '1')
		return ;
	else if (game->map[game->x_pac][game->y_pac - 1] == '0'
			|| game->map[game->x_pac][game->y_pac - 1] == 'C')
	{
		game->countcoin += (game->map[game->x_pac][game->y_pac - 1] == 'C');
		game->map[game->x_pac][game->y_pac] = '0';
		game->map[game->x_pac][game->y_pac - 1] = 'P';
	}
	else if (game->map[game->x_pac][game->y_pac - 1] == 'N')
		quit(game + ft_printf("GAME OVER!\n") * 0);
	else if (game->map[game->x_pac][game->y_pac - 1] == 'E'
			&& game->countcoin == game->coin)
		quit(game + ft_printf("WIN!\n") * 0);
	game->countmoves++;
	adding_to_window(game, 1);
}

void	move_down(t_game *game)
{
	if (game->memmove == 1 || game->memmove == 0)
	{
		game->memmove = 1;
		game->move = 1;
	}
	else if (game->memmove == 2)
		game->movel = 1;
	if (game->map[game->x_pac + 1][game->y_pac] == '1')
		return ;
	if (game->map[game->x_pac + 1][game->y_pac] == '0'
		|| game->map[game->x_pac + 1][game->y_pac] == 'C')
	{
		game->countcoin += (game->map[game->x_pac + 1][game->y_pac] == 'C');
		game->map[game->x_pac][game->y_pac] = '0';
		game->map[game->x_pac + 1][game->y_pac] = 'P';
	}
	else if (game->map[game->x_pac + 1][game->y_pac] == 'N')
		quit(game + ft_printf("GAME OVER!\n") * 0);
	else if (game->map[game->x_pac + 1][game->y_pac] == 'E'
		&& game->countcoin == game->coin)
		quit(game + ft_printf("WIN!\n") * 0);
	game->countmoves++;
	adding_to_window(game, 1);
}

void	move_up(t_game *game)
{
	if (game->memmove == 2)
		game->movel = 1;
	else
		game->move = 1;
	if (game->map[game->x_pac - 1][game->y_pac] == '1')
		return ;
	if (game->map[game->x_pac - 1][game->y_pac] == '0'
		|| game->map[game->x_pac - 1][game->y_pac] == 'C')
	{
		game->countcoin += (game->map[game->x_pac - 1][game->y_pac] == 'C');
		game->map[game->x_pac][game->y_pac] = '0';
		game->map[game->x_pac - 1][game->y_pac] = 'P';
	}
	else if (game->map[game->x_pac - 1][game->y_pac] == 'N')
		quit(game + ft_printf("GAME OVER!\n") * 0);
	else if (game->map[game->x_pac][game->y_pac - 1] == 'E'
		&& game->countcoin == game->coin)
		quit(game + ft_printf("WIN!\n") * 0);
	game->countmoves++;
	adding_to_window(game, 1);
}
