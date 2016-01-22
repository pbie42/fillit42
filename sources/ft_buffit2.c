/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffit2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:56:06 by pbie              #+#    #+#             */
/*   Updated: 2016/01/19 14:37:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_strswap(char **s1, char **s2, char **s3, char **s4)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = *s1;
	*s1 = *s2;
	*s2 = *s3;
	*s3 = *s4;
	*s4 = tmp;
}

void			ft_charswap(char *x1, char *x2, char *x3, char *x4)
{
	char		tmp;

	tmp = *x1;
	*x1 = *x2;
	*x2 = *x3;
	*x3 = *x4;
	*x4 = tmp;
}

void			ft_vfix2(char *x1, char *x2, char *x3, char *x4)
{
	ft_charswap(x1, x2, x3, x4);
	ft_charswap(x1, x2, x3, x4);
}

void			ft_vfix3(char *x1, char *x2, char *x3, char *x4)
{
	ft_charswap(x1, x2, x3, x4);
	ft_charswap(x1, x2, x3, x4);
	ft_charswap(x1, x2, x3, x4);
}
