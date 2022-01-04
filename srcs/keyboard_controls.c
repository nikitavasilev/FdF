/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 02:12:30 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 16:08:55 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_z_axis(int key, t_fdf *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (key == XK_Page_Up && data->z_matrix[i][j])
			{
				if (data->z_matrix[i][j] == -1)
					data->z_matrix[i][j] += 2;
				else
					data->z_matrix[i][j]++;
			}
			else if (key == XK_Page_Down && data->z_matrix[i][j])
			{
				if (data->z_matrix[i][j] == 1)
					data->z_matrix[i][j] -= 2;
				else
					data->z_matrix[i][j]--;
			}
		}
	}
}

static void	zoom_move_axis(int key, t_fdf *data)
{
	if (key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left)
		move(key, data);
	if (key == XK_KP_Add || key == XK_plus)
		data->zoom++;
	if (key == XK_KP_Subtract || key == XK_minus)
		data->zoom--;
	if (key == XK_Page_Up || key == XK_Page_Down)
		change_z_axis(key, data);
	if (key == XK_KP_End
		|| key == XK_KP_Down || key == XK_KP_Next
		|| key == XK_KP_Left || key == XK_KP_Begin
		|| key == XK_KP_Right || key == XK_KP_Home
		|| key == XK_KP_Up || key == XK_KP_Prior)
		rotate_axis(key, data);
}

int	key_press(int key, t_fdf *data)
{
	if ((key == 'c' && data->prev_key == XK_Control_L) || key == XK_Escape)
		exit_success(data);
	data->prev_key = key;
	if (key == 'i')
	{
		data->is_iso = 1;
		data->z_axis = 0;
	}
	if (key == 'd')
	{
		data->is_iso = 0;
		data->z_axis = 0;
	}
	if (key == 'p')
	{
		data->is_iso = 1;
		data->z_axis = -0.786799;
	}
	zoom_move_axis(key, data);
	draw_map(data, data->img);
	return (0);
}
