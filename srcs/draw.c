/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 06:31:38 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/03 14:57:59 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_coord coord, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = coord.x1 - coord.x;
	y_step = coord.y1 - coord.y;
	max = (fmaxf(fabsf(x_step), fabsf(y_step)));
	x_step /= max;
	y_step /= max;
	while ((int)(coord.x - coord.x1) || (int)(coord.y - coord.y1))
	{
		my_mlx_pixel_put(data->img, coord.x, coord.y, data->color);
		coord.x += x_step;
		coord.y += y_step;
	}
}

void	isometric(float *x, float *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	bresenham(t_coord coord, t_fdf *data)
{
	if (coord.z || coord.z1)
		data->color = 0xf7e436;
	else
		data->color = 0x40eb34;
	if (data->is_iso)
	{
		isometric(&coord.x, &coord.y, coord.z);
		isometric(&coord.x1, &coord.y1, coord.z1);
	}
	coord.x += data->shift_x;
	coord.x1 += data->shift_x;
	coord.y += data->shift_y;
	coord.y1 += data->shift_y;
	draw_line(coord, data);
}

t_coord	project(t_coord coord, t_fdf *data)
{
	coord.z = data->z_matrix[(int)coord.y][(int)coord.x];
	coord.z1 = data->z_matrix[(int)coord.y1][(int)coord.x1];
	coord.x *= data->zoom;
	coord.y *= data->zoom;
	coord.x1 *= data->zoom;
	coord.y1 *= data->zoom;
	return (coord);
}

void	draw_map(t_fdf *data, t_data *img)
{
	int	x;
	int	y;

	ft_bzero(img->addr, WIDTH * HEIGHT * (img->bits_per_pixel / 8));
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(project(get_coord(x, y, x + 1, y), data), data);
			if (y < data->height - 1)
				bresenham(project(get_coord(x, y, x, y + 1), data), data);
			x++;
		}
		y++;
	}
	print_menu(data, img);
}
