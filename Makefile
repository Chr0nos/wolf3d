# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/19 22:06:06 by snicolet          #+#    #+#              #
#    Updated: 2016/03/19 22:39:33 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
FLAGS=-Wall -Wextra -Werror -Weverything
DRAW=./libs/draw
MLX=./libs/minilibx_macos
LIBFT=./libs/libft
INC=-I./headers -I $(DRAW) -I $(LIBFT)
CC=clang
LINKER=-L $(LIBFT) -lft -L $(DRAW) -ldraw -L $(MLX) -lmlx -lm -framework AppKit -framework OpenGL
OBJ=main.o closer.o events.o

all: $(NAME)
	$(CC) $(OBJ) $(LINKER) -o $(NAME)

$(NAME): $(LIBFT)/libft.a $(DRAW)/libdraw.a $(OBJ)

%.o: %.c
	$(CC) -c $< $(INC) $(FLAGS)

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(DRAW)/libdraw.a:
	make -C $(DRAW) MLX=../../$(MLX)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
