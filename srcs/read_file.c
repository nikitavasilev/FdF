/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 02:52:34 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/29 06:24:05 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_wdcounter(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

void	get_height_and_width(const char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		height;

	line = NULL;
	fd = open(file_name, O_RDONLY);
	height = 0;
	if ((line = get_next_line(fd)))
	{
		data->width = ft_wdcounter(line, ' ');
		height++;
		free(line);
	}
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	data->height = height;
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
	data->zoom = MIN((WIDTH - MENU_WIDTH) / data->width / 2, HEIGHT / data->height / 2);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
