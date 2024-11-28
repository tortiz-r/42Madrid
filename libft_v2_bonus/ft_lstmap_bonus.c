/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:13:34 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/28 16:14:59 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_map(t_list **lst, void (*del)(void*), size_t size);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_list;
	t_list	*new_node_ptr;
	t_list	*current_ptr_lst;

	if (lst == NULL)
		return (NULL);
	result_list = ft_lstnew(NULL);
	if (result_list == NULL)
		return (NULL);
	else
		result_list->content = (*f)(lst->content);
	current_ptr_lst = lst->next;
	while (current_ptr_lst != NULL && result_list != NULL)
	{
		new_node_ptr = ft_lstnew(NULL);
		if (new_node_ptr == NULL)
			ft_lstclear_map(&result_list, del, ft_lstsize(result_list));
		else
		{
			new_node_ptr->content = f(current_ptr_lst->content);
			ft_lstadd_back(&result_list, new_node_ptr);
			current_ptr_lst = current_ptr_lst->next;
		}
	}
	return (result_list);
}

void	ft_lstclear_map(t_list **lst, void (*del)(void*), size_t size)
{
	t_list	*next_node_ptr;
	size_t	i_clear;

	next_node_ptr = *lst;
	i_clear = 0;
	while (i_clear < size)
	{
		del((*lst)->content);
		next_node_ptr = (*lst)->next;
		free(*lst);
		*lst = next_node_ptr;
		i_clear++;
	}
}
