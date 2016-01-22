/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comparer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:14:09 by pkerckho          #+#    #+#             */
/*   Updated: 2016/01/21 16:32:27 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_privchecker(char **bt, char **vt, int y)
{
	int		o;
	int		g;
	int		z;
	int		w;
	int		cntr;

	o = 0;
	g = 4;
	while (vt[o] != NULL)
	{
		z = o - 1;
		w = y;
		cntr = 0;
		while (++z < g && vt[z] != NULL)
		{
			if (ft_strequ(bt[w], vt[z]) == 1)
				cntr++;
			w++;
		}
		if (cntr == 4)
			return (1);
		o += 4;
		g += 4;
	}
	return (0);
}

int			ft_shitcmp(char **bt, char **vt)
{
	int		y;
	int		i;

	y = 0;
	i = 4;
	while (bt[y] != NULL)
	{
		if (ft_privchecker(bt, vt, y) == 0)
			return (0);
		y += 4;
		i += 4;
	}
	return (1);
}

int			ft_structsizer(char **bt)
{
	int		y;

	y = ft_tablen(bt) / 4;
	return (y);
}
