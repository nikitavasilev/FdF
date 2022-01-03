/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:09:26 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/03 03:35:39 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		draw_map(data, img);
		init_controls(data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
