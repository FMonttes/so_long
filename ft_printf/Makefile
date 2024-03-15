# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmontes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 09:51:05 by fmontes           #+#    #+#              #
#    Updated: 2023/10/27 14:58:38 by fmontes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = check_args.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c \
       ft_putstr.c ft_putunsgnbr.c get_lowhex.c get_mem.c get_upphex.c		
	    
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)


