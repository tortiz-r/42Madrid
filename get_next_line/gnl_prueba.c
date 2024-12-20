/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_prueba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:01:18 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/19 18:42:35 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include <sys/stat.h>
# include <fcntl.h>

#define RESET_COLOR	"\x1b[0m"
#define MAGENTA_T  "\x1b[35m"
#define ROJO_T	"\x1b[31m"
#define VERDE_T	"\x1b[32m"
#define AZUL_T	"\x1b[34m"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 80
#endif

int	main(void)
{
	// t_list 		*read_node;
	// t_list		*current_ptr;
	// t_list		*temp_node_ptr;
	int			i;
	int			fd;
	char	*result;

	i = 0;
	fd = open("read_txt_short.txt", O_RDONLY);
	// read_node = NULL;
	while (i < 1)
	{
		result = get_next_line(fd);
		printf("La string result es:\n%s\n", result);
		i++;
	}
	// while (i <= 9)
	// {
	// 	printf(AZUL_T"--->read_line<---\n"RESET_COLOR);
	// 	temp_node_ptr = ft_lstnew(write_buffer(fd));

	// 	printf(VERDE_T"La string leída es:\n"MAGENTA_T"%s\n"RESET_COLOR, (char *)(temp_node_ptr->content));
	// 	printf(VERDE_T"El linelen del buffer corresp es: %i\n", ft_linelen((char *)(temp_node_ptr->content), '\n'));
	// 	printf(VERDE_T"El tamaño del buffer corresp es: %i\n"RESET_COLOR, ft_size(2, (char *)(temp_node_ptr->content), '\n'));

	// 	ft_lstadd_back(&read_node, temp_node_ptr);
	// 	i++;
	// }

	// 	printf("------- Imprimo los contenidos de la lista\n" RESET_COLOR);
	// current_ptr = read_node;
	// while (current_ptr != NULL)
	// {
	// 	printf(VERDE_T"El nodo contiene:\n"MAGENTA_T"%s\n"RESET_COLOR, (char *)current_ptr->content);
	// 	current_ptr = current_ptr->next;
	// }
	return (0);
}

/*------------------------- FUNCIONES A TESTEAR ---------------------------*/
char	*get_next_line(int fd)
{
	static t_line_obj	line_obj = {0, -1, 0, 1, 0, NULL, NULL, NULL};
	char				*buffer;
	char				*check_malloc;

	line_obj.fd = fd;
	if (line_obj.l_compl == 0  && line_obj.c_status == 1)
	{
		free(line_obj.l_compl);
		line_obj.f_status = -1;
	}
	if (line_obj.f_status == -1)
		return (NULL);
	while (line_obj.l_status == 0)
	{
		if (line_obj.l_rem == NULL) //si l_rem está vacía
		{
			if (line_obj.f_status == 0)
				return (line_obj.l_compl);
	printf("------- Llamamos a write_buffer 1 vez\n" RESET_COLOR);
			buffer = write_buffer(fd, &line_obj);
			if (buffer == NULL)
			{
				line_obj.f_status = -1;
				return (NULL); //TENDRÍA QUE FREE STRUCT Y POSIBLES SIG NODOS!!!
			}
		}
	printf("------- Llamamos a distrib_buffer con buffer:\n" RESET_COLOR);
	printf(VERDE_T"%s\n"RESET_COLOR, buffer);
		check_malloc = distrib_buffer(1, buffer, &line_obj);
	printf(VERDE_T"Line_obj.l_complete es:\n"MAGENTA_T"%s\n"RESET_COLOR, line_obj.l_compl);
	printf(VERDE_T"tamaño de string: %d\n"RESET_COLOR, ft_linelen(line_obj.l_compl, '\0', 30));
	printf(VERDE_T"Line_obj.l_remainder es:\n"MAGENTA_T"%s\n"RESET_COLOR, line_obj.l_rem);
	printf(VERDE_T"tamaño de string: %d\n"RESET_COLOR, ft_linelen(line_obj.l_rem, '\0', 53));
		if (check_malloc == NULL)
			return (NULL); //FREE COSIS
		if (check_line(&line_obj) != 1)
			printf(VERDE_T"Check_line da 0\n"RESET_COLOR);
	}
	return (line_obj.l_compl);
}

//lee el contenido de fd (buffer_size) y lo escribe en *buffer
char	*write_buffer(int fd, t_line_obj *line_utils)
{
	printf(AZUL_T"--->WRITE_BUFFER<---\n"RESET_COLOR);
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE LA STRUCT ENTERA!!!!***
		return (NULL);
	}
	line_utils->bytes_read= read(fd, buffer, BUFFER_SIZE);
	printf(VERDE_T"bytes_read = %i\n"RESET_COLOR, line_utils->bytes_read);
	return (buffer);
}
char	*distrib_buffer(int optn, char *buffer, t_line_obj *l_obj)
{
	printf(AZUL_T"--->DISTRIB__BUFFER<---\n"RESET_COLOR);
	int				len_buf;
	int				len_compl;
	int				len_rem;

	len_buf = l_obj->bytes_read;
	len_compl = ft_linelen(buffer, '\n', len_buf);
	len_rem = len_buf - len_compl;
	printf(AZUL_T"-----fusiono en l_compl\n"RESET_COLOR);
	l_obj->l_compl = ft_linefusion(l_obj->l_compl, buffer, len_compl);
	printf(AZUL_T"-----fusiono en l_rem\n"RESET_COLOR);
	l_obj->l_rem = ft_linefusion(l_obj->l_rem, buffer+len_compl,len_rem);
	if (optn == 1)
		free(buffer);
	return (l_obj->l_compl);
}
//si l_status == 1, elimino l_compl pq ya la he pasado antes
//si l_status == 0, es que me toca comprobar la línea l_compl 1º
//busco si tiene un /n (no busco más alla que bytes_read o si == )
int	check_line(t_line_obj *line_obj)
{
	printf(AZUL_T"--->CHECK_LINE<---\n"RESET_COLOR);
	int	i;

	i = 0;
	if (line_obj->l_status == 1)
		free(line_obj->l_compl);
	if (line_obj->l_status == 0)
	{
		while (*(line_obj->l_compl + i) != '\n')
			i++;
		printf("el valor de i es %i\n", i);
		printf("el valor de  len_l_compl -1 es %i\n", (ft_linelen(line_obj->l_compl, 0, line_obj->bytes_read) - 1));
		if (i + 1 == ft_linelen(line_obj->l_compl, 0, line_obj->bytes_read) - 1)
		{
			line_obj->l_status = 1;
		}
	}
	return (line_obj->l_status);

}
//cocatena line2len chars de line2 en line1
//haciendo malloc para result y free a line1
//line2len es el numchar a fusionar (linelen(end, bytes_read))
char	*ft_linefusion(char *line1, char *line2, int line2_len)
{
	printf(AZUL_T"--->LINE_FUSION<---\n"RESET_COLOR);
	char	*line_result;
	int		i;
	int		j;
	int		line1_len;

	i = 0;
	j = 0;
	printf(VERDE_T"Line1 es:\n"MAGENTA_T"%s\n", line1);
	printf(VERDE_T"Line2 es:\n"MAGENTA_T"%s\n", line2);
	line1_len = ft_linelen(line1, '\0', -1);
	printf(VERDE_T"La variable line1_len es: %i\n", line1_len);
	printf(VERDE_T"La variable input len es: %i\n", line2_len);
	line_result = malloc(line1_len + line2_len - 1 + 1);
	printf("El malloc que he hecho es de %i\n", line1_len + line2_len + 1);
	if (line_result == NULL)
		return (NULL);
	while (i < line1_len)
	{
		line_result[i] = line1[i];
		i++;
	}
	free(line1);
	while (i < line1_len + line2_len && line2[j] != '\0')
	{
		line_result[i] = line2[j];
		i++;
		j++;
	}
	line_result[i + 1] = '\0';
	return (line_result);
}

//estoy haciendo lengths, no iterador!! "hola" da 5!!!
int ft_linelen(char *str, int end, int str_len)
{
	//printf(AZUL_T"--->LINE_LEN<---\n"RESET_COLOR);
	int	size;
	int	flag;

	size = 0; 
	flag = 0;
	if (str == NULL)
		return (0);
	if (str_len < 0)
	{
		while (str[size] != end && str[size] != '\0')
		size++;
	}
	else
	{
		while (size < str_len && str[size] != '\0' && flag == 0)
		{
			if (str[size] == end)
				flag = 1;
			size++;
		}
	}
	return (size);
}
/*
t_list	*write_to_buffer(int fd, t_list **read_node)
{
	// int			read_size;
	char		*buffer;
	t_list		*nodo;

	buffer = malloc(BUFFER_SIZE);
	// CONTROLAR CÓMO ESTÁ LA write_buffer_calls
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE TODA LISTA***
		return (NULL);
	}
	printf(AZUL_T"--->read_line<---\n"RESET_COLOR);
	// printf(MAGENTA_T"Buffer_size es: %i\n" RESET_COLOR, BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	nodo = ft_lstnew(buffer);
	if (*read_node == NULL)
		*read_node = nodo;
	else
		ft_lstadd_back(read_node, nodo);
	// read_size += strlen((char *) buffer);
	if (*buffer == 0)
		printf("ATENCION!!!!!\n");
	printf(VERDE_T"La string leída es:\n"MAGENTA_T"%s\n"RESET_COLOR, buffer);
	printf(VERDE_T"El linelen del buffer corresp es: %i\n", ft_linelen(buffer, '\n'));
	printf(VERDE_T"El tamaño del buffer corresp es: %i\n"RESET_COLOR, ft_size(2, buffer, '\n'));
	// if (read_size == BUFFER_SIZE)
	// {
	// 	flag ++;
	// 	//esto no tiene sentido, no??
	// 	//flag = write_buffer(fd, flag);
	// 	//DEBERÍA HACER ALGO PARA AÑADIR UN NODO AL FINAL SI ES NECESARIO
	// }
	return (*read_node);
}*/




/*------------------------- FUNCIONES LST ---------------------------*/

t_line_obj	*ft_lstnew(int fd, int c_status, int l_status)
{
	t_line_obj	*node;

	node = malloc(sizeof(t_line_obj));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->c_status = c_status;
	node->l_status = l_status;
	node->l_compl = NULL;
	node->l_compl = NULL;
	node->next = NULL;
	return (node);
}

int		ft_lstsize(t_line_obj *lst)
{
	int		size;
	t_line_obj	*current_ptr;

	if (lst == NULL)
		return (0);
	current_ptr = lst;
	size = 0;
	while (current_ptr!= NULL)
	{
		current_ptr = current_ptr->next;
		size++;
	}
	return (size);
}

void	ft_lstadd_back(t_line_obj *lst, t_line_obj *new_node)
{
	t_line_obj	*last_ptr;
	int				i;

	if (lst != NULL && new_node != NULL)
	{
		if (lst == NULL)
			lst = new_node;
		else
		{
			last_ptr = lst;
			i = 1;
			while (i < ft_lstsize(lst))
			{
				last_ptr = last_ptr->next;
				i++;
			}
			last_ptr->next = new_node;
		}
	}
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str_result;

// 	str_result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (str_result == NULL)
// 		return (NULL);
// 	str_result = ft_memcpy(str_result, s1, ft_strlen(s1));
// 	ft_strlcpy((str_result + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
// 	return (str_result);
// }
