/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 21:41:55 by pbie              #+#    #+#             */
/*   Updated: 2016/01/26 18:12:06 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "libft.h"

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_piece
{
	char		name;
	int			end;
	int			cbp;
	int			redo;
	int			og;
	t_xy		first;
	t_xy		second;
	t_xy		third;
	t_xy		fourth;
}				t_piece;

void			ft_vchars(char **tab);
void			ft_vpointhash(char **tab);
char			**ft_buffit(char **buffer);
void			ft_vfix(char **bt, int y, int x, int i);
void			ft_vfix2(char *x1, char *x2, char *x3, char *x4);
void			ft_vfix3(char *x1, char *x2, char *x3, char *x4);
char			**ft_hfix(char **bt, int y, int i);
void			ft_charswap(char *x1, char *x2, char *x3, char *x4);
void			ft_strswap(char **s1, char **s2, char **s3, char **s4);
void			ft_putstrtab(char **tab);
char			**ft_lefttest(char **bt, int x, int y, int i);
char			**ft_toptest(char **bt, int x, int y, int i);
int				ft_shitcmp(char **bt, char **vt);
int				ft_privchecker(char **bt, char **vt, int y);
char			**ft_board(char **bt);
int				ft_tablen(char **tab);
void			ft_letfill(char c, t_piece *st);
void			ft_pfill(int y, int x, t_piece *st, int k);
t_piece			*ft_structer(char **bt, int y, int x);
int				ft_padjust(int y);
char			**ft_filereader(char *filename, int *c);
char			**tetrotableplacertester(t_piece *teststruct, char **testtab);
char			**ft_boardbuilder(int boardsize);
char			**ft_newboardfiller(char **board, char **newboard);
char			**ft_thenewalgo(t_piece *structtab, int sz, int boardsize);
int				ft_structsizer(char **bt);
char			**ft_tettotab(t_piece piece, char **resize);
void			ft_spacecheck(char *dest);
t_piece			ft_resetx(t_piece phold, t_piece stab);
t_piece			ft_ystructtoboard(t_piece piece, char **resize, t_piece stab);
t_piece			ft_xstructtoboard(t_piece piece, char **resize);
t_piece			ft_onestructcopy(t_piece piece, t_piece piececopy);
t_piece			ft_structxcopy(t_piece piece, t_piece piececopy);
t_piece			*ft_structtcpy(t_piece *structtab, t_piece *structcopy, int sz);
char			*ft_gp1(int bs);
char			*ft_gp2(int bs);
char			*ft_gp3(int bs);
char			**ft_goodpieces(int size);

#endif
