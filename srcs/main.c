/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:09:26 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/26 09:18:16 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	deal_key(int key, t_fdf *data)
{
	if ((key == 'c' && data->prev_key == XK_Control_L) || key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
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
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_fdf	*data;

	(void)argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(argv[1], data);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FdF");
	data->zoom = 40;
	data->prev_key = 0;
	data->shift_x = 270;
	data->shift_y = 270;

	//bresenham(10, 10, 600, 300, data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		free(data->z_matrix[i]);
		printf("\n");
		i++;
	}
	free(data->z_matrix);
	free(data);
	return (0);
}

/*
int	main(int argc, char const *argv[])
{
	t_fdf	*data;

	(void)argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(argv[1], data);

	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		free(data->z_matrix[i]);
		printf("\n");
		i++;
	}
	free(data->z_matrix);
	free(data);
	return (0);
}*/

/*
int	deal_key(int key, t_params *params)
{
	if ((key == 'c' && *params->tmp == XK_Control_L) || key == XK_Escape)
	{
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(EXIT_SUCCESS);
	}
	printf("Key: %d, Tmp: %d\n", key, *params->tmp);
	*params->tmp = key;
	return (0);
}

int	main(void)
{
	t_params	params;

	//memset(&params, 0, sizeof(t_params));
	//params.mlx_ptr = 0;
	//params.win_ptr = 0;
	//params.tmp = 0;
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, 500, 500, "MLX 42");
	mlx_pixel_put(params.mlx_ptr, params.win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(params.win_ptr, deal_key, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}*/
