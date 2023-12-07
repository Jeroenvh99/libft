/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:09:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/11 10:58:37 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<unistd.h>
#include<stdlib.h>

static int	getlength(unsigned int n, t_padding *padinfo)
{
	int	count;

	count = 0;
	if (padinfo->prec > -1)
		padinfo->padc = ' ';
	if (padinfo->prec == 0 && n == 0)
		return (0);
	while ((n / 10) > 0)
	{
		++count;
		n /= 10;
	}
	if (n < 10)
		++count;
	if (count < padinfo->prec)
		count = padinfo->prec;
	if (padinfo->padc == '0' && padinfo->prec < 1 && padinfo->width > count)
	{
		padinfo->prec += (padinfo->width - count);
		count = padinfo->width;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n, t_padding *padinfo)
{
	int		i;
	char	*c;

	i = getlength(n, padinfo);
	c = ft_calloc(i + 1, 1);
	if (!c)
		return (NULL);
	--i;
	while (n > 9)
	{
		c[i] = (n % 10) + '0';
		n /= 10;
		--i;
	}
	c[i] = n + '0';
	while (i > 0)
	{
		--i;
		c[i] = '0';
	}
	return (c);
}

static int	printpreformatting(int strlen, t_padding *padinfo)
{
	int		i;
	int		formlen;
	char	*form;

	formlen = 0;
	if (padinfo->width > -1 && padinfo->adj == 'r' && strlen < padinfo->width)
	{
		i = padinfo->width - strlen;
		form = ft_calloc(i + 1, 1);
		if (!form)
			return (-1);
		formlen = i;
		while (i > 0)
		{
			--i;
			form[i] = padinfo->padc;
		}
		write(1, form, formlen);
		free(form);
	}
	return (formlen);
}

static int	printpostformatting(int strlen, t_padding *padinfo)
{
	int		i;
	int		formlen;
	char	*form;

	formlen = 0;
	if (padinfo->width > -1 && padinfo->adj == 'l' && strlen < padinfo->width)
	{
		i = padinfo->width - strlen;
		form = ft_calloc(i + 1, 1);
		if (!form)
			return (-1);
		formlen = i;
		while (i > 0)
		{
			--i;
			form[i] = padinfo->padc;
		}
		write(1, form, formlen);
		free(form);
	}
	return (formlen);
}

int	ft_writestr(char *s, char type, t_padding *padinfo)
{
	int	len;
	int	preformlen;
	int	postformlen;

	if (!s)
		s = ft_strdup("(null)");
	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (type == 'c')
		len = 1;
	if (type == 's' && padinfo->prec > -1 && len > padinfo->prec)
		len = padinfo->prec;
	preformlen = printpreformatting(len, padinfo);
	write(1, s, len);
	if (type != 's' || ft_strnstr(s, "(null)", 6))
		free(s);
	if (preformlen == -1)
		return (-1);
	postformlen = printpostformatting(len, padinfo);
	if (postformlen == -1)
		return (-1);
	return (len + preformlen + postformlen);
}
