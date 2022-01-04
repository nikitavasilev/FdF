/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:57:24 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 15:58:03 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
