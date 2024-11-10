/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:48:15 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/10 18:54:26 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*test;

	if (lst == NULL)
		return (0);
	test = NULL;
	test->next = lst;
	size = 1;
	while (test->next != NULL)
	{
		test = test->next;
		size++;
	}
	return (size);
}

#include<stdio.h>
#include<unistd.h>

int	main(void)
{
	// t_list	*nodo3;
	// t_list	*nodo2;
	// t_list	*nodo1;

	// t_list *nodo3 {
	// 	void	*content;
	// 	t_list	*next;
	// }{};
	
	t_list *nodo3 = {"TRES", NULL};
	t_list *nodo2 = {"DOS", &nodo3};
	t_list *nodo1 = {"TRES", &nodo2};
	// nodo3->content = "TRES";
	// nodo3->next = NULL;
	// nodo2->content = "DOS";
	// nodo2->next = nodo3;
	// nodo1->content = "UNO";
	// nodo1->next = nodo2;
	printf("el tamaño de la lista es: %i./n", ft_lstsize(nodo1));
	return (0);
}