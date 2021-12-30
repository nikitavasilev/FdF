/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:11:38 by nvasilev          #+#    #+#             */
/*   Updated: 2021/12/30 04:36:47 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_sizeof_long(void)
{
	char	size;

	if (sizeof(long) == 8)
		size = 18;
	else
		size = 9;
	return (size);
}

static char	ft_long_overflow_checker(char count, char sign, char value)
{
	char	max_size;

	max_size = ft_sizeof_long();
	if (sign == 1)
	{
		if ((count == max_size && (value - '0') > 7) || count > max_size)
			return (-1);
	}
	else if (sign == -1)
	{
		if ((count == 18 && (value - '0') > 8) || count > max_size)
			return (0);
	}
	return (1);
}

static char	ft_add_numbers(const char *str, char sign, long *res)
{
	char	count;
	char	max_long_size;
	char	ret;

	count = 0;
	max_long_size = ft_sizeof_long();
	while (ft_isdigit(*str))
	{
		if (count >= max_long_size)
		{
			ret = ft_long_overflow_checker(count, sign, *str);
			if (ret != 1)
				return (ret);
		}
		*res = *res * 10 + (*str - '0');
		count++;
		str++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	res;
	char	sign;
	char	ret;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	ret = ft_add_numbers(str, sign, &res);
	if (ret == 1)
		return (res * sign);
	else
		return (ret);
}
