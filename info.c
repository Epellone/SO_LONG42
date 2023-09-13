/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:25:38 by epellone          #+#    #+#             */
/*   Updated: 2023/06/26 16:57:18 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sizen(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int countmoves)
{
	int			len;
	char		*str;
	long int	ln;

	ln = countmoves;
	len = sizen(ln);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (ln == 0)
		str[0] = 48;
	str[len--] = 0;
	if (ln < 0)
	{
		str[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		str[len--] = ln % 10 + '0';
		ln = ln / 10;
	}
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	i = 0;
	while (str[i])
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	ft_putstring(t_game *game)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa(game->countmoves);
	str = ft_strjoin(ft_strdup("moves: "), tmp);
	mlx_string_put(game->mlxptr, game->winptr, 10, 10, 0xFFFFFF, str);
	free(str);
	free(tmp);
	str = 0;
	tmp = 0;
	tmp = ft_itoa(game->countcoin);
	str = ft_strjoin(ft_strdup("coins: "), tmp);
	mlx_string_put(game->mlxptr, game->winptr, (game->widthmap * 60)
		- ft_strlen(str) * 10, 10, 0xFFFFFF, str);
	free(str);
	free(tmp);
}
