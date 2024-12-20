/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:49:07 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/14 15:11:39 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_ptr;
	size_t	i;

	if (lst == NULL)
		return (lst);
	current_ptr = lst;
	i = 1;
	while (i < (size_t)ft_lstsize(lst))
	{
		current_ptr = current_ptr->next;
		i++;
	}
	return (current_ptr);
}
