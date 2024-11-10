/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus_prueba.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:43:17 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/10 18:20:52 by tortiz-r         ###   ########.fr       */
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

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*node_ptr;
// 	t_list	node;

// 	node_ptr = (t_list *)malloc(sizeof(t_list));
// 	if (node_ptr == NULL)
// 		return (NULL);
// 	node = *node_ptr;
// 	node.content = content;
// 	node.next = NULL;
// 	*node_ptr = node;

//ATENCIÓN PQ GESTIONAR POR ASIGNACIÓN POR VALORES ES CACA
//POR ESO USAMOS LA ->

// 	//return (&node);
// 	//node_ptr->content = content;
// 	//node_ptr->next = NULL;
// 	return (node_ptr);
// }

// int main(void){
// 	t_list	*node_ptr;
// 	t_list	node;

// 	node_ptr = (t_list *)malloc(sizeof(t_list));
// 	if (node_ptr == NULL)
// 		return (1);
// 	node = *node_ptr;
// 	printf("%i\n", &node == node_ptr);
// 	return (0);
// }