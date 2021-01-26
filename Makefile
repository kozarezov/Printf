# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 14:44:39 by ceccentr          #+#    #+#              #
#    Updated: 2020/06/01 11:40:25 by ceccentr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_putchar.c \
		ft_param.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_itoa_base_u.c \
		ft_tolower_str.c \
		ft_flag.c \
		ft_atoi.c \
		ft_strlen.c \
		ft_len_param.c \
		ft_isdigit.c \
		len_num.c \
		ft_star.c \
		ft_isalpha.c \
		ft_itoa.c \
		ft_clear_list.c \
		ft_print_n.c \
		ft_print_sim.c \
		ft_print_str.c \
		ft_print_hex.c \
		ft_strjoin_f.c \
		ft_strlcpy.c \
		ft_print_p.c \
		ft_strdup.c \
		ft_print_nofing.c

OBJECTS = ft_printf.o \
			ft_putchar.o \
			ft_param.o \
			ft_putnbr.o \
			ft_putstr.o \
			ft_itoa_base_u.o \
			ft_tolower_str.o \
			ft_flag.o \
			ft_atoi.o \
			ft_strlen.o \
			ft_len_param.o \
			ft_isdigit.o \
			len_num.o \
			ft_star.o \
			ft_isalpha.o \
			ft_itoa.o \
			ft_clear_list.o \
			ft_print_n.o \
			ft_print_sim.o \
			ft_print_str.o \
			ft_print_hex.o \
			ft_strjoin_f.o \
			ft_strlcat.o \
			ft_strlcpy.o \
			ft_print_p.o \
			ft_strdup.o \
			ft_print_nofing.o

FLAGS = -Wall -Wextra -Werror
INCLUDE = ./
HEADER = libftprintf.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $?
	ranlib $(NAME)

$(OBJECTS): %.o: %.c $(HEADER)
	gcc -c $(FLAGS) -I$(INCLUDE) $< -o $@

clean:
	/bin/rm -f $(OBJECTS) $(OBJECTS_BONUS)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
