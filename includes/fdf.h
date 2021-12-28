/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:49:23 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/28 17:54:35 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

# define MAX(a, b) ((a > b) ? a : b)
# define MIN(a, b) ((a < b) ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

# define WIDTH 1600
# define HEIGHT 900
# define MENU_WIDTH 240
# define NAME "FdF - 3D Wireframe Viewer"

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
void	print_menu(t_fdf *data);

// UTILS
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(const char *str, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);

#endif
