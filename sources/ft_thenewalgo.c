/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thenewalgo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:08:44 by pbie              #+#    #+#             */
/*   Updated: 2016/01/22 16:27:30 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece			ft_firstif(t_piece structtab, t_piece shold)
{
	shold = ft_structxcopy(structtab, shold);
	shold.redo = 1;
	return (shold);
}

t_piece			ft_thirdif(t_piece structtab, t_piece shold)
{
	shold = ft_onestructcopy(structtab, shold);
	shold.end = 1;
	return (shold);
}

char			**ft_sixthif(char **board, t_piece shold)
{
	board[shold.first.y][shold.first.x] = '.';
	board[shold.second.y][shold.second.x] = '.';
	board[shold.third.y][shold.third.x] = '.';
	board[shold.fourth.y][shold.fourth.x] = '.';
	return (board);
}

void			ft_thenewalgo2(t_piece *structtab,
				t_piece *shold, char **board, int *y)
{
	if (shold[*y].og == 1 && shold[*y].redo == 1)
		shold[*y] = ft_firstif(structtab[*y], shold[*y]);
	if (shold[*y].cbp == 0)
		shold[*y] = ft_ystructtoboard(shold[*y], board, structtab[*y]);
	if (shold[*y].cbp == 0)
		shold[*y] = ft_thirdif(structtab[*y], shold[*y]);
	if (shold[*y].cbp == 1)
	{
		ft_tettotab(shold[*y], board);
		shold[*y].end = 0;
	}
	if (shold[*y].end == 1)
	{
		if (*y != 0)
		{
			board = ft_sixthif(board, shold[*y - 1]);
			shold[*y - 1].redo = 1;
			shold[*y - 1].cbp = 0;
			*y -= 2;
		}
	}
}

char			**ft_thenewalgo(t_piece *structtab, int sz, int boardsize)
{
	char		**board;
	t_piece		*shold;
	int			y;
	int			k;

	k = 2;
	shold = NULL;
	boardsize = 0;
	shold = ft_structtcpy(structtab, shold, sz);
	board = ft_boardbuilder(k);
	y = 0;
	while (y < sz)
	{
		ft_thenewalgo2(structtab, shold, board, &y);
		if (shold[0].cbp == 0 && shold[0].end == 1)
		{
			k++;
			board = ft_boardbuilder(k);
			shold = ft_structtcpy(structtab, shold, sz);
			y = -1;
		}
		y++;
	}
	return (board);
}
