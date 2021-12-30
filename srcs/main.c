/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:09:26 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/30 06:24:54 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_success(t_fdf *data)
{
	int	i;

	i = 0;
	while (data->z_matrix[i])
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data->img);
	free(data->mlx_ptr);
	free(data);
	exit(EXIT_SUCCESS);
}

int	deal_key(int key, t_fdf *data)
{
	if ((key == 'c' && data->prev_key == XK_Control_L) || key == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		exit_success(data);
	}
	data->prev_key = key;
	if (key == XK_Up)
		data->shift_y -= 10;
	if (key == XK_Down)
		data->shift_y += 10;
	if (key == XK_Right)
		data->shift_x += 10;
	if (key == XK_Left)
		data->shift_x -= 10;
	draw(data, data->img);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_fdf	*data;
	t_data	*img;

	if (argc == 2)
	{
		img = (t_data *)malloc(sizeof(t_data));
		if (!img)
			err_alloc();
		data = (t_fdf *)malloc(sizeof(t_fdf));
		if (!data)
			err_alloc();
		init(data, img);
		read_map(argv[1], data);
		init_shift(data);
		draw(data, img);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
