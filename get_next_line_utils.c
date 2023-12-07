/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 09:40:58 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/09 11:08:18 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

int	gnl_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		++count;
		++s;
	}
	return (count);
}

static char	*extendmem(char *mem, int increment, int i, int prevsize)
{
	char	*newmem;

	newmem = ft_calloc(prevsize + increment + 1, sizeof(char));
	if (!newmem)
	{
		if (mem)
			free(mem);
		return (NULL);
	}
	while (i < prevsize)
	{
		newmem[i] = mem[i];
		++i;
	}
	newmem[prevsize + increment] = '\0';
	if (mem)
		free(mem);
	return (newmem);
}

int	copytomem(char **mem, char *src, int i, int len)
{
	int	memlen;

	memlen = gnl_strlen(*mem);
	*mem = extendmem(*mem, len, 0, memlen);
	if (!*mem)
		return (-2);
	while (src[i])
	{
		if (src[i] == '\n')
		{
			(*mem)[memlen + i] = src[i];
			(*mem)[memlen + i + 1] = '\0';
			return (i);
		}
		else
		{
			(*mem)[memlen + i] = src[i];
		}
		++i;
	}
	return (-1);
}

void	shiftmem(char *mem, int shiftlen)
{
	int	i;
	int	memlen;

	i = 0;
	memlen = gnl_strlen(mem);
	while (i < memlen + 1 - shiftlen)
	{
		mem[i] = mem[i + shiftlen];
		++i;
	}
}
