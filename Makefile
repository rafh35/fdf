# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/12/19 15:58:24 by maberkan     #+#   ##    ##    #+#        #
#    Updated: 2019/02/20 14:35:34 by maberkan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

NAME = fdf

SRC = ./main.c ft_parce.c ft_stock_pos.c ft_read_line.c \
		ft_count_nbr.c ft_count_line.c ft_c_strlen.c ft_algo_bre.c \
		ft_projection.c legend.c ft_init_window.c ft_fdf.c

LIB = libft/libft.a

MLX = libmlx/libmlx.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(LIB) $(MLX) $(OBJ)
	$(CC) -framework OpenGL -framework AppKit -I includes -o $@ $^ $(LIB) $(MLX) $(FLAGS)

$(LIB):
	make -C libft

$(MLX):
	make -C libmlx

%.o: %.c
	 $(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
	make -C libft clean
	make -C libmlx clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLX)
	rm -rf $(LIB)

re: fclean all
