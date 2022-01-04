/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 06:31:38 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 03:07:41 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "color.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * data->bits_per_pixel / 8) + (y * data->line_length);
		data->addr[i] = color;
		data->addr[++i] = color >> 8;
		data->addr[++i] = color >> 16;
	}
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_coord current, t_coord start, t_coord end, t_coord delta)
{
	int	red;
	int	green;
	int	blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x1, current.x);
	else
		percentage = percent(start.y, end.y1, current.y);
	if ((current.z > current.z1 && current.z > 0) ||
	(current.z < current.z1 && current.z < 0))
	{
		red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
		green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
		blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	}
	else
	{
		red = get_light((end.color >> 16) & 0xFF, (start.color >> 16) & 0xFF, percentage);
		green = get_light((end.color >> 8) & 0xFF, (start.color >> 8) & 0xFF, percentage);
		blue = get_light(end.color & 0xFF, start.color & 0xFF, percentage);
	}
	return ((red << 16) | (green << 8) | blue);
}

void	draw_line(t_coord coord, t_fdf *data)
{
	t_coord	delta;
	t_coord	start;
	t_coord	end;
	int		max;

	start = coord;
	start.color = data->color;
	coord.color = start.color;
	end = coord;
	if (!coord.z || !coord.z1)
		end.color = 0xf7797d;
	else
		end.color = data->color;
	delta.x = coord.x1 - coord.x;
	delta.y = coord.y1 - coord.y;
	max = (fmaxf(fabsf(delta.x), fabsf(delta.y)));
	delta.x /= max;
	delta.y /= max;
	while ((int)(coord.x - coord.x1) || (int)(coord.y - coord.y1))
	{
		my_mlx_pixel_put(data->img, coord.x, coord.y, get_color(coord, start, end, delta));
		coord.x += delta.x;
		coord.y += delta.y;
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
		data->color = 0xFBD786;
	else
		data->color = 0xf7797d;
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
	coord.z = data->z_matrix[(int)coord.y][(int)coord.x] * 2;
	coord.z1 = data->z_matrix[(int)coord.y1][(int)coord.x1] * 2;
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
