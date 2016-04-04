# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/19 22:06:06 by snicolet          #+#    #+#              #
#    Updated: 2016/04/05 00:01:29 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
FLAGS=-Wall -Wextra -Werror -pipe -Ofast
DRAW=./libs/draw
LIBFT=./libs/libft
SDL=~/.brew/include/
INC=-I./headers -I $(DRAW)/headers/ -I $(LIBFT) -I $(SDL)
CC=clang
SDLLINK=-L ~/.brew/lib/ -lSDL2 -lSDL2_image
LINKER=$(FLAGS) -L $(LIBFT) -L $(DRAW) -ldraw -lft -lm $(SDLLINK)
OBJ=main.o closer.o events.o parser.o display_map.o display.o init.o check.o \
	player_actions.o stats.o popper.o textures.o colors.o fix_y.o textures_base.o \
	textures_floor.o event_togglefs.o

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(DRAW)/libdraw.a $(OBJ)
	$(CC) $(OBJ) $(LINKER) -o $(NAME)

%.o: %.c
	$(CC) -c $< $(INC) $(FLAGS)

$(LIBFT)/libft.a:
	make -C $(LIBFT) FLAGS="$(FLAGS)"

$(DRAW)/libdraw.a:
	make -C $(DRAW) FLAGS="$(FLAGS)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

fcleanlibs:
	make -C $(LIBFT) fclean
	make -C $(DRAW) fclean

relibs: fcleanlibs $(LIBFT)/libft.a $(DRAW)/libdraw.a $(OBJ)

linux:
	make FLAGS="$(FLAGS)" LINKER="$(FLAGS) -L $(DRAW) -ldraw -L $(LIBFT) -lft -lm"

.PHONY: all re clean fclean
