/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:51:24 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 15:52:18 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	get_coord(int x, int y, int x1, int y1)
{
	t_coord	coord;

	coord.x = x;
	coord.x1 = x1;
	coord.y = y;
	coord.y1 = y1;
	return (coord);
}
