# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmount <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 10:04:52 by rmount            #+#    #+#              #
#    Updated: 2023/04/15 13:20:32 by rmount           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iheader_files/ 

SRC = srcs/*.c
PRINTF = ft_printf/
PRINTF_A = $(PRINTF)*.a
GNL = get_next_line/*.c
LIB = -L mini_lib_x -lmlx -framework OpenGL -framework AppKit
MLX := mini_lib_x/
BUFF_SIZE = -D BUFFER_SIZE=100

all: $(PRINTF_A)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(SRC) $(PRINTF_A) $(BUFF_SIZE) $(GNL)  $(LIB) -o $(NAME)

$(PRINTF_A):
	make -C $(PRINTF)
	cp -f $(PRINTF)headers/* header_files

r:
	make
	clear
	./$(NAME) maps/map3.ber

clean:
	make clean -C $(MLX)
	make clean -C $(PRINTF)
	rm -rf $(NAME)

fclean: clean
	make fclean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re