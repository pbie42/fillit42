/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goodpieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:08:48 by pbie              #+#    #+#             */
/*   Updated: 2016/01/26 18:06:59 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*ft_gp1(int bs)
{
	char		*s1;
	char		*s2;
	char		*s3;
	char		*s4;
	char		*full;

	bs++;
	s1 = "##..\n##..\n....\n....\n\n#...\n#...\n#...\n#...\n\n";
	s2 = "####\n....\n....\n....\n\n###.\n#...\n....\n....\n\n";
	s3 = "#...\n#...\n##..\n....\n\n..#.\n###.\n....\n....\n\n";
	s4 = "##..\n.#..\n.#..\n....\n\n##..\n#...\n#...\n....\n\n";
	full = ft_strjoin(ft_strjoin(s1, s2), ft_strjoin(s3, s4));
	return (full);
}

char			*ft_gp2(int bs)
{
	char		*s1;
	char		*s2;
	char		*s3;
	char		*s4;
	char		*full;

	bs++;
	s1 = "#...\n###.\n....\n....\n\n.#..\n.#..\n##..\n....\n\n";
	s2 = "###.\n..#.\n....\n....\n\n#...\n##..\n.#..\n....\n\n";
	s3 = ".##.\n##..\n....\n....\n\n.#..\n##..\n#...\n....\n\n";
	s4 = "##..\n.##.\n....\n....\n\n###.\n.#..\n....\n....\n\n";
	full = ft_strjoin(ft_strjoin(s1, s2), ft_strjoin(s3, s4));
	return (full);
}

char			*ft_gp3(int bs)
{
	char		*s1;
	char		*s2;
	char		*full;

	bs++;
	s1 = "#...\n##..\n#...\n....\n\n.#..\n###.\n....\n....\n\n";
	s2 = ".#..\n##..\n.#..\n....\n\n";
	full = ft_strjoin(s1, s2);
	return (full);
}

char			**ft_goodpieces(int size)
{
	char		*s1;
	char		*s2;
	char		*s3;
	char		*s4;
	char		**vt;

	size++;
	s1 = ft_gp1(5);
	s2 = ft_gp2(5);
	s3 = ft_gp3(5);
	s4 = ft_strjoin(ft_strjoin(s1, s2), s3);
	vt = ft_strsplit(s4, '\n');
	return (vt);
}
