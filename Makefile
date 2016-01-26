# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkerckho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 11:55:43 by pkerckho          #+#    #+#              #
#    Updated: 2016/01/26 18:12:40 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = fillit.a

INC_DIR = includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

SOURCES = ft_putstr.c\
		  ft_putstr_fd.c\
		  ft_putnbr.c\
		  ft_strlen.c\
		  ft_strcmp.c\
		  ft_strequ.c\
		  ft_strjoin.c\
		  ft_strncpy.c\
		  ft_strndup.c\
		  ft_strsplit.c\
		  ft_putstrtab.c\
		  ft_putchar_fd.c\
		  ft_putendl.c\
		  ft_putendl_fd.c\
		  ft_tablen.c\
		  ft_memalloc.c\
		  ft_bzero.c\
		  ft_putchar.c\
		  ft_memalloc.c\
		  ft_memset.c\
		  ft_bzero.c\
		  ft_buffit.c\
		  ft_buffit2.c\
		  ft_comparer.c\
		  ft_tetrotableplacer.c\
		  ft_thealgo.c\
		  ft_thealgo2.c\
		  ft_thenewalgo.c\
		  ft_validator.c\
		  ft_read.c\
		  ft_structer.c\
		  ft_exit.c\
		  ft_goodpieces.c\


SRC = $(addprefix sources/,$(SOURCES))

OBJ = $(SRC:.c=.o)

all : $(NAME) $(LIB)

$(NAME) : $(LIB)
	@$(CC) -o $(NAME) main.c $(LIB) $(CFLAGS)
	@echo "$(NAME) created"

$(LIB) : $(OBJ)
	@ar -r $(LIB) $(OBJ)
	@ranlib $(LIB)
	@echo "$(NAME) indexed"

clean :
	@rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean : clean
	@rm -rf $(NAME) $(LIB)
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
