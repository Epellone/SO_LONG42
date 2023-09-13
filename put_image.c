/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:29:21 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 17:35:06 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_wall(t_game *game, int row, int col)
{
	if (game->map[row][col] == '1')
	{
		if (row < game->heightmap - 1 && game->map[row + 1][col] == '1')
			place_wall2(game, row, col);
		else if (row == 0 && col < game->widthmap - 1
			&& game->map[row][col] == '1')
			mlx_put_image_to_window(game->mlxptr, game->winptr,
				game->wall_o, col * 60, row * 60);
		else if (row == game->heightmap - 1
			&& col < game->widthmap - 1 && game->map[row][col] == '1')
			mlx_put_image_to_window(game->mlxptr, game->winptr,
				game->wall_o_d, col * 60, row * 60);
		else
			mlx_put_image_to_window(game->mlxptr, game->winptr,
				game->wall_v, col * 60, row * 60);
		mlx_put_image_to_window(game->mlxptr, game->winptr, game->cor_d_r,
			(game->widthmap - 1) * 60, (game->heightmap - 1) * 60);
		mlx_put_image_to_window(game->mlxptr, game->winptr, game->cor_d_l, 0,
			(game->heightmap - 1) * 60);
	}
}

void	place_pacman(t_game *game, int height, int width)
{
	if (game->move == 1 && game->memmove == 1)
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->img[0], width * 60, height * 60);
	else if (game->movel == 1 && game->memmove == 2)
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->img[3], width * 60, height * 60);
	else
	{
		if (game->memmove == 1)
			mlx_put_image_to_window(game->mlxptr,
				game->winptr, game->img[0], width * 60, height * 60);
	}
	game->x_pac = height;
	game->y_pac = width;
}

void	place_enemy(t_game *game, int height, int width)
{
	game->x_en = height;
	game->y_en = width;
	mlx_put_image_to_window(game->mlxptr,
		game->winptr, game->enemy, width * 60, height * 60);
}	

void	adding_to_window(t_game *game, int t)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (game->map[i][j])
		{	
			ft_draw(game, i, j, t);
			j++;
		}
		i++;
		if (game->start == 0)
			mlx_put_image_to_window(game->mlxptr,
				game->winptr, game->ready,
				((game->widthmap * 60) / 2) - 300,
				((game->heightmap * 60) / 2) - 150);
	}
	ft_putstring(game);
}

void	ft_draw(t_game *game, int i, int j, int t)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->floor, j * 60, i * 60);
	else if (game->map[i][j] == '1')
		place_wall(game, i, j);
	else if (t && game->map[i][j] == 'P')
		place_pacman(game, i, j);
	else if (game->map[i][j] == 'N')
		place_enemy(game, i, j);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->coll, j * 60, i * 60);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->exit, j * 60, i * 60);
}
