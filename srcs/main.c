/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:09:26 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/29 06:41:43 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_and_quit(t_fdf *data)
{
	int	i;

	i = 0;
	while (data->z_matrix[i])
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data->img);
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
		free(data->mlx_ptr);
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
	draw(data, data->img);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_fdf	*data;
	t_data	*img;

	(void)argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	img = (t_data *)malloc(sizeof(t_data));
	read_map(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, NAME);
	img->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	data->prev_key = 0;
	data->shift_x = MENU_WIDTH + (WIDTH - (data->width * data->zoom)) / 2;
	data->shift_y = (HEIGHT - (data->height * data->zoom)) / 2;
	draw(data, img);
	data->img = img;
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
