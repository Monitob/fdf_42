# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/20 14:26:24 by bjacob            #+#    #+#              #
#    Updated: 2013/12/21 13:39:06 by bjacob           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = event_fdf.c ft_draw_line.c curent_fdf.c main.c

OBJ = $(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror

MLIBX = -L/usr/X11/lib -lmlx -lXext -lX11

LIB = libft/libft.a

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(MLIBX) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) -c -I./libft/includes/ $< -o $@

clean:
	make clean -C libft/
	/bin/rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME)

re: fclean all
