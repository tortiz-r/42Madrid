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
//estoy haciendo lengths, no iterador!! "hola" da 5!!!
int ft_linelen(char *str, int end, int str_len)
{
	int	size;
	int	flag;

	size = 0; 
	flag = 0;
	if (str == NULL)
		return (0);
	if (str_len < 0)
	{
		while (str[size] != end && str[size] != '\0')
		size++;
	}
	else
	{
		while (size < str_len && str[size] != '\0' && flag == 0)
		{
			if (str[size] == end)
				flag = 1;
			size++;
		}
	}
	return (size);
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


/*
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_result;

	str_result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_result == NULL)
		return (NULL);
	str_result = ft_memcpy(str_result, s1, ft_strlen(s1));
	ft_strlcpy((str_result + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (str_result);
}*/

/*
void	ft_lstclear_num(t_line_obj **lst, void (*del)(void*), size_t size)
{
	t_line_obj	*next_node_ptr;
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
}*/