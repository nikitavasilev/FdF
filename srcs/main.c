/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:09:26 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/28 05:18:32 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_and_quit(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data);
	exit(EXIT_SUCCESS);
}

int	deal_key(int key, t_fdf *data)
{
	if ((key == 'c' && data->prev_key == XK_Control_L) || key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_and_quit(data);
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
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, NAME);
	data->prev_key = 0;
	data->shift_x = MENU_WIDTH + (WIDTH - (data->width * data->zoom)) / 2;
	data->shift_y = (HEIGHT - (data->height * data->zoom)) / 2;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
