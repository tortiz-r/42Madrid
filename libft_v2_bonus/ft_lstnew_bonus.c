/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:43:17 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/10 18:32:12 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// #include<stdio.h>
// #include<unistd.h>
// int	main(void)
// {
// 	t_list	*nodo_prueba;
// 	char *contenido = "holi";
// 	nodo_prueba = ft_lstnew(contenido);
// 	printf("el contenido es: %s\n", (char *)(nodo_prueba->content));
// 	return (0);
// }
