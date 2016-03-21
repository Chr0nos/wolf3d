# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/19 22:06:06 by snicolet          #+#    #+#              #
#    Updated: 2016/03/21 15:20:04 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
FLAGS=-Wall -Wextra -Werror -Weverything -fsanitize=address
DRAW=./libs/draw
MLX=./libs/minilibx_macos
LIBFT=./libs/libft
INC=-I./headers -I $(DRAW) -I $(LIBFT)
CC=clang
LINKER=$(FLAGS) -L $(LIBFT) -lft -L $(DRAW) -ldraw -L $(MLX) -lmlx -lm -framework AppKit -framework OpenGL
OBJ=main.o closer.o events.o parser.o display_map.o display.o

all: $(NAME)
	$(CC) $(OBJ) $(LINKER) -o $(NAME)

$(NAME): $(LIBFT)/libft.a $(DRAW)/libdraw.a $(OBJ)

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
	make -C $(DRAW) fclean

relibs: fcleanlibs $(LIBFT)/libft.a $(DRAW)/libdraw.a $(OBJ)

.PHONY: all re clean fclean
