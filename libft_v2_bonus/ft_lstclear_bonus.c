/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:33:55 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/25 13:36:57 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node_ptr;

	//ft_lstiter(*lst, del);
	next_node_ptr = *lst;
	while (*lst != NULL)
	{
		del((*lst)->content);
		next_node_ptr = (*lst)->next;
		free(*lst);
		*lst = next_node_ptr;
	}
}
