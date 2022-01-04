/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:43:33 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 15:47:01 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

static void	isometric(float *x, float *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

static void	shift_coord(t_coord *coord, t_fdf *data)
{
	coord->x += data->shift_x;
	coord->x1 += data->shift_x;
	coord->y += data->shift_y;
	coord->y1 += data->shift_y;
}

static void	zoom_coord(t_coord *coord, t_fdf *data)
{
	coord->x *= data->zoom;
	coord->y *= data->zoom;
	coord->x1 *= data->zoom;
	coord->y1 *= data->zoom;
}

static void	rotate_coord(t_coord *coord, t_fdf *data)
{
	rotate_x(&coord->y, &coord->z, data->x_axis);
	rotate_y(&coord->x, &coord->z, data->y_axis);
	rotate_z(&coord->x, &coord->y, data->z_axis);
	rotate_x(&coord->y1, &coord->z1, data->x_axis);
	rotate_y(&coord->x1, &coord->z1, data->y_axis);
	rotate_z(&coord->x1, &coord->y1, data->z_axis);
}

void	project(t_coord coord, t_fdf *data)
{
	coord.z = data->z_matrix[(int)coord.y][(int)coord.x] * 2;
	coord.z1 = data->z_matrix[(int)coord.y1][(int)coord.x1] * 2;
	zoom_coord(&coord, data);
	rotate_coord(&coord, data);
	if (coord.z || coord.z1)
		data->color = COLOR_YELLOW;
	else
		data->color = COLOR_PURPLE;
	if (data->is_iso)
	{
		isometric(&coord.x, &coord.y, coord.z);
		isometric(&coord.x1, &coord.y1, coord.z1);
	}
	shift_coord(&coord, data);
	draw_line(coord, data);
}
