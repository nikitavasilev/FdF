/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:22:50 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 15:26:50 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "color.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static t_color	gradient(t_color col, t_coord curr, t_coord st, t_coord end)
{
	if ((curr.z > curr.z1 && curr.z > 0)
		|| (curr.z < curr.z1 && curr.z < 0))
	{
		col.red = get_light((st.color >> 16) & 0xFF,
				(end.color >> 16) & 0xFF, col.percentage);
		col.green = get_light((st.color >> 8) & 0xFF,
				(end.color >> 8) & 0xFF, col.percentage);
		col.blue = get_light(st.color & 0xFF,
				end.color & 0xFF, col.percentage);
	}
	else
	{
		col.red = get_light((end.color >> 16) & 0xFF,
				(st.color >> 16) & 0xFF, col.percentage);
		col.green = get_light((end.color >> 8) & 0xFF,
				(st.color >> 8) & 0xFF, col.percentage);
		col.blue = get_light(end.color & 0xFF,
				st.color & 0xFF, col.percentage);
	}
	return (col);
}

int	get_color(t_coord current, t_coord start, t_coord end, t_coord delta)
{
	t_color	color;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		color.percentage = percent(start.x, end.x1, current.x);
	else
		color.percentage = percent(start.y, end.y1, current.y);
	color = gradient(color, current, start, end);
	return ((color.red << 16) | (color.green << 8) | color.blue);
}
