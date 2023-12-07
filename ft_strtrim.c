/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:43:27 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/26 10:09:59 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

static int	getstart(const char *s, const char *set)
{
	int	i;
	int	j;
	int	inset;

	i = 0;
	while (s[i])
	{
		j = 0;
		inset = 0;
		while (!inset && set[j])
		{
			if (s[i] == set[j])
				inset = 1;
			++j;
		}
		if (!inset)
			break ;
		++i;
	}
	return (i);
}

static int	getlast(const char *s, const char *set)
{
	int	i;
	int	j;
	int	inset;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		j = 0;
		inset = 0;
		while (!inset && set[j])
		{
			if (s[i] == set[j])
				inset = 1;
			++j;
		}
		if (!inset)
			break ;
		--i;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	char	*c;

	i = getstart(s1, set);
	end = getlast(s1, set);
	if (end == -1)
		i = 0;
	return (ft_substr(s1, i, (end - i) + 1));
}
