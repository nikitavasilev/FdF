/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:59:00 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 16:00:34 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_axis(int key, t_fdf *data)
{
	if (key == XK_KP_Down)
		data->x_axis += 0.01;
	else if (key == XK_KP_Up)
		data->x_axis -= 0.01;
	else if (key == XK_KP_Left)
		data->y_axis -= 0.01;
	else if (key == XK_KP_Right)
		data->y_axis += 0.01;
	else if (key == XK_KP_End || key == XK_KP_Home)
		data->z_axis += 0.01;
	else if (key == XK_KP_Next || key == XK_KP_Prior)
		data->z_axis -= 0.01;
}

void	rotate_x(float *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(float *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(float *x, float *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}
