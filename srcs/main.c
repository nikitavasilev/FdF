/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:09:26 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/03 21:56:31 by nvasilev         ###   ########.fr       */
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
		read_map(argv[1], data);
		init(data, img);
		draw_map(data, img);
		init_controls(data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
