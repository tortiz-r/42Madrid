/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:13:34 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/25 13:42:28 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_list_ptr;
	t_list	*node_ptr;
	t_list	*current_ptr;

	if (lst == NULL)
		return (NULL);
	result_list_ptr = ft_lstnew((*f)(lst->content));
	if (result_list_ptr == NULL)
		free(result_list_ptr);
	current_ptr = lst->next;
	while (current_ptr != NULL)
	{
		node_ptr = ft_lstnew((*f)(current_ptr->content));
		if (node_ptr == NULL)
		{
			ft_lstclear(&result_list_ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&result_list_ptr, node_ptr);
		current_ptr = current_ptr->next;		
	}
	return (result_list_ptr);
}
