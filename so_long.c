/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:06:51 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 18:20:41 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_game *game)
{
	game->fd = 0;
	game->heightmap = 0;
	game->widthmap = 0;
	game->x_pac = 0;
	game->y_pac = 0;
	game->x_en = 0;
	game->y_en = 0;
	game->frame = 0;
	game->move = 0;
	game->movel = 0;
	game->memmove = 0;
	game->countmoves = 0;
	game->memenemy = 0;
	game->ghost = 0;
	game->start = 0;
	game->coin = 0;
	game->check_n = 0;
	game->check_p = 0;
	game->countenemy = 0;
	game->countcoin = 0;
	game->map = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		check;

	if (argc != 2)
		return (error(6));
	check = ft_strlen(argv[1]);
	if (check < 5 || argv[1][check - 1] != 'r' || argv[1][check - 2] != 'e'
		|| argv[1][check - 3] != 'b' || argv[1][check - 4] != '.')
		return (error(5));
	initialize(&game);
	if (!map_reading(&game, argv))
		return (1);
	game.mlxptr = mlx_init();
	images(&game);
	game.winptr = mlx_new_window(game.mlxptr, (game.widthmap * 60),
			(game.heightmap * 60), "solong");
	adding_to_window(&game, 1);
	mlx_key_hook(game.winptr, key_hook, &game);
	mlx_hook(game.winptr, 17, 0, quit, &game);
	mlx_loop_hook(game.mlxptr, animations, &game);
	mlx_loop(game.mlxptr);
}
