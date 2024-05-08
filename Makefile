# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 09:51:59 by rmarquar          #+#    #+#              #
#    Updated: 2024/01/30 08:59:24 by rmarquar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
CC		:=	cc
FLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -f
SRCS	:=	utils.c \
			utils2.c \
			ft_c.c \
			ft_s.c \
			ft_p.c \
			ft_d.c \
			ft_ux.c \
			ft_printf.c \

OBJS	:=	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
