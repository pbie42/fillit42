/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thealgo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:21:23 by pbie              #+#    #+#             */
/*   Updated: 2016/01/22 15:32:16 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char			**ft_boardbuilder(int boardsize)
{
	int			i;
	int			j;
	char		**brandnew;

	i = 0;
	brandnew = (char **)malloc(sizeof(char *) * boardsize + 1);
	brandnew[boardsize] = NULL;
	while (i < boardsize)
	{
		j = 0;
		brandnew[i] = (char *)malloc(sizeof(char) * boardsize + 1);
		brandnew[i][boardsize] = '\0';
		while (j < boardsize)
		{
			brandnew[i][j] = '.';
			j++;
		}
		i++;
	}
	return (brandnew);
}

int				ft_vp(t_piece piece, char **resize)
{
	if (resize[piece.first.y][piece.first.x] == '.'
			&& resize[piece.second.y][piece.second.x] == '.'
			&& resize[piece.third.y][piece.third.x] == '.'
			&& resize[piece.fourth.y][piece.fourth.x] == '.')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char			**ft_tettotab(t_piece piece, char **resize)
{
	resize[piece.first.y][piece.first.x] = piece.name;
	resize[piece.second.y][piece.second.x] = piece.name;
	resize[piece.third.y][piece.third.x] = piece.name;
	resize[piece.fourth.y][piece.fourth.x] = piece.name;
	return (resize);
}

t_piece			ft_xstructtoboard(t_piece phold, char **resize)
{
	if (phold.redo == 1)
	{
		phold.first.x++;
		phold.second.x++;
		phold.third.x++;
		phold.fourth.x++;
		phold.redo = 0;
	}
	while (resize[phold.first.y][phold.first.x] != '\0'
			&& resize[phold.second.y][phold.second.x] != '\0'
			&& resize[phold.third.y][phold.third.x] != '\0'
			&& resize[phold.fourth.y][phold.fourth.x] != '\0')
	{
		if (ft_vp(phold, resize) == 1)
		{
			phold.cbp = 1;
			return (phold);
		}
		phold.first.x++;
		phold.second.x++;
		phold.third.x++;
		phold.fourth.x++;
	}
	phold.redo = 0;
	return (phold);
}

t_piece			ft_ystructtoboard(t_piece piece, char **resize, t_piece stab)
{
	int			j;
	t_piece		phold;

	j = ft_tablen(resize);
	phold = ft_onestructcopy(piece, phold);
	phold.og = 0;
	while (phold.first.y < j && phold.second.y < j && phold.third.y < j
			&& phold.fourth.y < j)
	{
		if (phold.redo == 0)
			phold = ft_resetx(phold, stab);
		phold = ft_xstructtoboard(phold, resize);
		if (phold.cbp == 1)
		{
			piece = phold;
			return (piece);
		}
		phold.first.y++;
		phold.second.y++;
		phold.third.y++;
		phold.fourth.y++;
	}
	return (piece);
}
