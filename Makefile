# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 17:44:00 by jamrabhi          #+#    #+#              #
#    Updated: 2020/02/22 23:33:37 by jamrabhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HDR = ft_printf.h

SRCS = ft_printf.c ft_putchar_count.c ft_putstr_count.c type_s.c \
		type_d.c type_c.c ft_putnbr_count.c dec_to_hex.c ft_bzero.c \
		ft_isdigit.c ft_strlen.c ft_strrev.c ft_substr.c ft_atoi.c type_p.c \
		ft_strjoin.c type_u.c type_percent.c type_x.c type_x_upper.c\
		dec_to_hex_upper.c checkers.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
