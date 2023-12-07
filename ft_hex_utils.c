/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:14:16 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/11 10:57:20 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	getlength(unsigned long int n, t_padding *padinfo)
{
	int	count;

	count = 0;
	if (padinfo->prec > -1)
		padinfo->padc = ' ';
	if (padinfo->prec == 0 && n == 0)
		return (0);
	if (padinfo->alt == 'y' && padinfo->padc == '0' && n > 0)
		padinfo->width -= 2;
	while ((n / 16) > 0)
	{
		++count;
		n /= 16;
	}
	if (n < 16)
		++count;
	if (count < padinfo->prec)
		count = padinfo->prec;
	if (padinfo->padc == '0' && padinfo->prec == -1 && padinfo->width > count)
	{
		padinfo->prec += (padinfo->width - count);
		count = padinfo->width;
	}
	return (count);
}

static char	gethexchar(int n, char type)
{
	if (n < 10)
	{
		return (n + '0');
	}
	else
	{
		if (type == 'x')
			return (n - 10 + 'a');
		else if (type == 'X')
			return (n - 10 + 'A');
	}
	return ('~');
}

char	*getstr_ptr(uintptr_t ptr, char type, t_padding *padinfo)
{
	int		i;
	char	*c;

	i = getlength(ptr, padinfo) + 2;
	c = ft_calloc(i + 1, 1);
	if (!c)
		return (NULL);
	--i;
	while (ptr >= 16)
	{
		c[i] = gethexchar((ptr % 16), type);
		ptr /= 16;
		--i;
	}
	c[i] = gethexchar((ptr % 16), type);
	--i;
	while (i > 1)
	{
		c[i] = '0';
		--i;
	}
	c[i] = type;
	--i;
	c[i] = '0';
	return (c);
}

char	*getstr_hex(long long int n, char type, t_padding *padinfo)
{
	int		i;
	char	*c;

	if (n < 0)
		n = ((2147483648 + n) * 2) - n;
	if (padinfo->alt == 'y' && n > 0)
		return (getstr_ptr(n, type, padinfo));
	i = getlength(n, padinfo);
	c = ft_calloc(i + 1, 1);
	if (!c)
		return (NULL);
	--i;
	while (n >= 16)
	{
		c[i] = gethexchar((n % 16), type);
		n /= 16;
		--i;
	}
	c[i] = gethexchar((n % 16), type);
	while (i > 0)
	{
		--i;
		c[i] = '0';
	}
	return (c);
}
