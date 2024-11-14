/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:48:51 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/14 15:22:15 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current_ptr;
	size_t	i;

	i = 0;
	if (lst != NULL)
	{
		current_ptr = lst;
		while (current_ptr != NULL)
		{
			(*f)(current_ptr->content);
			current_ptr = current_ptr->next;
			i++;
		}
	}
}
