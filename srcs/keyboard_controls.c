/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 02:12:30 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/03 22:48:51 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_z(int key, t_fdf *data)
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

void	move(int key, t_fdf *data)
{
	if (key == XK_Up)
		data->shift_y -= 10;
	else if (key == XK_Down)
		data->shift_y += 10;
	else if (key == XK_Right)
		data->shift_x += 10;
	else if (key == XK_Left)
		data->shift_x -= 10;
}

int	key_press(int key, t_fdf *data)
{
	if ((key == 'c' && data->prev_key == XK_Control_L) || key == XK_Escape)
		exit_success(data);
	data->prev_key = key;
	if (key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left)
		move(key, data);
	if (key == 'i')
		data->is_iso = 1;
	if (key == 'p')
		data->is_iso = 0;
	if (key == XK_KP_Add || key == XK_plus)
		data->zoom++;
	if (key == XK_KP_Subtract || key == XK_minus)
		data->zoom--;
	if (key == XK_Page_Up || key == XK_Page_Down)
		change_z(key, data);
	draw_map(data, data->img);
	return (0);
}
