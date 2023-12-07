/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:56:03 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 14:38:06 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{	
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		--n;
	}
	return (NULL);
}
