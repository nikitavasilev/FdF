# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 00:24:06 by nvasilev          #+#    #+#              #
#    Updated: 2021/12/26 02:43:44 by nvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = 			fdf

CC = 			gcc
CFLAGS =		-Wall -Wextra -Werror
RM =			rm -f

MLX = minilibx-linux/libmlx.a
LIBS = -L minilibx-linux/ -lmlx -lXext -lX11
INCLUDES = -I minilibx-linux/

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS =			./srcs/main.c

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
				./utils/ft_atoi.c

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
	$(CC) $(CFLAGS)  $(INCLUDES) $(LIBS) -c $< -o $@

$(NAME): $(MLX) $(OBJS) $(OBJS_SRCS)
	$(CC) $(OBJS) $(OBJS_SRCS) $(INCLUDES) $(LIBS) -o $@

$(MLX):
	$(MAKE) -C $(MLX:libmlx.a=)

clean:
	$(RM) $(OBJS) $(OBJS_SRCS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
