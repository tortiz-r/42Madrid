/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:50:14 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/14 15:27:24 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// //otra opción que se podria hacer, no tiene que verr con lo q nos piden
// void	ft_lstadd_back_raro(t_list **last, t_list *new)
// {
// 	(*last)->next = new;
// 	new->next = NULL;
// }