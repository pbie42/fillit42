/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:17:43 by pbie              #+#    #+#             */
/*   Updated: 2016/01/25 17:25:40 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_hfix(char **bt, int y, int i)
{
	if (i - y == 3)
	{
		ft_strswap(&bt[y - 1], &bt[y], &bt[y + 1], &bt[y + 2]);
	}
	else if (i - y == 2)
	{
		ft_strswap(&bt[y - 2], &bt[y - 1], &bt[y], &bt[y + 1]);
		ft_strswap(&bt[y - 2], &bt[y - 1], &bt[y], &bt[y + 1]);
		return (bt);
	}
	else if (i - y == 1)
	{
		ft_strswap(&bt[y - 3], &bt[y - 2], &bt[y - 1], &bt[y]);
		ft_strswap(&bt[y - 3], &bt[y - 2], &bt[y - 1], &bt[y]);
		ft_strswap(&bt[y - 3], &bt[y - 2], &bt[y - 1], &bt[y]);
	}
	return (bt);
}

void			ft_vfix(char **bt, int y, int x, int i)
{
	if (x - 0 == 1)
	{
		while (y < i)
		{
			ft_charswap(&bt[y][x - 1], &bt[y][x], &bt[y][x + 1], &bt[y][x + 2]);
			y++;
		}
	}
	else if (x - 0 == 2)
	{
		while (y < i)
		{
			ft_vfix2(&bt[y][x - 2], &bt[y][x - 1], &bt[y][x], &bt[y][x + 1]);
			y++;
		}
	}
	else if (x - 0 == 3)
	{
		while (y < i)
		{
			ft_vfix3(&bt[y][x - 3], &bt[y][x - 2], &bt[y][x - 1], &bt[y][x]);
			y++;
		}
	}
}

char			**ft_buffit(char **buffer)
{
	int			y;
	int			x;
	int			i;
	char		**tbuff;

	y = 0;
	x = 0;
	i = 4;
	tbuff = buffer;
	ft_toptest(tbuff, x, y, i);
	ft_lefttest(tbuff, x, y, i);
	return (tbuff);
}

char			**ft_lefttest(char **bt, int x, int y, int i)
{
	int			k;

	while (bt[y] != NULL)
	{
		x = -1;
		while (bt[y][++x] != '\0')
		{
			k = y - 1;
			while (++k < i)
			{
				if (bt[k][x] == '#')
				{
					ft_vfix(bt, y, x, i);
					k = i;
					x = 3;
				}
			}
		}
		y += 4;
		i += 4;
	}
	return (bt);
}

char			**ft_toptest(char **bt, int x, int y, int i)
{
	int			k;

	while (bt[y] != NULL)
	{
		k = y;
		while (k < i)
		{
			x = 0;
			while (bt[k][x] != '\0' && bt[k] != NULL)
			{
				if (bt[k][x] == '#')
				{
					ft_hfix(bt, k, i);
					k = i - 1;
					x = 3;
				}
				x++;
			}
			k++;
		}
		y += 4;
		i += 4;
	}
	return (bt);
}
