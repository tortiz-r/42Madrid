/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:27:07 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/28 17:21:00 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

char	*get_next_line(int fd)
{
	static int	flag;

	flag = 0;
	printf("\n--->get_next_line<---\n");
	printf("La variable estática flag es: %i\n", flag);
	//leer línea, llamar a write_buffer hasta que tengamos un /n al final
	//usar una variable estática que sea rollo una flag?? 
	//si tenemos cosas después de un /n, quitarlas por detrás
	flag = write_buffer(fd, flag);

	if (flag != -1)
		return (NULL);
	return (NULL);
}

int	write_to_buffer(int fd, int flag)
{
	int			read_size;
	char		*buffer;
	t_list		*read_list;

	// CONTROLAR CÓMO ESTÁ LA FLAG
	if (buffer == NULL)
	{
		free(buffer); //AQUÍ DEBERÍA HACER UN FREE DE TODA LISTA***
		return (-1);
	}
	printf("\n--->read_line<---\n");
	printf("Buffer_size es: %i\n", BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	read_list->content = &buffer;
	read_size += ft_strlen((char *) buffer);
	printf("La string leída es: %s\n", buffer);
	if (read_size == BUFFER_SIZE)
	{
		flag ++;
		//flag = write_buffer(fd, flag);
		//DEBERÍA HACER ALGO PARA AÑADIR UN NODO AL FINAL SI ES NECESARIO
	}
	return (flag);
}

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

int	main(void)
{
	int		fd;
	char	*random;

	fd = open("leer.txt", O_RDONLY);
	random = get_next_line(fd);
	random = get_next_line(fd);
	printf("%i\n", *random);
	return (0);
}
