/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbonus_prueba.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:43:17 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/14 16:43:08 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>

#define RESET_COLOR	"\x1b[0m"
#define ROJO_T	"\x1b[31m"
#define VERDE_T	"\x1b[32m"
#define AZUL_T	"\x1b[34m"

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_del(void *ptr)
{
	ptr = 0;
}

//TESTS: lista 0 --> 1 --> 2 --> 3 --> (NULL)

int	main(void)
{
	//DECLARO NODOS
	t_list	*nodo4_ptr;
	t_list	*nodo3_ptr;
	t_list	*nodo2_ptr;
	t_list	*nodo1_ptr;
	t_list	*nodo0_ptr;
	//DECLARO PTR A LISTA Y LAST
	t_list	*list;
	t_list	*last;
	int		size;

		printf("\n---------- TEST FT_LSTNEW ----------\n");
	//CREO NODOS
	nodo4_ptr = ft_lstnew("4");
	nodo3_ptr = ft_lstnew("3");
	nodo2_ptr = ft_lstnew("2");
	nodo1_ptr = ft_lstnew("1");
	nodo0_ptr = ft_lstnew("0");
		printf(AZUL_T "------- Nodos 0, 1, 2, 3, 4 creados\n" RESET_COLOR);
	printf(VERDE_T "Los contenidos de los 5 nodos creados son: %s, %s, %s, %s y %s \n" RESET_COLOR, (char *)(nodo0_ptr->content), (char *)(nodo1_ptr->content), (char *)(nodo2_ptr->content), (char *)(nodo3_ptr->content), (char *)(nodo4_ptr->content));
	//GENERO MI LISTA
	
		printf("\n---------- TEST EN FT_LSTADD_FRONT ----------\n");

	// como añado por delante, mi nodo og va a ser el 3
	list = nodo3_ptr;
	ft_lstadd_front(&list, nodo2_ptr);
	ft_lstadd_front(&list, nodo1_ptr);
	ft_lstadd_front(&list, nodo0_ptr);
		printf(AZUL_T "------- Lista 0 --> 1 --> 2 --> 3 --> (NULL) creada\n" RESET_COLOR);

		printf("\n---------- TEST FT_LSTSIZE ----------\n");

	//CALCULO Y PRINTEO TAMAÑO LISTA
	// lstsize recibe la variable list y no &list para no poder mod list
	size = ft_lstsize(list);
	printf(VERDE_T "El tamaño de la lista creada es: %i.\n" RESET_COLOR, size);

		printf("\n---------- TEST FT_LSTLAST ----------\n");

	last = ft_lstlast(list);
	printf(VERDE_T "El último nodo de la lista contiene: %s.\n" RESET_COLOR, (char *)(last->content));

		printf("\n---------- TEST FT_LSTADD_BACK ----------\n");

	//MODIFICO LISTA
	ft_lstadd_back(&list, nodo4_ptr);
		printf(AZUL_T "------- Node4 añadido al final de la lista\n" RESET_COLOR);
		printf(AZUL_T "------- Lista modificada: 0 --> 1 --> 2 --> 3 --> 4 --> (NULL)\n" RESET_COLOR);
	size = ft_lstsize(list);
	printf(VERDE_T "El tamaño de la lista modificada es: %i.\n" RESET_COLOR, size);
	last = ft_lstlast(list);
	printf(VERDE_T "El último nodo de la lista contiene: %s.\n" RESET_COLOR, (char *)(last->content));

		printf("\n---------- TEST FT_LSTDELONE ----------\n");

	//////////////////////// PROBAR FT_LSTDELONE, FT_LSTITER
	ft_lstdelone(nodo4_ptr, &ft_del);
		printf(AZUL_T "------- ft_lstdelone aplicada a nodo4_ptr\n" RESET_COLOR);
	
	// if (nodo4_ptr->content != NULL)
	// 	printf("he entrado en el if!!!!!\n");
	// 	//printf(VERDE_T "Nodo3 contiene: %s.\n" RESET_COLOR, (char *)(nodo3_ptr->content));
	// else
	// 	printf(VERDE_T "Nodo4 no existe.\n" RESET_COLOR);

		printf("\n---------- TEST FT_LSTCLEAR ----------\n");
	
	nodo4_ptr = ft_lstnew("4");
	ft_lstadd_back(&list, nodo4_ptr);
		printf(AZUL_T "------- Lista de vuelta a como estaba sin delone\n" RESET_COLOR);


	ft_lstclear(&list, &ft_del);
	// if (list != NULL)
	// 	printf(VERDE_T "1º nodo contiene: %s.\n" RESET_COLOR, (char *)(list->content));
	// else
	// 	printf(VERDE_T "El puntero list no lleva a ningún lado.\n" RESET_COLOR);
	// if (nodo0_ptr && nodo1_ptr && nodo2_ptr && nodo3_ptr && nodo4_ptr)
	// 	printf(VERDE_T "Los contenidos de los 5 nodos creados son: %s, %s, %s, %s y %s \n" RESET_COLOR, (char *)(nodo0_ptr->content), (char *)(nodo1_ptr->content), (char *)(nodo2_ptr->content), (char *)(nodo3_ptr->content), (char *)(nodo4_ptr->content));
	// else
	// 	printf(VERDE_T "Los nodos no existen.\n" RESET_COLOR);

	return (0);
}

// ---------- FUNCIONES BONUS A TESTEAR ----------

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
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	*lst = new;
}
int		ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current_ptr;

	if (lst == NULL)
		return (0);
	current_ptr = lst;
	size = 0;
	while (current_ptr!= NULL)
	{
		/*printf("el content de mi nodo es: %s\n", (char *)(current_ptr->content));
		if (current_ptr->next)
			printf("el content de mi nodo sig debería ser: %s\n", 
				(char *)((current_ptr->next)->content));
		else
			printf("no existe el siguiente nodo \n");*/
		current_ptr = current_ptr->next;
		size++;
	}
	return (size);
}
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_ptr;
	size_t		i;

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
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_ptr;

	last_ptr = ft_lstlast(*lst);
	last_ptr->next = new;
}
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	//printf("he entrado a delone!!!!\n");
	(*del)(lst->content);
	free(lst);
}
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