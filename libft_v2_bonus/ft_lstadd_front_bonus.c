/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:44:27 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/10 20:54:49 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	*lst = new;
}

#include<stdio.h>
#include<unistd.h>

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

int	main(void)
{
	t_list	*nodo2_ptr;
	t_list	*nodo1_ptr;
	t_list	*nodo0_ptr;
	t_list	*nodoNeg1_ptr;
	t_list	*current_ptr;
	t_list	*list;
	int		size;

	nodo2_ptr = ft_lstnew("dos");
	nodo1_ptr = ft_lstnew("uno");
	nodo0_ptr = ft_lstnew("0");
	nodoNeg1_ptr = ft_lstnew("-1");
	list = nodo2_ptr;

	ft_lstadd_front(&list, nodo1_ptr);
	ft_lstadd_front(&list, nodo0_ptr);
	ft_lstadd_front(&list, nodoNeg1_ptr);

	current_ptr = list;
	size = 0;
	while (current_ptr != NULL)
	{
		printf("el content de mi nodo es: %s\n", (char *)(current_ptr->content));
		if (current_ptr->next)
			printf("el content de mi nodo sig debería ser: %s\n", (char *)((current_ptr->next)->content));
		else
			printf("no existe el siguiente nodo \n");
		current_ptr = current_ptr->next;
		size++;
		printf("tamaño actual: %i\n", size);
	}
	printf("el tamaño de la lista es: %i\n", size);
	return (0);
}


void	ft_lstadd_back_raro(t_list **last, t_list *new)
{
	(*last)->next = new;
	new->next = NULL;
}

// ft_initialize(A)
// {
// 	*A
// }

// //test_ptr = ft_lstnew("");
// 	test_ptr->next = nodo1_ptr;
// 	size = 0;
// 	while (test_ptr->next != NULL)
// 	{
// 		printf("el content de mi nodo og es: %s\n", (char *)(test_ptr->content));
// 		printf("el content de mi nodo nuevo debería ser: %s\n", (char *)((test_ptr->next)->content));
// 		test_ptr->next = (test_ptr->next)->next;
// 		printf("el content de mi nodo nuevo es: %s\n", (char *)(test_ptr->content));
// 		size++;
// 		printf("tamaño actual: %i\n", size);
// 	}
// 	printf("el tamaño de la lista es: %i\n", size);
// 	return (0);