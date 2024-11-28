/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:28:31 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/28 17:14:50 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//basicamente aquí meto las funciones de la libft que vaya a necesitar
//por la norma solo puede haber un máximo de 5 funciones por archivo
//así que ft_strlen, ft_strjoin, ft_strchr, ft_strnchr, ft_substr

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current_ptr;

	if (lst == NULL)
		return (0);
	current_ptr = lst;
	size = 0;
	while (current_ptr != NULL)
	{
		current_ptr = current_ptr->next;
		size++;
	}
	return (size);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_ptr;
	size_t	i;

	if (lst != NULL && new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_ptr = *lst;
			i = 1;
			while (i < (size_t)ft_lstsize(*lst))
			{
				last_ptr = last_ptr->next;
				i++;
			}
			last_ptr->next = new;
		}
	}
}

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
			ft_lstclear_num(&result_list, del, ft_lstsize(result_list));
		else
		{
			new_node_ptr->content = f(current_ptr_lst->content);
			ft_lstadd_back(&result_list, new_node_ptr);
			current_ptr_lst = current_ptr_lst->next;
		}
	}
	return (result_list);
}

void	ft_lstclear_num(t_list **lst, void (*del)(void*), size_t size)
{
	t_list	*next_node_ptr;
	size_t	i_clear;

	next_node_ptr = *lst;
	i_clear = 0;
	while (*lst != NULL && i_clear < size)
	{
		del((*lst)->content);
		next_node_ptr = (*lst)->next;
		free(*lst);
		*lst = next_node_ptr;
		i_clear++;
	}
}
// size_t	ft_strlen(const char *s)
// {
// 	unsigned long	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }


// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	(*del)(lst->content);
// 	free(lst);
// }


// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = (*lst);
// 	*lst = new;
// }


// t_list	*ft_lstlast(t_list *lst)
// {
// 	t_list	*current_ptr;
// 	size_t	i;

// 	if (lst == NULL)
// 		return (lst);
// 	current_ptr = lst;
// 	i = 1;
// 	while (i < (size_t)ft_lstsize(lst))
// 	{
// 		current_ptr = current_ptr->next;
// 		i++;
// 	}
// 	return (current_ptr);
// }


// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	t_list	**current_ptr;
// 	size_t	i;

// 	i = 0;
// 	current_ptr = &lst;
// 	if (lst != NULL)
// 	{
// 		(*current_ptr) = lst;
// 		while ((*current_ptr) != NULL)
// 		{
// 			(*f)((*current_ptr)->content);
// 			(*current_ptr) = (*current_ptr)->next;
// 			i++;
// 		}
// 	}
// }