/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:49:23 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/03 21:56:20 by nvasilev         ###   ########.fr       */
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
# define MENU_WIDTH 240
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
}	t_coord;

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

	int		**z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
}	t_fdf;

void	read_map(const char *file_name, t_fdf *data);
void	bresenham(t_coord coord, t_fdf *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_coord	get_coord(int x, int y, int x1, int y1);
void	draw_line(t_coord coord, t_fdf *data);
void	draw_map(t_fdf *data, t_data *img);
void	print_menu(t_fdf *data, t_data *img);
void	init(t_fdf *data, t_data *img);
void	err_alloc(void);
void	err_mlx(void *addr);
void	exit_success(t_fdf *data);
int		key_press(int key, t_fdf *data);
void	init_controls(t_fdf *data);

#endif
