/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:09:26 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/26 00:47:29 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	params.mlx_ptr = 0;
	params.win_ptr = 0;
	params.tmp = 0;
	params.mlx_ptr = mlx_init();
	params.win_ptr = mlx_new_window(params.mlx_ptr, 500, 500, "MLX 42");
	mlx_pixel_put(params.mlx_ptr, params.win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(params.win_ptr, deal_key, &params);
	mlx_loop(params.mlx_ptr);
	return (0);
}
