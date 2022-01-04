/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:49:23 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 18:16:29 by nvasilev         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080
# define MENU_WIDTH 220
# define NAME "FdF - 3D Wireframe Viewer"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_coordinates
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		z;
	int		z1;
	int		color;
}	t_coord;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
	double	percentage;
}	t_color;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		prev_key;
	int		is_iso;
	double	x_axis;
	double	y_axis;
	double	z_axis;

	int		**z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
}	t_fdf;

void	read_map(const char *file_name, t_fdf *data);
void	project(t_coord coord, t_fdf *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_coord	get_coord(int x, int y, int x1, int y1);
void	draw_line(t_coord coord, t_fdf *data);
void	draw_map(t_fdf *data, t_data *img);
void	print_menu(t_fdf *data, t_data *img);
void	init(t_fdf *data, t_data *img);
void	err_alloc(void);
void	err_open(void);
void	err_mlx(void *addr);
void	exit_success(t_fdf *data);
int		key_press(int key, t_fdf *data);
void	init_controls(t_fdf *data);
void	rotate_axis(int key, t_fdf *data);
void	rotate_x(float *y, int *z, double alpha);
void	rotate_y(float *x, int *z, double beta);
void	rotate_z(float *x, float *y, double gamma);
int		get_color(t_coord current, t_coord start, t_coord end, t_coord delta);
void	move(int key, t_fdf *data);

#endif
