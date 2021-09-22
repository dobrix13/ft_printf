# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 12:29:47 by avitolin          #+#    #+#              #
#    Updated: 2021/09/22 23:21:18 by avitolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

PARS_DIR	= ./parser

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I$(LIBFT_DIR)
LFLAGS		= -L$(LIBFT_DIR) -lft
LIB			= ar -rcs
LIB1		= ranlib
RM			= /bin/rm -f

SRC_DIR		= ./souce_files
SRCS		= $(SRC_DIR)/ft_type_conversion.c \
			$(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/ft_vprintf.c \
			$(SRC_DIR)/ft_convert_c.c \
			$(SRC_DIR)/ft_convert_d_i.c \
			$(SRC_DIR)/ft_convert_p.c \
			$(SRC_DIR)/ft_convert_prct.c \
			$(SRC_DIR)/ft_convert_s.c \
			$(SRC_DIR)/ft_convert_ux.c \
			$(SRC_DIR)/ft_initialize_format.c \
			$(SRC_DIR)/ft_placeholder.c \
			$(SRC_DIR)/ft_add_prefix.c \
			$(SRC_DIR)/ft_fill_left_pad.c \
			$(SRC_DIR)/ft_fill_right_pad.c \
			$(SRC_DIR)/ft_u_itoa_base.c \
			$(PARS_DIR)/ft_parse.c \
			$(PARS_DIR)/ft_parse_width.c \
			$(PARS_DIR)/ft_parse_precision.c \
			$(PARS_DIR)/ft_parse_flags.c \
			$(PARS_DIR)/ft_parse_conversion.c \
			$(PARS_DIR)/ft_appendchr.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(LIB)	$(NAME) $(OBJS)
			$(LIB1) $(NAME)

.c.o: 		
			$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(LIBFT):
			make -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)

bonus:		all

clean:
			make clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re