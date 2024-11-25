/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbonus_prueba.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:43:17 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/25 13:42:25 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>

#define RESET_COLOR	"\x1b[0m"
#define MAGENTA_T  "\x1b[35m"
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
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));


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
	//DECLARO PTR A LISTA, LAST Y TEST
	t_list	*list;
	t_list	*last;
	t_list	*test;
	int		size;
	int 	i;

	i = 0;
		printf("\n---------- TEST FT_LSTNEW ----------\n" RESET_COLOR);
	//CREO NODOS
	nodo4_ptr = ft_lstnew("4");
	nodo3_ptr = ft_lstnew("3");
	nodo2_ptr = ft_lstnew("2");
	nodo1_ptr = ft_lstnew("1");
	nodo0_ptr = ft_lstnew("0");
	printf(AZUL_T "------- Nodos 0, 1, 2, 3, 4 creados\n" RESET_COLOR);
	printf(VERDE_T "Los contenidos de los 5 nodos creados son: %s, %s, %s, %s y %s \n" RESET_COLOR, (char *)(nodo0_ptr->content), (char *)(nodo1_ptr->content), (char *)(nodo2_ptr->content), (char *)(nodo3_ptr->content), (char *)(nodo4_ptr->content));
		printf(MAGENTA_T "------- FT_LSTNEW SUCCESSFUL\n" RESET_COLOR);
	
	//GENERO MI LISTA
		printf("\n---------- TEST EN FT_LSTADD_FRONT ----------\n" RESET_COLOR);

	// como añado por delante, mi nodo og va a ser el 3
	list = nodo3_ptr;
	ft_lstadd_front(&list, nodo2_ptr);
	ft_lstadd_front(&list, nodo1_ptr);
	ft_lstadd_front(&list, nodo0_ptr);
	//IMPRIMIR LISTA
	test = list;
	printf(AZUL_T "------- Lista creada: ");
	while (test!= NULL)
	{
		printf("%s --> ", (char *)(test->content));
		if ((test->next) == NULL)
			printf("(NULL)\n" RESET_COLOR);
		test = test->next;
	}
		printf(MAGENTA_T "------- FT_LSTADD_FRONT SUCCESSFUL\n" RESET_COLOR);

		printf("\n---------- TEST FT_LSTSIZE ----------\n" RESET_COLOR);
	//PRINTEO TAMAÑO LISTA
	// lstsize recibe la variable list y no &list para no poder mod list
	printf(VERDE_T "El tamaño de la lista creada es: %i.\n" RESET_COLOR, ft_lstsize(list));
		printf(MAGENTA_T "------- FT_LSTSIZE SUCCESSFUL\n" RESET_COLOR);

		printf("\n---------- TEST FT_LSTLAST ----------\n"RESET_COLOR);
	last = ft_lstlast(list);
	printf(VERDE_T "El último nodo de la lista contiene: %s.\n" RESET_COLOR, (char *)(last->content));
		printf(MAGENTA_T "------- FT_LAST SUCCESSFUL\n" RESET_COLOR);

		printf("\n---------- TEST FT_LSTADD_BACK ----------\n" RESET_COLOR);
	ft_lstadd_back(&list, nodo4_ptr);
	printf(AZUL_T "------- Node4 añadido al final de la lista\n" RESET_COLOR);
	printf(AZUL_T "------- Lista modificada: ");
	test = list;
	while (test!= NULL)
	{
		printf("%s --> ", (char *)(test->content));
		if ((test->next) == NULL)
			printf("(NULL)\n" RESET_COLOR);
		test = test->next;
	}
	size = ft_lstsize(list);
	printf(VERDE_T "El tamaño de la lista modificada es: %i.\n" RESET_COLOR, size);
	if ((ft_lstlast(list)->next) == NULL)
		printf(MAGENTA_T "---------- FT_LSTADD_BACK SUCCESSFUL\n" RESET_COLOR);

		printf("\n---------- TEST FT_LSTDELONE ----------\n");
	ft_lstdelone(nodo4_ptr, &ft_del);
	printf(AZUL_T "------- ft_lstdelone aplicada a nodo4_ptr\n" RESET_COLOR);
	//IMPRIMIR LISTA
	if (list)
		printf("list existe y contenido es %s\n", (char *)(list->content));
	test = list;
	if (test->next)
		printf("test->next existe y contenido es %s\n", (char *)((test->next)->content));
	printf(AZUL_T "------- Lista: ");
	while (test!= NULL && i < (size_t)(size - 1))
	{
		printf("%s --> ", (char *)(test->content));
		if ((test->next) == NULL)
			printf("(NULL)\n" RESET_COLOR);
		test = test->next;
		i++;
	}
	printf(AZUL_T "(=> CORE DUMPED)\n(pq hemos delone node4)\n" RESET_COLOR);
		printf(MAGENTA_T "------- FT_LSTDELONE SUCCESSFUL\n" RESET_COLOR);
	
		printf("\n---------- TEST FT_LSTCLEAR ----------\n");
	//DEVUELVO LISTA A COMO ESTABA
	nodo4_ptr = ft_lstnew("4");
	nodo3_ptr->next = nodo4_ptr;
		printf(AZUL_T "------- Lista devuelta a como estaba sin delone\n" RESET_COLOR);
	//IMPRIMIR LISTA, APLICAR CLEAR
	test = list;
	printf(AZUL_T "------- Lista: ");
	while (test!= NULL)
	{
		printf("%s --> ", (char *)(test->content));
		if ((test->next) == NULL)
			printf("(NULL)\n" RESET_COLOR);
		test = test->next;
	}
	ft_lstclear(&list, &ft_del);
	printf("list => CORE DUMPED");
	//printf("list => %s\n", (char *)(list->content));
		printf(MAGENTA_T "------- FT_LSTCLEAR SUCCESSFUL\n" RESET_COLOR);

		printf("\n---------- TEST FT_LSTITER ----------\n");
	//CREAMOS LISTA DE NUEVO
	nodo4_ptr = ft_lstnew("4");
	nodo3_ptr = ft_lstnew("3");
	nodo2_ptr = ft_lstnew("2");
	nodo1_ptr = ft_lstnew("1");
	nodo0_ptr = ft_lstnew("0");
	list = nodo4_ptr;
	ft_lstadd_front(&list, nodo3_ptr);
	ft_lstadd_front(&list, nodo2_ptr);
	ft_lstadd_front(&list, nodo1_ptr);
	ft_lstadd_front(&list, nodo0_ptr);
	printf(AZUL_T "------- Lista creada de nuevo: ");
	test = list;
	while (test!= NULL)
	{
		printf("%s --> ", (char *)(test->content));
		if ((test->next) == NULL)
			printf("(NULL)\n" RESET_COLOR);
		test = test->next;
	}
	ft_lstiter(list, &ft_del);
		printf("list => CORE DUMPED\n");
		printf(MAGENTA_T "------- FT_LSTITER SUCCESSFUL\n" RESET_COLOR);

		printf("\n---------- TEST FT_LSTMAP ----------\n");
	//CREAMOS LISTA DE NUEVO
	nodo4_ptr = ft_lstnew("4");
	nodo3_ptr = ft_lstnew("3");
	nodo2_ptr = ft_lstnew("2");
	nodo1_ptr = ft_lstnew("1");
	nodo0_ptr = ft_lstnew("0");
	list = nodo4_ptr;
	ft_lstadd_front(&list, nodo3_ptr);
	ft_lstadd_front(&list, nodo2_ptr);
	ft_lstadd_front(&list, nodo1_ptr);
	ft_lstadd_front(&list, nodo0_ptr);
	printf(AZUL_T "------- Lista creada de nuevo: ");
	test = list;
	while (test!= NULL)
	{
		printf("%s --> ", (char *)(test->content));
		if ((test->next) == NULL)
			printf("(NULL)\n" RESET_COLOR);
		test = test->next;
	}
	

	return (0);
}

// //IMPRIMIR LISTA
	// test = list;
	// i = 0;
	// while (test!= NULL && i<6)
	// {
	// 	printf("el content de mi nodo es: %s\n", (char *)(test->content));
	// 	if (test->next)
	// 		printf("el content de mi nodo sig debería ser: %s\n", 
	// 			(char *)((test->next)->content));
	// 	else
	// 		printf("no existe el siguiente nodo \n");
	// 	test = test->next;
	// 	i++;
	// }

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
	size_t		size;

	if (lst == NULL)
		return (lst);
	current_ptr = lst;
	i = 1;
	size = (size_t)ft_lstsize(lst);
	while (i < size)
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
	(*del)(lst->content);
	free(lst);
}
// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*next_node_ptr;

// 	if (*lst != NULL)
// 	{
// 		//printf("El contenido del nodo es %s.\n", (char *)((*lst)->content));
// 		(*del)((*lst)->content);
// 		/*if (((*lst)->content) == NULL)
// 			printf("Contenido del nodo borrado.\n");*/
// 		next_node_ptr = (*lst)->next;
// 	}
// 	if (next_node_ptr != NULL)
// 	{
// 		//printf("El contenido del siguiente nodo, que es %s, lo paso de nuevo.\n", (char *)(next_node_ptr->content));
// 		ft_lstclear(&next_node_ptr, del);
// 	}
// 	free(*lst);
// }
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
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	**current_ptr;
	size_t	i;

	i = 0;
	current_ptr = &lst;
	if (lst != NULL)
	{
		(*current_ptr) = lst;
		while ((*current_ptr) != NULL)
		{
			(*f)((*current_ptr)->content);
			(*current_ptr) = (*current_ptr)->next;
			i++;
		}
	}
}
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_list_ptr;
	t_list	*node_ptr;
	t_list	*current_ptr;

	if (lst == NULL)
		return (NULL);
	result_list_ptr = ft_lstnew((*f)(lst->content));
	if (result_list_ptr == NULL)
		free(result_list_ptr);
	current_ptr = lst->next;
	while (current_ptr != NULL)
	{
		node_ptr = ft_lstnew((*f)(current_ptr->content));
		if (node_ptr == NULL)
		{
			ft_lstclear(&result_list_ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&result_list_ptr, node_ptr);
		current_ptr = current_ptr->next;		
	}
	return (result_list_ptr);
}