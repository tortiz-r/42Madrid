
char	*write_distrib_buffer(int fd, t_line_obj *line_obj)
{
	char			*buffer;
	int				len_buf;
	int				len_compl;
	int				len_rem;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE LA STRUCT ENTERA!!!!***
		return (NULL);
	}
	read(fd, buffer, BUFFER_SIZE);
	len_buf = ft_linelen(buffer, '\0');
	len_compl = ft_linelen(buffer, '\n');
	len_rem = len_buf - len_compl;
	line_obj->l_compl = malloc(len_compl + 1);
	if (line_obj->l_compl == NULL)
	{
		//HAY QUE LIBERAR COSIS
		return (NULL);
	}
	line_obj->l_compl = ft_linefusion(line_obj->l_compl, buffer, len_compl);
	line_obj->l_rem = ft_linefusion(line_obj->l_rem, buffer+len_compl, len_rem);
	free(buffer);
	return (line_obj->l_compl);
}


char	*distrib_buffer_in_strings(char *buf, t_line_obj *line_utils)
{
	// char			*temp_buf;
	int				len_buf;
	int				len_compl;
	int				len_rem;

	len_buf = ft_linelen(buf, '\0');
	len_compl = ft_linelen(buf, '\n');
	printf(VERDE_T"La variable len_buf es: %i\n", len_buf);
	printf(VERDE_T"La variable len_compl es: %i\n", len_compl);
	len_rem = len_buf - len_compl;
	printf(VERDE_T"La variable len_rem es: %i\n", len_rem);
	// line_utils->l_compl = malloc(len_compl + 1);
	// if (line_utils->l_compl == NULL)
	// {
	// 	//HAY QUE LIBERAR COSIS
	// 	return (NULL);
	// }
	line_utils->l_compl = ft_linefusion(line_utils->l_compl, buf, len_compl);
	line_utils->l_rem = ft_linefusion(line_utils->l_rem, buf+len_compl,len_rem);
	printf("pre-buf\n");
	free(buf);
	printf("post-buf\n");
	return (line_utils->l_compl);
}



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

// char	*write_buffer(int fd)
// {
// 	char	*buffer;

// 	buffer = malloc(BUFFER_SIZE);
// 	if (buffer == NULL)
// 	{
// 		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE LA STRUCT ENTERA!!!!***
// 		return (NULL);
// 	}
// 	read(fd, buffer, BUFFER_SIZE);
// 	return (buffer);
// }

/*
GNL
if (gnl_calls == 0)
	//HACER TODO DESDE CERO
else if (lines_read->content == NULL && gnl_calls != 0)
	// 	return (NULL); //no hay nada más que leer
	// if (ft_lstsize(lines_read) > 2)
	// {
	// 	temp_ptr = lines_read->next;
	// 	ft_lstclear_num(&lines_read, 1); //eliminar 1º nodo
	// 	lines_read = temp_ptr;
	// 	return (lines_read->content);
	// }
	// else if (ft_lstsize(lines_read) == 2)
	// 	{
	// //eliminar el primer nodo (linea devuelta antes) y mod lines_read_list
	// cuando tenga \n\0 en buffer, creo otro nodo con null content.
	// 		//miro si es NULL o no (atención al caso de no \n sí \0!!)
	// 		//no:
	// 			//write_buffer
	// 			//scan cuantas \n tengo (atención al \0!!!!!!!)
	// 			meter cada trocito de buffer en su nodo adecuado y free(buffer)
	// 			atención, poner un \0 al final si no hay \n!!!!
*/

/*EW CAMBIAR ESTO (hacer ft_lstsize y ft_linelen)
//en int 0 == '\0' y 10 = '\n'
//me devuelve -1 si no tiene \n y encima es más peq que buffer_size

int	ft_size(int inp, void *ptr, int end)
{
	int				len;
	t_line_utils	*current_ptr;

	len = 0;
	current_ptr = ptr;
	if (inp == 3)
	{
		while (current_ptr != NULL)
		{
			current_ptr = current_ptr->next;
			len++;
		}
	}
	if (inp == 1 || inp == 2)
	{
		while ((char *)(ptr + len) != end && (char *)(ptr + len) != (-2 + inp))
			len++;
	}
	if ((inp == 1 || inp == 2) && len == BUFFER_SIZE)
		return (-1);
	if ((inp == 1 || inp == 2) && len < BUFFER_SIZE)
		return (-2);
	return (len);
}*/

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


/************* Funciones lst que creo que no usaré ***************/

// void	ft_lstadd_back(t_line_obj *lst, t_line_obj *new_node)
// {
// 	t_line_obj	*last_ptr;
// 	int				i;

// 	if (lst != NULL && new_node != NULL)
// 	{
// 		if (lst == NULL)
// 			lst = new_node;
// 		else
// 		{
// 			last_ptr = lst;
// 			i = 1;
// 			while (i < ft_lstsize(lst))
// 			{
// 				last_ptr = last_ptr->next;
// 				i++;
// 			}
// 			last_ptr->next = new_node;
// 		}
// 	}
// }

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