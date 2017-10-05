#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 17:37:31 by gvilmont          #+#    #+#              #
#    Updated: 2016/01/22 21:43:51 by gvilmont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_intab.c ft_read_txt.c ft_placetet.c ft_checktet.c \
	  main.c ft_initmap.c ft_putintab.c ft_carlen.c \
	  ft_showtab.c ft_checkpos.c ft_resolve.c ft_tools.c

OBJ = ft_intab.o ft_read_txt.o ft_placetet.o ft_checktet.o \
	  main.o ft_initmap.o ft_putintab.o ft_carlen.o \
	  ft_showtab.o ft_checkpos.o ft_resolve.o ft_tools.o

FLAG = -Wall -Wextra -Werror

LIBS = libft.a

all: $(NAME)

$(NAME):$(OBJ)
	gcc $(FLAG) -o $(NAME) $(SRC) $(LIBS) -I.

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
