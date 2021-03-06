# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 00:24:06 by nvasilev          #+#    #+#              #
#    Updated: 2022/01/04 16:20:01 by nvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = 			fdf

CC = 			gcc
CFLAGS =		-Wall -Wextra -Werror -O3 -g
RM =			rm -f

MLX = minilibx-linux/libmlx.a
LIBS = -L minilibx-linux/ -lmlx -lXext -lX11 -lm
INCLUDES = -I ./minilibx-linux/ -I ./includes/

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS =			./srcs/main.c \
				./srcs/read_map.c \
				./srcs/draw.c \
				./srcs/menu.c \
				./srcs/init.c \
				./srcs/error.c \
				./srcs/exit.c \
				./srcs/keyboard_controls.c \
				./srcs/init_controls.c \
				./srcs/color.c \
				./srcs/project.c \
				./srcs/get_coord.c \
				./srcs/move.c \
				./srcs/rotate.c

UTILS =			./utils/ft_putchar_fd.c \
				./utils/ft_putstr_fd.c \
				./utils/ft_putnbr_fd.c \
				./utils/ft_bzero.c \
				./utils/ft_strchr.c \
				./utils/ft_strdup.c \
				./utils/ft_strjoin.c \
				./utils/ft_strlen.c \
				./utils/ft_substr.c \
				./utils/get_next_line.c \
				./utils/ft_isdigit.c \
				./utils/ft_atoi.c \
				./utils/ft_split.c \
				./utils/wdcounter.c \
				./utils/ft_min.c

################################################################################
#                                     OBJECTS                                  #
################################################################################

OBJS_SRCS =		$(SRCS:%.c=%.o)
OBJS =			$(UTILS:%.c=%.o)

################################################################################
#                                     RULES                                    #
################################################################################

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -c $< -o $@

$(NAME): $(MLX) $(OBJS) $(OBJS_SRCS)
	$(CC) $(OBJS) $(OBJS_SRCS) $(INCLUDES) $(LIBS) -o $@

$(MLX):
	$(MAKE) -C $(MLX:libmlx.a=)

clean:
	$(RM) $(OBJS) $(OBJS_SRCS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus: all

.PHONY: all clean fclean bonus re
