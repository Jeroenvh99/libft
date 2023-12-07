/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:50:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 15:40:48 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (len)
		{
			--len;
			*(char *)(dst + len) = *(char *)(src + len);
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
