// void	ft_lstclear_num(t_list **lst, size_t size)
// {
// 	t_list	*next_node_ptr;
// 	size_t	i_clear;

// 	next_node_ptr = *lst;
// 	i_clear = 0;
// 	while (*lst != NULL && i_clear < size)
// 	{
// 		free((*lst)->content);
// 		next_node_ptr = (*lst)->next;
// 		free(*lst);
// 		*lst = next_node_ptr;
// 		i_clear++;
// 	}
// }

/*
char	*write_buffer(int fd, int write_buffer_calls, t_list **read_list)
{
	char		*buffer;
	t_list		*nodo;

	buffer = malloc(BUFFER_SIZE);
	// CONTROLAR CÓMO ESTÁ LA write_buffer_calls??
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE TODA LISTA!!!!***
		return (-1);
	}
		printf(AZUL_T"--->read_line<---\n");
		printf(MAGENTA_T"Buffer_size es: %i\n" RESET_COLOR, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	nodo = ft_lstnew(buffer);
	if (read_list == NULL)
		*read_list = nodo;
	else
		ft_lstadd_back(read_list, nodo);
	// read_size += strlen((char *) buffer);
	printf(VERDE_T"La string leída es: %s\n"RESET_COLOR, buffer);
	write_buffer_calls++;
	if (read_size == BUFFER_SIZE)//!!! gestión de si he llegado al final de todo
	{
		flag ++;
		//flag = write_buffer(fd, flag);
		//DEBERÍA HACER ALGO PARA AÑADIR UN NODO AL FINAL SI ES NECESARIO
	}
	return (flag);
	// 	//DEBERÍA HACER ALGO PARA AÑADIR UN NODO AL FINAL SI ES NECESARIO
	return (write_buffer_calls);
}*/






// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*result_list;
// 	t_list	*new_node_ptr;
// 	t_list	*current_ptr_lst;

// 	if (lst == NULL)
// 		return (NULL);
// 	result_list = ft_lstnew(NULL);
// 	if (result_list == NULL)
// 		return (NULL);
// 	else
// 		result_list->content = (*f)(lst->content);
// 	current_ptr_lst = lst->next;
// 	while (current_ptr_lst != NULL && result_list != NULL)
// 	{
// 		new_node_ptr = ft_lstnew(NULL);
// 		if (new_node_ptr == NULL)
// 			ft_lstclear_num(&result_list, del, ft_lstsize(result_list));
// 		else
// 		{
// 			new_node_ptr->content = f(current_ptr_lst->content);
// 			ft_lstadd_back(&result_list, new_node_ptr);
// 			current_ptr_lst = current_ptr_lst->next;
// 		}
// 	}
// 	return (result_list);
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	(*del)(lst->content);
// 	free(lst);
// }


// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = (*lst);
// 	*lst = new;
// }


// t_list	*ft_lstlast(t_list *lst)
// {
// 	t_list	*current_ptr;
// 	size_t	i;

// 	if (lst == NULL)
// 		return (lst);
// 	current_ptr = lst;
// 	i = 1;
// 	while (i < (size_t)ft_lstsize(lst))
// 	{
// 		current_ptr = current_ptr->next;
// 		i++;
// 	}
// 	return (current_ptr);
// }


// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	t_list	**current_ptr;
// 	size_t	i;

// 	i = 0;
// 	current_ptr = &lst;
// 	if (lst != NULL)
// 	{
// 		(*current_ptr) = lst;
// 		while ((*current_ptr) != NULL)
// 		{
// 			(*f)((*current_ptr)->content);
// 			(*current_ptr) = (*current_ptr)->next;
// 			i++;
// 		}
// 	}
// }