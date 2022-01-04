/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:53:07 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 18:15:50 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"
#include "text.h"

static void	print_square(t_fdf *data)
{
	data->color = COLOR_WHITE;
	draw_line(get_coord(10, 10, 220, 10), data);
	draw_line(get_coord(220, 10, 220, 410), data);
	draw_line(get_coord(10, 410, 10, 10), data);
	draw_line(get_coord(220, 410, 10, 410), data);
}

void	print_menu(t_fdf *data, t_data *img)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	print_square(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img, 0, 0);
	mlx_string_put(mlx, win, 40, y += 35, COLOR_L_GREY, STR_MENU);
	mlx_string_put(mlx, win, 35, y += 35, COLOR_L_GREY, STR_ZOOM);
	mlx_string_put(mlx, win, 35, y += 30, COLOR_L_GREY, STR_MOVE);
	mlx_string_put(mlx, win, 35, y += 30, COLOR_L_GREY, STR_ROTATE);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_ROTATE_X);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_ROTATE_Y);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_ROTATE_Z);
	mlx_string_put(mlx, win, 35, y += 30, COLOR_L_GREY, STR_PROJECTION);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_ISOMETRIC);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_PARALLEL);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_2D);
	mlx_string_put(mlx, win, 35, y += 30, COLOR_L_GREY, STR_Z_AXIS);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_Z_INC);
	mlx_string_put(mlx, win, 55, y += 25, COLOR_L_GREY, STR_Z_DEC);
	mlx_string_put(mlx, win, WIDTH - 200, HEIGHT - 30, COLOR_L_GREY, STR_QUIT);
}
