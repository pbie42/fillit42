/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:09:56 by pkerckho          #+#    #+#             */
/*   Updated: 2015/12/16 16:42:55 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstrtab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putendl(tab[i]);
		i++;
	}
}
