/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:53:07 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/30 04:18:51 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"
#include "text.h"

void	draw_line(float x, float y, float x1, float y1, t_fdf *data, t_data *img)
{
	float	x_step;
	float	y_step;
	int		max;

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

void	print_square(t_fdf *data, t_data *img)
{
	data->color = COLOR_WHITE;
	draw_line(10, 10, 200, 10, data, img);
	draw_line(200, 10, 200, 240, data, img);
	draw_line(10, 10, 10, 240, data, img);
	draw_line(200, 240, 10, 240, data, img);
}

void	print_menu(t_fdf *data, t_data *img)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	print_square(data, img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img, 0, 0);
	mlx_string_put(mlx, win, 40, y += 35, COLOR_L_GREY, STR_MENU);
	mlx_string_put(mlx, win, 35, y += 35, COLOR_L_GREY, STR_ZOOM);
	mlx_string_put(mlx, win, 35, y += 30, COLOR_L_GREY, STR_MOVE);
	mlx_string_put(mlx, win, 35, y += 30, COLOR_L_GREY, STR_ROTATE);
	mlx_string_put(mlx, win, 35, y += 30, COLOR_L_GREY, STR_PROJECTION);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_ISOMETRIC);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_PARALLEL);
	mlx_string_put(mlx, win, WIDTH - 200, HEIGHT - 30, COLOR_L_GREY, STR_QUIT);
}
