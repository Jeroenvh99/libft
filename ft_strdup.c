/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 09:40:21 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 14:38:59 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>
#include<errno.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*c;

	i = ft_strlen(s1);
	c = malloc(i + 1);
	if (!c)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (i >= 0)
	{
		c[i] = s1[i];
		--i;
	}
	return (c);
}
