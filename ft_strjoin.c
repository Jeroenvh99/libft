/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:42:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 14:39:09 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*c;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	c = malloc(len1 + len2 + 1);
	if (!c)
		return (NULL);
	while (*s1)
	{
		*c = *s1;
		++c;
		++s1;
	}
	while (*s2)
	{
		*c = *s2;
		++c;
		++s2;
	}
	*c = '\0';
	return (c - (len1 + len2));
}
