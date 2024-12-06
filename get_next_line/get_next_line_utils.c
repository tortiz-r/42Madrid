/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:28:31 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/06 21:13:43 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

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
//me devuelve -1 si no tiene \n y encima es más peq que buffer_size

int	ft_linelen(char *str, char end)
{
	int	size;

	size = 0;
	while (str[size] != end && str[size] != '\0')
		size++;
	if (size == 0 && size < BUFFER_SIZE)
		return (-1);
	else
		return (size);
}
