/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:49:23 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/26 01:07:09 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <X11/keysym.h>

typedef struct s_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*tmp;
}	t_params;

// LIBFT
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(const char *str, int fd);

#endif
