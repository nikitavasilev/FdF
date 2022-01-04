/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 02:32:06 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/03 22:52:14 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(void *param)
{
	exit_success(param);
	return (0);
}

void	init_controls(t_fdf *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, 17, 1L << 5, close_window, data);
	//mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	//mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	//mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
}
