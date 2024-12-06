/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:27:07 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/06 22:17:17 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

char	*get_next_line(int fd)
{
	t_list		*lines_read;
	t_list		*temp_ptr;
	char		*buffer;
	static int	gnl_calls = 0;

	if (gnl_calls == 0)
	{
		lines_read = ft_lstnew(NULL);
		buffer = write_buffer(fd);
		temp_ptr = distrib_buffer_in_nodes(buffer, &lines_read);
		
		//////crear todo desde cero
	}
	else if (lines_read->content == NULL && gnl_calls != 0)
		return (NULL); //no hay nada más que leer
	if (ft_lstsize(lines_read) > 2)
	{
		temp_ptr = lines_read->next;
		ft_lstclear_num(&lines_read, 1); //eliminar 1º nodo
		lines_read = temp_ptr;
		return (lines_read->content);
	}
	else if (ft_lstsize(lines_read) == 2)
		{
	//eliminar el primer nodo (linea devuelta antes) y mod lines_read_list
	/*cuando tenga \n\0 en buffer, creo otro nodo con null content.*/
			//miro si es NULL o no (atención al caso de no \n sí \0!!)
			//no:
				//write_buffer
				//scan cuantas \n tengo (atención al \0!!!!!!!)
				//meter cada trocito de buffer en su nodo adecuado y free(buffer)
				//atención, poner un \0 al final si no hay \n!!!!
			
		}

	gnl_calls++;
	return (lines_read->content);
}

char	*write_buffer(int fd)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE TODA LISTA!!!!***
		return (NULL);
	}
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

t_list	*distrib_buffer_in_nodes(char *buffer, t_list **list)
{
	char	*temp_buffer;
	t_list	*temp_node_ptr;

	temp_buffer = buffer;
	(*list)->content = temp_buffer;
	temp_node_ptr = ft_lstnew(NULL);
	if (temp_node_ptr == NULL)
	{
		//FREEEEEEEEEEEEEE
		return (NULL);
	}
	(*list)->next = temp_node_ptr;
	return (*list);
	//scan \n y demás (opción meter info de str en una struct???)
}

/*
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_result;

	str_result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_result == NULL)
		return (NULL);
	str_result = ft_memcpy(str_result, s1, ft_strlen(s1));
	ft_strlcpy((str_result + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (str_result);
}*/


/*
** FLAG:
0 == he leido /n o /0
-1 == algo ha ido mal
1,2,3,... == bien, = nº veces llamada write_buffer
*/
/* 
***Si hay que meter una linea en varios buffers pq no cabe
hay que asegurarse que liberamos toda la memoria que hayamos podido coger antes
*/

//size_t read(int fildes, void *buf, size_t nbyte);
// para compilar:
//cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 *.c *.h

// int	main(void)
// {
// 	int		fd;
// 	char	*random;

// 	fd = open("leer.txt", O_RDONLY);
// 	random = get_next_line(fd);
// 	random = get_next_line(fd);
// 	printf("%i\n", *random);
// 	return (0);
// }
