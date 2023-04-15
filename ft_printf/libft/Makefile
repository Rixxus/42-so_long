# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmount <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 14:49:46 by rmount            #+#    #+#              #
#    Updated: 2022/03/02 08:54:09 by rmount           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc -I ../headers
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

#---------------#
#    SOURCES    #
#---------------#

SRC_CHAR = ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_islower.c \
		   ft_isprint.c \
		   ft_isspace.c \
		   ft_isupper.c

SRC_CONVERSION = ft_atoi.c \
				 ft_itoa.c 

SRC_MEMORY = ft_bzero.c \
			 ft_calloc.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_memset.c 

SRC_PRINT = ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c	

SRC_STR = ft_split.c \
		  ft_strchr.c \
		  ft_strdlen.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c 

SRCS = $(SRC_CHAR) \
	   $(SRC_CONVERSION) \
	   $(SRC_MEMORY) \
	   $(SRC_PRINT) \
	   $(SRC_STR)

OBJS = $(SRCS:.c=.o)

#-------------#
#    BONUS    #
#-------------#

BONUS_SRC_LIST = ft_lstadd_back.c \
				 ft_lstadd_front.c \
				 ft_lstclear.c \
				 ft_lstdelone.c \
				 ft_lstiter.c \
				 ft_lstlast.c \
				 ft_lstmap.c \
				 ft_lstnew.c \
				 ft_lstsize.c 

BONUS_SRCS = $(BONUS_SRC_LIST)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

#-------------#
#    RULES    #
#-------------#

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I . -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus:
	$(CC) $(CFLAGS) -I . -c $(SRCS) $(BONUS_SRCS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
