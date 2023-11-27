# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmoussa <chmoussa@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 14:26:47 by chmoussa          #+#    #+#              #
#    Updated: 2023/03/14 14:26:57 by chmoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c ft_memchr.c ft_memset.c ft_strlen.c	ft_tolower.c  \
			ft_atoi.c ft_isascii.c ft_memcmp.c ft_strncmp.c ft_toupper.c \
			ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strlcat.c	ft_strnstr.c ft_isalnum.c \
			ft_isprint.c ft_memmove.c ft_strlcpy.c ft_calloc.c ft_strdup.c	\
			ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c	ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c	ft_striteri.c	ft_strjoin.c	ft_strmapi.c	ft_strtrim.c ft_strchr.c \
			ft_substr.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthex.c \
			ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_base.c ft_printf/ft_putptr.c \
			ft_printf/ft_putint.c \


NAME	= libft.a

OBJS	=  ${SRCS:.c=.o}

.c.o	:
		gcc -Wall -Wextra -Werror -g -I . -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

so:
	gcc -nostartfiles -fPIC -Wall -Werror -Wextra $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

so:
	gcc -nostartfiles -fPIC -Wall -Werror -Wextra $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
