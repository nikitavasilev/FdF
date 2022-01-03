/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 06:35:45 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/30 06:39:37 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	destroy_mlx(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
}

void	exit_success(t_fdf *data)
{
	size_t	i;

	destroy_mlx(data);
	i = 0;
	while (data->z_matrix[i])
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data->img);
	free(data->mlx_ptr);
	free(data);
	exit(EXIT_SUCCESS);
}
