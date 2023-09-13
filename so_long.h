/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:18:28 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 17:13:49 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"

typedef struct s_game
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		x_pac;
	int		y_pac;
	int		x_en;
	int		y_en;
	int		frame;
	int		move;
	int		movel;
	int		memmove;
	int		countmoves;
	int		memenemy;
	int		ghost;
	int		start;
	int		coin;
	int		check_n;
	int		check_p;
	int		countcoin;

	long	countenemy;

	char	**map;

	void	*img[6];
	void	*wall_v;
	void	*wall_v_r;
	void	*wall_o_d;
	void	*wall_o;
	void	*cor_u_l;
	void	*cor_d_l;
	void	*cor_u_r;
	void	*cor_d_r;
	void	*mlxptr;
	void	*winptr;
	void	*floor;
	void	*enemy;
	void	*coll;
	void	*ready;
	void	*exit;
}	t_game;

int		map_reading(t_game *game, char **argv);
int		error(int i);
int		quit(t_game *game);
int		key_hook(int keycode, t_game *game);
int		check_walls(t_game game);
int		animations(t_game *game);
int		check_rectangle(t_game game);
int		check_different(t_game game);
int		check_exit_and_player_bool(t_game *game);
void	images(t_game *game);
void	adding_to_window(t_game *game, int t);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
void	player_animation(t_game *game);
void	player_animation_left(t_game *game);
void	move_left_enemy(t_game *game);
void	move_right_enemy(t_game *game);
void	enemy_animations(t_game *game);
void	move_down_enemy(t_game *game);
void	move_up_enemy(t_game *game);
void	check_exit_and_player(t_game *game);
void	ft_putstring(t_game *game);
void	place_wall2(t_game *game, int row, int col);
void	images2(t_game *game, int i, int j);
void	ft_draw(t_game *game, int i, int j, int t);
char	*ft_strdup(const char *str);
char	*ft_itoa(int countmoves);
#endif