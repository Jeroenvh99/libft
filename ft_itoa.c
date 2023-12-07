/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 14:00:49 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/10 12:23:53 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

static int	getlength(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		++count;
		n *= -1;
	}
	while ((n / 10) > 0)
	{
		++count;
		n /= 10;
	}
	if (n < 10)
		++count;
	return (count);
}

static char	*getstr(long int n, int len)
{
	char	*c;

	c = malloc(len + 1);
	if (!c)
		return (NULL);
	if (n < 0)
	{
		*c = '-';
		n *= -1;
	}
	c += len;
	*c = '\0';
	--c;
	while (n > 9)
	{
		*c = (n % 10) + '0';
		n /= 10;
		--c;
	}
	*c = n + '0';
	if (*(c - 1) == '-')
		return (c - 1);
	return (c);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (getstr(n, getlength(n)));
}
