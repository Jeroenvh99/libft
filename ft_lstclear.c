/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 10:12:25 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 14:37:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (*lst)
	{
		current = *lst;
		while (current)
		{
			temp = current->next;
			ft_lstdelone(current, del);
			current = temp;
		}
		*lst = NULL;
	}
}
