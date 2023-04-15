# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmount <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 10:36:38 by rmount            #+#    #+#              #
#    Updated: 2023/03/12 10:27:30 by rmount           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders -I . -c

RM = rm -f

SRCS = srcs/ft_char_type.c \
	   srcs/ft_printf.c \
	   srcs/ft_char_print.c \
	   srcs/ft_str_print.c \
	   srcs/ft_num_length.c \
	   srcs/ft_hex_print.c \
	   srcs/ft_num_print.c

OBJ_DEST = mv *.o srcs

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRCS)
	$(OBJ_DEST)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
