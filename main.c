/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:45:36 by pbie              #+#    #+#             */
/*   Updated: 2016/01/26 18:12:10 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int			main(int ac, char **argv)
{
	char		**bufftable;
	char		**goodtable;
	char		**thefinal;
	int			sz;
	int			c;

	c = 0;
	if (ac != 2)
	{
		ft_exit("error");
		return (0);
	}
	bufftable = ft_buffit(ft_filereader(argv[1], &c));
	if (ft_tablen(bufftable) > 104)
		ft_exit("error");
	c = 0;
	goodtable = ft_goodpieces(5);
	if (ft_shitcmp(bufftable, goodtable) == 1)
		ft_board(bufftable);
	else
		ft_exit("error");
	sz = ft_structsizer(bufftable);
	thefinal = ft_thenewalgo(ft_structer(bufftable, 0, 0), sz, 4);
	ft_putstrtab(thefinal);
	return (0);
}
