/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:28:31 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/10 17:54:31 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

t_line_obj	*ft_lstnew(int fd, int read_status, int line_status)
{
	t_line_obj	*node;

	node = malloc(sizeof(t_line_obj));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->read_status = read_status;
	node->line_status = line_status;
	node->l_compl = NULL;
	node->l_compl = NULL;
	node->next = NULL;
	return (node);
}

int		ft_lstsize(t_line_obj *lst)
{
	int		size;
	t_line_obj	*current_ptr;

	if (lst == NULL)
		return (0);
	current_ptr = lst;
	size = 0;
	while (current_ptr!= NULL)
	{
		current_ptr = current_ptr->next;
		size++;
	}
	return (size);
}

void	ft_lstadd_back(t_line_obj *lst, t_line_obj *new_node)
{
	t_line_obj	*last_ptr;
	int				i;

	if (lst != NULL && new_node != NULL)
	{
		if (lst == NULL)
			lst = new_node;
		else
		{
			last_ptr = lst;
			i = 1;
			while (i < ft_lstsize(lst))
			{
				last_ptr = last_ptr->next;
				i++;
			}
			last_ptr->next = new_node;
		}
	}
}

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char	*substr;

// 	if (ft_linelen(s, '\0') >= (start + len))
// 	{
// 		substr = malloc(len + 1);
// 		if (substr == NULL)
// 			return (NULL);
// 		ft_strlcpy(substr, (s + start), len + 1);
// 	}
// 	else
// 	{
// 		substr = malloc(ft_strlen(s) - start + 1);
// 		if (substr == NULL)
// 			return (NULL);
// 		ft_strlcpy(substr, (s + start), ft_strlen(s) - start + 1);
// 	}
// 	return (substr);
// }