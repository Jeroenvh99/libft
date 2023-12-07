/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:41:09 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/26 10:14:32 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*c;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
		len = 0;
	else if (start + len > srclen && srclen >= start)
		len = srclen - start;
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	i = 0;
	s += start;
	while (i < len)
	{
		c[i] = *s;
		++i;
		++s;
	}
	c[i] = '\0';
	return (c);
}
