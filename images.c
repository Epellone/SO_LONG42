/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:09:20 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 17:16:31 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_game *game)
{
	int	i;
	int	j;

	game->img[0] = mlx_xpm_file_to_image(game->mlxptr,
			"images/pacman1.xpm", &i, &j);
	game->img[1] = mlx_xpm_file_to_image(game->mlxptr,
			"images/pacman2.xpm", &i, &j);
	game->img[2] = mlx_xpm_file_to_image(game->mlxptr,
			"images/pacman3.xpm", &i, &j);
	game->img[3] = mlx_xpm_file_to_image(game->mlxptr,
			"images/pacman1left.xpm", &i, &j);
	game->img[4] = mlx_xpm_file_to_image(game->mlxptr,
			"images/pacman2left.xpm", &i, &j);
	game->img[5] = mlx_xpm_file_to_image(game->mlxptr,
			"images/pacman3left.xpm", &i, &j);
	game->enemy = mlx_xpm_file_to_image(game->mlxptr,
			"images/enemy.xpm", &i, &j);
	images2(game, i, j);
}

void	images2(t_game *game, int i, int j)
{
	game->wall_v = mlx_xpm_file_to_image(game->mlxptr,
			"images/wall_v.xpm", &i, &j);
	game->wall_v_r = mlx_xpm_file_to_image(game->mlxptr,
			"images/wall_v_r.xpm", &i, &j);
	game->wall_o = mlx_xpm_file_to_image(game->mlxptr,
			"images/wall_or.xpm", &i, &j);
	game->wall_o_d = mlx_xpm_file_to_image(game->mlxptr,
			"images/wall_o_d.xpm", &i, &j);
	game->floor = mlx_xpm_file_to_image(game->mlxptr,
			"images/floor.xpm", &i, &j);
	game->cor_u_l = mlx_xpm_file_to_image(game->mlxptr,
			"images/corner_u_l.xpm", &i, &j);
	game->cor_d_l = mlx_xpm_file_to_image(game->mlxptr,
			"images/corner_d_l.xpm", &i, &j);
	game->cor_u_r = mlx_xpm_file_to_image(game->mlxptr,
			"images/corner_u_r.xpm", &i, &j);
	game->cor_d_r = mlx_xpm_file_to_image(game->mlxptr,
			"images/corner_d_r.xpm", &i, &j);
	game->coll = mlx_xpm_file_to_image(game->mlxptr,
			"images/coll.xpm", &i, &j);
	game->ready = mlx_xpm_file_to_image(game->mlxptr,
			"images/ready.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxptr,
			"images/exit.xpm", &i, &j);
}

int	quit(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlxptr, game->wall_v);
	mlx_destroy_image(game->mlxptr, game->wall_v_r);
	mlx_destroy_image(game->mlxptr, game->wall_o_d);
	mlx_destroy_image(game->mlxptr, game->wall_o);
	mlx_destroy_image(game->mlxptr, game->cor_u_l);
	mlx_destroy_image(game->mlxptr, game->cor_d_l);
	mlx_destroy_image(game->mlxptr, game->cor_u_r);
	mlx_destroy_image(game->mlxptr, game->cor_d_r);
	mlx_destroy_image(game->mlxptr, game->floor);
	mlx_destroy_image(game->mlxptr, game->enemy);
	mlx_destroy_image(game->mlxptr, game->coll);
	mlx_destroy_image(game->mlxptr, game->ready);
	mlx_destroy_image(game->mlxptr, game->exit);
	mlx_destroy_window(game->mlxptr, game->winptr);
	while (i < game->heightmap)
		free(game->map[i++]);
	free(game->map);
	exit (0);
}
