/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 01:06:56 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 17:26:24 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animations(t_game *game)
{
	if (game->start == 1)
	{
		game->countenemy++;
		enemy_animations(game);
		player_animation(game);
		player_animation_left(game);
	}
	return (0);
}

void	player_animation(t_game *game)
{
	if (game->move == 1 && game->memmove == 1)
	{	
		if (game->frame > 3)
		{
			game->frame = 0;
			game->move = 0;
		}
		mlx_put_image_to_window(game->mlxptr, game->winptr,
			game->img[0 + game->frame - game->frame / 2],
			game->y_pac * 60, game->x_pac * 60);
		game->frame++;
		game->countenemy += 1500;
		usleep(18000);
	}
}

void	player_animation_left(t_game *game)
{
	if (game->movel == 1)
	{
		if (game->frame > 3)
		{
			game->frame = 0;
			game->movel = 0;
		}
		mlx_put_image_to_window(game->mlxptr, game->winptr,
			game->img[3 + game->frame - game->frame / 2],
			game->y_pac * 60, game->x_pac * 60);
		game->frame++;
		game->countenemy += 1500;
		usleep(18000);
	}
}

void	place_wall2(t_game *game, int row, int col)
{
	if (col < game->widthmap)
	{
		if (game->map[row][col + 1] == '1' )
			mlx_put_image_to_window(game->mlxptr, game->winptr,
				game->cor_u_l, col * 60, row * 60);
		else if (col > 0 && game->map[row][col - 1] == '1')
			mlx_put_image_to_window(game->mlxptr, game->winptr,
				game->cor_u_r, col * 60, row * 60);
		else if (col > 0 && (game->map[row][col - 1] == '0'
			|| game->map[row][col - 1] == 'P' || game->map[row][col - 1] == 'C'
				|| game->map[row][col - 1] == 'E'
				|| game->map[row][col - 1] == 'N'))
			mlx_put_image_to_window(game->mlxptr, game->winptr,
				game->wall_v_r, col * 60, row * 60);
		else
			mlx_put_image_to_window(game->mlxptr, game->winptr,
				game->wall_v, col * 60, row * 60);
	}
}
