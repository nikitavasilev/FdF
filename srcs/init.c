/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 06:12:26 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/03 22:01:35 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	init_shift(t_fdf *data)
{
	data->shift_x = (MENU_WIDTH + (WIDTH - (data->width * data->zoom))) / 2;
	data->shift_y = (HEIGHT - (data->height * data->zoom)) / 2;
}

static void	init_zoom(t_fdf *data)
{
	data->zoom = ft_min((WIDTH - MENU_WIDTH) / data->width / 2,
			HEIGHT / data->height / 2);
}

static int	init_img(t_fdf *data, t_data *img)
{
	img->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->img || !img->addr)
		return (0);
	return (1);
}

static int	init_mlx(t_fdf *data, t_data *img)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, NAME);
	if (!data->mlx_ptr || !data->win_ptr)
		return (0);
	data->prev_key = 0;
	data->is_iso = 1;
	data->img = img;
	return (1);
}

void	init(t_fdf *data, t_data *img)
{
	if (!init_mlx(data, img))
		err_mlx(data);
	if (!init_img(data, img))
		err_mlx(img);
	init_zoom(data);
	init_shift(data);
}
