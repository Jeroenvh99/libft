/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 18:57:57 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 14:39:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlelength;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	needlelength = ft_strlen(needle);
	while (*haystack && i < len && len - i > needlelength - 1)
	{
		if (!ft_strncmp(haystack, needle, needlelength))
			return ((char *)haystack);
		++i;
		++haystack;
	}
	return (NULL);
}
