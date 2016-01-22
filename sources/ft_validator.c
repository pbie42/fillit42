/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:51:35 by pbie              #+#    #+#             */
/*   Updated: 2016/01/19 14:41:04 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_vchars(char **tab)
{
	int		x;
	int		y;

	x = 0;
	while (tab[x] != NULL)
	{
		y = 0;
		while (tab[x][y] != '\0')
		{
			if (tab[x][y] != '.' && tab[x][y] != '#')
				ft_exit("error");
			y++;
		}
		if (y != 4)
			ft_exit("error");
		x++;
	}
}

void		ft_vpointhash(char **tab)
{
	int		i;
	int		x;
	int		y;
	int		cntr;

	cntr = 0;
	x = -1;
	y = -1;
	while (tab[++x] != NULL)
	{
		i = -1;
		while (++i < 16)
		{
			if (tab[x][++y] == '#')
				cntr++;
			if ((i + 1 % 4) == 0)
			{
				x++;
				y = 0;
			}
		}
		if ((cntr % 4) != 0)
			ft_exit("error");
	}
}
