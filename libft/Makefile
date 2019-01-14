# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 10:19:15 by pavaucha          #+#    #+#              #
#    Updated: 2018/03/15 14:35:13 by pavaucha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = includes/ft_printf.h

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = libftprintf.a

SRC = ft_printf.c \
	ft_start_printf.c \
	ft_nullstr.c \
	ft_stock_zflags.c \
	ft_affiche_bc.c \
	ft_change_flags.c \
	ft_change_zflags.c \
	ft_affiche.c \
	ft_affiche_p.c \
	ft_champ_minimum.c \
	ft_precision.c \
	ft_d_affiche.c \
	ft_stock_zero.c \
	ft_affiche_s.c \
	ft_affiche_bs.c \
	ft_affiche_c.c \
	ft_putchar_unicode.c \
	ft_d_affiche.c \
	ft_start_flags.c \
	s_printf.c \
	c_printf.c \
	d_printf.c \
	p_printf.c \
	o_printf.c \
	ft_putnbr_hecto.c \
	ft_putnbr_hexa.c \
	u_printf.c \
	ft_putnbr_max.c \
	ft_size_modification.c \
	ft_found_flags.c \
	ft_putunsigned_int.c \
	ft_usize_modif.c \
	ft_put_type.c \
	x_printf.c \
	ft_affiche_pourc.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putendl.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@ $(CC) $(FLAGS) -c $(SRC) -I $(INC)
	@ ar rc $(NAME) $(SRCO)
	@ ranlib $(NAME)

clean:
	@ rm -f $(SRCO)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
