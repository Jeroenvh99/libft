/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 12:05:39 by jvan-hal      #+#    #+#                 */
/*   Updated: 2024/01/11 20:07:43 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checksign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		++(*str);
	}
	return (sign);
}

double	ft_atof(char *str)
{
	double	val;
	int		sign;
	int		significant;

	val = 0;
	sign = checksign(&str);
	significant = 0;
	while (*str && (ft_isdigit(*str) || *str == '.'))
	{
		if (*str != '.')
		{
			val = (val * 10) + (*str - '0');
			significant *= 10;
		}
		else if (*str == '.')
		{
			if (significant > 0)
				return (0);
			significant = 1;
		}
		++str;
	}
	if (val > 0 && significant > 0)
		val /= significant;
	return (val * sign);
}
