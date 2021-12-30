/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:49:23 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/30 06:20:46 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
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

# define WIDTH 1920
# define HEIGHT 1080
# define MENU_WIDTH 240
# define NAME "FdF - 3D Wireframe Viewer"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_fdf
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
	t_data	*img;
}	t_fdf;

void	read_map(const char *file_name, t_fdf *data);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_fdf *data, t_data *img);
void	print_menu(t_fdf *data, t_data *img);
void	init(t_fdf *data, t_data *img);
void	init_shift(t_fdf *data);
void	err_alloc(void);
void	err_mlx(void *addr);

#endif
