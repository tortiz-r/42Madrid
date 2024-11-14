/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:33:55 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/14 16:15:57 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*previous_ptr;

	if (*lst != NULL)
	{
		(*del)((*lst)->content);
		previous_ptr = *lst;
		free(previous_ptr);
		lst = &((*lst)->next);
	}
	ft_lstclear(lst, del);
	*lst = NULL;
}

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*next_ptr;

// 	if (*lst != NULL)
// 	{
// 		(*del)((*lst)->content);
// 		next_ptr = (*lst)->next;
// 		free(*lst);
// 		lst = next_ptr;
// 	}
// 	ft_lstclear(lst, del);
// 	*lst = NULL;
// }
