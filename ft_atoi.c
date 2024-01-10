/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 09:38:50 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/23 13:29:38 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	out;
	int	i;

	while (ft_isspace(*str))
		++str;
	if ((*str == '+' || *str == '-') && *(str + 1) >= '0' && *(str + 1) <= '9')
		++str;
	out = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		out *= 10;
		out += str[i] - '0';
		++i;
	}
	if (*(str - 1) == '-')
		out *= -1;
	return (out);
}
