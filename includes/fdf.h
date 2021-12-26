/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:49:23 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/26 08:21:45 by nvasilev         ###   ########.fr       */
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
# include <fcntl.h>
# include <math.h>

# define MAX(a, b) ((a > b) ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef struct s_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*tmp;
}	t_params;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		prev_key;

	int		**z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	read_map(const char *file_name, t_fdf *data);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);

// UTILS
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(const char *str, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

#endif
