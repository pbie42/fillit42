/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrotableplacer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:35:32 by pbie              #+#    #+#             */
/*   Updated: 2016/01/19 14:40:35 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**tetrotableplacertester(t_piece *teststruct, char **testtab)
{
	int		x;
	int		y;

	y = 0;
	while (testtab[y] != NULL)
	{
		x = 0;
		while (testtab[y][x] != '\0')
		{
			if (teststruct[0].first.x == x && teststruct[0].first.y == y)
				testtab[y][x] = teststruct[0].name;
			if (teststruct[0].second.x == x && teststruct[0].second.y == y)
				testtab[y][x] = teststruct[0].name;
			if (teststruct[0].third.x == x && teststruct[0].third.y == y)
				testtab[y][x] = teststruct[0].name;
			if (teststruct[0].fourth.x == x && teststruct[0].fourth.y == y)
				testtab[y][x] = teststruct[0].name;
			x++;
		}
		y++;
	}
	return (testtab);
}
