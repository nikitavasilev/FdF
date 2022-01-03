/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 02:52:34 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/03 22:07:37 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	get_height_and_width(const char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (line)
		data->width = wdcounter(line, ' ');
	data->height = 0;
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_map(const char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	get_height_and_width(file_name, data);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->z_matrix)
		err_alloc();
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width));
		if (!data->z_matrix[i])
			err_alloc();
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i++], line);
		free(line);
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
