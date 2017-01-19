# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgengo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/21 08:20:55 by jgengo            #+#    #+#              #
#    Updated: 2017/01/14 10:56:59 by jgengo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror
ATTACH = -lmlx -framework OpenGL -framework AppKit -L./libft -lft

SRC = main.c check_args.c parse_args.c event_key.c \
	  map_proj.c draw_line.c
OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -I libft/ -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(ATTACH)

run42:
	./fdf tests/42.fdf

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
