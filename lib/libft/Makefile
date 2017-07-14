# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#   .c \reated: 2016/02/12 21:59:32 by dgaitsgo          #+#    #+#            #
#    Updated: 2017/03/21 17:10:10 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = \
 \
ft_abs.c \
ft_atoi.c	\
ft_bzero.c	\
ft_isalnum.c 	\
ft_isalpha.c	\
ft_isascii.c	\
ft_isdigit.c	\
ft_isprint.c	\
ft_isspace.c	\
ft_itoa.c	\
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_memalloc.c	\
ft_memccpy.c	\
ft_memchr.c	\
ft_memcmp.c	\
ft_memcpy.c	\
ft_memdel.c	\
ft_memmove.c	\
ft_memset.c	\
ft_putchar.c	\
ft_putchar_fd.c	\
ft_putendl.c	\
ft_putendl_fd.c	\
ft_putnbr.c	\
ft_putnbr_fd.c	\
ft_putstr.c	\
ft_putstr_fd.c	\
ft_qsort.c \
ft_realloc.c \
ft_strcat.c	\
ft_strchr.c	\
ft_strclr.c	\
ft_strcmp.c	\
ft_strcpy.c	\
ft_strdel.c	\
ft_strdup.c	\
ft_strequ.c	\
ft_strtrim.c	\
ft_striter.c	\
ft_striteri.c	\
ft_strjoin.c	\
ft_strlcat.c	\
ft_strlen.c	\
ft_strmap.c	\
ft_strmapi.c	\
ft_strncat.c	\
ft_strncmp.c	\
ft_strncpy.c	\
ft_strnequ.c	\
ft_strnew.c	\
ft_strnstr.c	\
ft_strrchr.c	\
ft_strsplit.c	\
ft_strstr.c	\
ft_strsub.c	\
ft_strtrim.c	\
ft_swap.c		\
ft_tolower.c	\
ft_toupper.c 	\
get_next_line.c \

HEADERS = libft.h

OBS = $(SOURCE:.c=.o)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SOURCE) $(HEADERS)
	ar rc $(NAME) $(OBS)

all: $(NAME)

clean:
	rm -rf $(OBS) libft.h.gch

fclean: clean
	rm -rf $(NAME)

re: fclean all
