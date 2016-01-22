/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:54:37 by pbie              #+#    #+#             */
/*   Updated: 2016/01/21 16:21:10 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_padjust(int y)
{
	if (y % 4 == 0)
		return (0);
	else if (y % 4 == 1)
		return (1);
	else if (y % 4 == 2)
		return (2);
	else if (y % 4 == 3)
		return (3);
	return (y);
}

void			ft_letfill(char c, t_piece *st)
{
	st->name = c;
	st->end = 0;
	st->cbp = 0;
	st->redo = 0;
	st->og = 0;
}

void			ft_pfill(int y, int x, t_piece *st, int k)
{
	y = ft_padjust(y);
	if (k == 0)
	{
		st->first.x = x;
		st->first.y = y;
	}
	else if (k == 1)
	{
		st->second.x = x;
		st->second.y = y;
	}
	else if (k == 2)
	{
		st->third.x = x;
		st->third.y = y;
	}
	else if (k == 3)
	{
		st->fourth.x = x;
		st->fourth.y = y;
	}
}

static void		ft_structincr(int *h, int *y, int *i)
{
	++*h;
	*y += 4;
	*i += 4;
}

t_piece			*ft_structer(char **bt, int y, int x)
{
	int			n[2];
	int			k[2];
	t_piece		*st;

	st = (t_piece *)malloc(sizeof(t_piece) * (ft_tablen(bt) / 4));
	n[1] = y + 4;
	k[1] = 0;
	while (bt[y] != NULL)
	{
		n[0] = y - 1;
		k[0] = 0;
		while (++n[0] < n[1] && (x = -1))
		{
			while (bt[n[0]][++x] != '\0')
			{
				if (bt[n[0]][x] != '.')
				{
					ft_letfill(bt[n[0]][x], &st[k[1]]);
					ft_pfill(n[0], x, &st[k[1]], k[0]++);
				}
			}
		}
		ft_structincr(&k[1], &y, &n[1]);
	}
	return (st);
}
