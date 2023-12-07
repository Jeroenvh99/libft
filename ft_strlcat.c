/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:51:55 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 14:20:47 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstsize < dstlen)
		return (dstsize + srclen);
	i = 0;
	dst += dstlen;
	while (src[i] && (dstlen + i) < dstsize)
	{
		*dst = src[i];
		++i;
		++dst;
	}
	if ((dstlen + i) == dstsize && dstlen < dstsize)
		--dst;
	*dst = '\0';
	return (srclen + dstlen);
}
