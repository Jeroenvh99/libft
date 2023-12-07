/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:44:31 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/03/23 11:57:47 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

static int	getarrlength(const char *s, char dlm)
{
	int		count;
	char	prevc;

	count = 0;
	prevc = dlm;
	while (*s)
	{
		if (*s == dlm && prevc != dlm)
			++count;
		prevc = *s;
		++s;
	}
	if (prevc != dlm)
		++count;
	return (count);
}

static char	*getsplit(const char **s, char dlm)
{
	int		i;
	char	prevc;
	char	*split;

	i = 0;
	prevc = dlm;
	while (i == 0 || s[0][i - 1])
	{
		if ((s[0][i] == dlm && prevc != dlm) || (!(s[0][i])
			&& prevc != dlm))
		{
			split = ft_substr(s[0], 0, i);
			if (!split)
				return (NULL);
			s[0] += i;
			return (split);
		}
		prevc = s[0][i];
		++i;
	}
	return (NULL);
}

static void	freearr(char **arr, int i)
{
	--i;
	while (i >= 0)
	{
		free(arr[i]);
		arr[i] = NULL;
		--i;
	}
	free(arr);
	arr = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		arrsize;
	int		i;
	char	**arr;

	if (!s)
		return (NULL);
	arrsize = getarrlength(s, c) + 1;
	arr = ft_calloc(arrsize, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < arrsize - 1)
	{
		while (*s == c)
			++s;
		arr[i] = getsplit(&s, c);
		if (!arr[i])
		{
			freearr(arr, i);
			return (NULL);
		}
		++i;
	}
	return (arr);
}
