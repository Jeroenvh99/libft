/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 12:05:39 by jvan-hal      #+#    #+#                 */
/*   Updated: 2024/01/10 12:10:40 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	double	val;
	int		significant;

	val = 0;
	significant = 0;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '.')
			break ;
		if (*str != '.')
		{
			val = (val * 10) + (*str - '0');
			if (significant > 0)
				significant *= 10;
		}
		else
		{
			if (significant > 0)
				return (0);
			significant = 1;
		}
		++str;
	}
	val /= significant;
	return (val);
}
