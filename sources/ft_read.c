/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:18:40 by pkerckho          #+#    #+#             */
/*   Updated: 2016/01/25 17:37:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_spacecheck(char *dest)
{
	int			i;
	int			cntr;

	i = 0;
	cntr = 0;
	while (dest[i] != '\0')
	{
		if (dest[i] == '\n')
		{
			cntr++;
		}
		if (cntr == 4)
		{
			if (dest[i + 1] == '\n' || dest[i + 1] == '\0')
				cntr = -1;
			else
				ft_exit("error");
		}
		i++;
	}
}

char			**ft_filereader(char *filename, int *c)
{
	int			fd;
	int			i;
	char		buffer[23];
	char		*dest;

	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_exit("error");
	dest = "";
	c += 1;
	while ((i = read(fd, buffer, 21)) != 0)
	{
		if (buffer[0] != '\n' && buffer[0] != '.' && buffer[0] != '#')
			ft_exit("error");
		buffer[i] = '\0';
		dest = ft_strjoin(dest, buffer);
	}
	if ((close(fd)) == -1)
		return (NULL);
	if (*c > 26 || ft_strlen(buffer) < 20 || ft_strlen(buffer) == 21)
		ft_exit("error");
	ft_spacecheck(dest);
	return (ft_strsplit(dest, '\n'));
}

char			**ft_board(char **bt)
{
	char		**tab;
	int			i;
	int			j;
	int			k;

	i = 0;
	tab = bt;
	while (tab[i] != NULL)
	{
		j = 0;
		k = i / 4;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
				tab[i][j] = tab[i][j] + 30 + k;
			j++;
		}
		i++;
	}
	return (tab);
}
