/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 06:31:38 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/30 04:33:32 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	isometric(float *x, float *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;

	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data, t_data *img)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	//----------zoom---------
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	//----------color--------
	data->color = (z || z1) ? 0xf7e436 : 0x40eb34;
	//-----------3d----------
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	//-----------shift--------
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;

	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(img, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data, t_data *img)
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
				bresenham(x, y, x + 1, y, data, img);
			if (y < data-> height - 1)
				bresenham(x, y, x, y + 1, data, img);
			x++;
		}
		y++;
	}
	print_menu(data, img);
}
