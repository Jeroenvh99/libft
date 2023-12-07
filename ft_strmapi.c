/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:46:05 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 14:39:25 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*c;

	c = malloc(ft_strlen(s) + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (s[i])
	{
		c[i] = (*f)(i, s[i]);
		++i;
	}
	c[i] = '\0';
	return (c);
}
