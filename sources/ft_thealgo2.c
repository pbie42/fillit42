/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thealgo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:31:38 by pkerckho          #+#    #+#             */
/*   Updated: 2016/01/22 16:28:25 by pkerckho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece			ft_onestructcopy(t_piece piece, t_piece piececopy)
{
	piececopy.name = piece.name;
	piececopy.end = piece.end;
	piececopy.cbp = piece.cbp;
	piececopy.redo = piece.redo;
	piececopy.first.y = piece.first.y;
	piececopy.first.x = piece.first.x;
	piececopy.second.y = piece.second.y;
	piececopy.second.x = piece.second.x;
	piececopy.third.y = piece.third.y;
	piececopy.third.x = piece.third.x;
	piececopy.fourth.y = piece.fourth.y;
	piececopy.fourth.x = piece.fourth.x;
	return (piececopy);
}

t_piece			ft_structxcopy(t_piece piece, t_piece piececopy)
{
	if (piececopy.first.x == piece.first.x + 1)
	{
		piececopy.first.y = piececopy.first.y + 1;
		piececopy.first.x = piece.first.x - 1;
		piececopy.second.y = piececopy.second.y + 1;
		piececopy.second.x = piece.second.x - 1;
		piececopy.third.y = piececopy.third.y + 1;
		piececopy.third.x = piece.third.x - 1;
		piececopy.fourth.y = piececopy.fourth.y + 1;
		piececopy.fourth.x = piece.fourth.x - 1;
	}
	return (piececopy);
}

t_piece			*ft_structtcpy(t_piece *structtab, t_piece *structcopy, int sz)
{
	int			y;

	y = 0;
	structcopy = (t_piece *)malloc(sizeof(t_piece) * sz + 1);
	while (y < sz)
	{
		structcopy[y] = structtab[y];
		y++;
	}
	return (structcopy);
}

t_piece			ft_resetx(t_piece phold, t_piece stab)
{
	phold.first.x = stab.first.x;
	phold.second.x = stab.second.x;
	phold.third.x = stab.third.x;
	phold.fourth.x = stab.fourth.x;
	return (phold);
}
