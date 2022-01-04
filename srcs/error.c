/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 06:08:32 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/04 11:42:00 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void	err_alloc(void)
{
	perror("Error: malloc() failed.");
	exit(EXIT_FAILURE);
}

void	err_open(void)
{
	perror("Error: open() failed.");
	exit(EXIT_FAILURE);
}

void	err_mlx(void *addr)
{
	free(addr);
	perror("ERROR: MLX instance failed.");
	exit(EXIT_FAILURE);
}
