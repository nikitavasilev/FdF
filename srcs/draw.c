/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 06:31:38 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 15:45:45 by nvasilev         ###   ########.fr       */
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
	if ((!coord.z || !coord.z1) && data->color != COLOR_WHITE)
		end.color = COLOR_PURPLE;
	else
		end.color = data->color;
	delta.x = coord.x1 - coord.x;
	delta.y = coord.y1 - coord.y;
	max = (fmaxf(fabsf(delta.x), fabsf(delta.y)));
	delta.x /= max;
	delta.y /= max;
	while ((int)(coord.x - coord.x1) || (int)(coord.y - coord.y1))
	{
		my_mlx_pixel_put(data->img, coord.x, coord.y,
			get_color(coord, start, end, delta));
		coord.x += delta.x;
		coord.y += delta.y;
	}
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
				project(get_coord(x, y, x + 1, y), data);
			if (y < data->height - 1)
				project(get_coord(x, y, x, y + 1), data);
			x++;
		}
		y++;
	}
	print_menu(data, img);
}
