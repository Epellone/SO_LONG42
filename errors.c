/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:45:57 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 18:16:06 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(int i)
{
	if (i == 1)
		ft_printf("Error\nCheck walls!\n");
	if (i == 2)
		ft_printf("Error\nCheck if the map is a rectangle.\n");
	if (i == 3)
		ft_printf("Error\nCheck exit, coin and starting position.\n");
	if (i == 4)
		ft_printf("Error\nCheck the letters.\n");
	if (i == 5)
		ft_printf("Error\nInvalid file.\n");
	if (i == 6)
		ft_printf("Error\nWrong arguments.\n");
	return (0);
}
