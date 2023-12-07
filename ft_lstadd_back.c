/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 09:28:23 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/01/09 13:38:03 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
		}
		else
		{
			tail = ft_lstlast(*lst);
			new->prev = tail;
			tail->next = new;
		}
	}
}
