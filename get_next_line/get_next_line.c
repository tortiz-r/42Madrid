/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:27:07 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/10 19:29:02 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

#define RESET_COLOR	"\x1b[0m"
#define MAGENTA_T  "\x1b[35m"
#define ROJO_T	"\x1b[31m"
#define VERDE_T	"\x1b[32m"
#define AZUL_T	"\x1b[34m"


char	*get_next_line(int fd)
{
	static t_line_obj	line_obj = {0, 0, -1, 0, NULL, NULL, NULL};
	int					actual_fd;
	char				*buffer;
	char				*check_ptr;

	if (line_obj.read_status == -1)
	{
		actual_fd = fd;
		line_obj.fd = actual_fd;
		buffer = write_buffer(fd, &line_obj);
		if (buffer == NULL)
		{
			line_obj.read_status = 0;
			return (NULL); //TENDRÍA QUE FREE STRUCT Y POSIBLES SIG NODOS!!!
		}
			check_ptr = distrib_buffer(1, buffer, &line_obj);
		if (check_ptr == NULL)
			return (NULL); //FREE COSIS
	}
	while (line_obj.line_status != 1)
		line_obj.line_status = check_line(&line_obj);
	return (line_obj.l_compl);
}

char	*write_buffer(int fd, t_line_obj *line_utils)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE LA STRUCT ENTERA!!!!***
		return (NULL);
	}
	line_utils->bytes_read= read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

char	*distrib_buffer(int optn, char *buffer, t_line_obj *l_obj)
{
	int				len_buf;
	int				len_compl;
	int				len_rem;

	// len_buf = ft_linelen(buffer, '\0');
	len_buf = l_obj->bytes_read;
	len_compl = ft_linelen(buffer, '\n', len_buf);
	len_rem = len_buf - len_compl;
	// l_obj->l_compl = malloc(len_compl + 1);
	// if (l_obj->l_compl == NULL)
	// {
	// 	//HAY QUE LIBERAR COSIS
	// 	return (NULL);
	// }
	l_obj->l_compl = ft_linefusion(l_obj->l_compl, buffer, len_compl, l_obj);
	l_obj->l_rem = ft_linefusion(l_obj->l_rem, buffer+len_compl,len_rem,l_obj);
	if (optn == 1)
		free(buffer);
	return (l_obj->l_compl);
}

int	check_line(t_line_obj *line_obj)
{
	int	i;

	i = 0;
	if (line_obj->line_status == 1)
		free(line_obj->l_compl);
	if (line_obj->line_status == 0)
	{
		while (line_obj->l_compl[i] != '\n')
			i++;
		if (i == ft_linelen(line_obj->l_compl, 0, line_obj->bytes_read) - 1)
		{
			line_obj->line_status = 1;
			return (line_obj->line_status);
		}
	}
	//si LINE_STATUS == 1, elimino l_compl pq ya la he pasado antes
	//si LINE_STATUS == 0, es que me toca comprobar la línea l_compl 1º
	//busco si tiene un /n (no busco más alla que bytes_read o si == )
}

// char	*write_distrib_buffer(int fd, t_line_obj *line_obj)
// {
// 	char			*buffer;
// 	int				len_buf;
// 	int				len_compl;
// 	int				len_rem;

// 	buffer = malloc(BUFFER_SIZE);
// 	if (buffer == NULL)
// 	{
// 		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE LA STRUCT ENTERA!!!!***
// 		return (NULL);
// 	}
// 	read(fd, buffer, BUFFER_SIZE);
// 	len_buf = ft_linelen(buffer, '\0');
// 	len_compl = ft_linelen(buffer, '\n');
// 	len_rem = len_buf - len_compl;
// 	line_obj->l_compl = malloc(len_compl + 1);
// 	if (line_obj->l_compl == NULL)
// 	{
// 		//HAY QUE LIBERAR COSIS
// 		return (NULL);
// 	}
// 	line_obj->l_compl = ft_linefusion(line_obj->l_compl, buffer, len_compl);
// 	line_obj->l_rem = ft_linefusion(line_obj->l_rem, buffer+len_compl, len_rem);
// 	free(buffer);
// 	return (line_obj->l_compl);
// }

char	*ft_linefusion(char *line1, char *line2, int len, t_line_obj *line_obj)
{
	char	*line_result;
	int		i;
	int		j;
	int		line1_len;

	i = 0;
	j = 0;
	printf(AZUL_T"Me meto en linefusion!! :) \n"RESET_COLOR);
	// printf(VERDE_T"Line1 es:\n"MAGENTA_T"%s\n", line1);
	//printf(VERDE_T"Line2 es:\n"MAGENTA_T"%s\n", line2);
	line1_len = ft_linelen(line1, 0, line_obj->bytes_read);
	printf(VERDE_T"La variable line1_len es: %i\n", line1_len);
	printf(VERDE_T"La variable input len es: %i\n", len);
	line_result = malloc(line1_len + len + 1);
	printf("El malloc que he hecho es de %i\n", line1_len + len + 1);
	if (line_result == NULL)
		return (NULL);
	while (i < line1_len)
	{
		line_result[i] = line1[i];
		i++;
	}
	printf("hooooolaaaaaa\n");
	free(line1);
	while (i < line1_len + len && line2[j] != '\0')
	{
		line_result[i] = line2[j];
		i++;
		j++;
	}
	line_result[i + 1] = '\0';
	return (line_result);
}

int ft_linelen(char *str, int end, int str_len)
{
	int	size;
	int	flag;

	size = 0;
	flag = 0;
	printf(VERDE_T"me meto en ft_linelen\n");
	if (str == NULL)
		return (0);
	while (size < str_len && flag == 0)
	{
		if (str[size] == end)
			flag = 1;
		size++;
	}
	// if (flag == 1 && size < BUFFER_SIZE)
	// 	return (-1);
	// if (flag == 0 && size == 0)
	// 	return (-3);
	// if (flag == 0 && size < BUFFER_SIZE)
	// 	return (-2);
	return (size);
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
void	ft_lstclear_num(t_line_obj **lst, void (*del)(void*), size_t size)
{
	t_line_obj	*next_node_ptr;
	size_t	i_clear;

	next_node_ptr = *lst;
	i_clear = 0;
	while (*lst != NULL && i_clear < size)
	{
		del((*lst)->content);
		next_node_ptr = (*lst)->next;
		free(*lst);
		*lst = next_node_ptr;
		i_clear++;
	}
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
