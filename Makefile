# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/19 22:06:06 by snicolet          #+#    #+#              #
#    Updated: 2016/03/28 20:13:45 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
FLAGS=-Wall -Wextra -Werror -Weverything -pipe -Ofast -g3
DRAW=./libs/draw
MLX=./libs/minilibx_macos
LIBFT=./libs/libft
INC=-I./headers -I $(DRAW) -I $(LIBFT) -I $(MLX)
CC=clang
LINKER=$(FLAGS) -L $(LIBFT) -lft -L $(DRAW) -ldraw -L $(MLX) -lmlx -lm -framework AppKit -framework OpenGL
OBJ=main.o closer.o events.o parser.o display_map.o display.o init.o check.o \
	player_actions.o stats.o popper.o textures.o colors.o

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(DRAW)/libdraw.a $(OBJ)
	$(CC) $(OBJ) $(LINKER) -o $(NAME)

%.o: %.c
	$(CC) -c $< $(INC) $(FLAGS)

$(LIBFT)/libft.a:
	make -C $(LIBFT) FLAGS="$(FLAGS)"

$(DRAW)/libdraw.a:
	make -C $(DRAW) MLX=../../$(MLX) FLAGS="$(FLAGS)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

fcleanlibs:
	make -C $(LIBFT) fclean
	make -C $(DRAW) fclean MLX="../$(MLX)"

relibs: fcleanlibs $(LIBFT)/libft.a $(DRAW)/libdraw.a $(OBJ)

linux:
	make FLAGS="$(FLAGS)" MLX="./libs/minilibx" LINKER="$(FLAGS) -L $(DRAW) -ldraw -L $(LIBFT) -lft -L ./libs/minilibx/ -lmlx -lm -lX11 -lXext"

.PHONY: all re clean fclean
