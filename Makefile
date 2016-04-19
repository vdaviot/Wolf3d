# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/05 21:05:49 by vdaviot           #+#    #+#              #
#    Updated: 2015/06/05 21:05:52 by vdaviot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c key/key1.c key/key2.c key/key3.c draw/render.c draw/raycast.c fps.c ft_convert.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/libft

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) -L includes/libft -lft -lmlx $(OBJ) -o $(NAME) -I\
		includes/libft/libft.h includes/libft/libft.a -framework OpenGL \
		-framework AppKit -funroll-loops -pipe -Ofast
		@echo "compile to $(NAME) DONE !"

lib:
	@make -C $(INCLUDES)
clean:
		@rm -f $(OBJ)
		@echo "clean of object done !"
fclean: clean
		@rm -f $(NAME)
		@echo "fclean $(NAME) done !"
re: fclean all

.PHONY: re clean fclean run all
