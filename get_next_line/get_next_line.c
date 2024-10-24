/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:27:07 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/10/24 20:29:59 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

char	*get_next_line(int fd)
{
	static int	read_pos;

	read_pos = 0;
	printf("\n--->get_next_line<---\n");
	printf("La variable estática read_pos es: %i\n", read_pos);
	read_line(fd, read_pos);
	if (read_pos != -1)
		return (NULL);
	return (NULL);
}

int	read_line(int fd, int read_pos)
{
	char	*buffer;

	buffer = malloc((size_t)BUFFER_SIZE);
	if (buffer == NULL)
	{
		free(buffer);
		return (-read_pos -1);
	}
	printf("\n--->read_line<---\n");
	printf("Buffer_size es: %i\n", BUFFER_SIZE);
	read_pos += read(fd, buffer, BUFFER_SIZE);
	printf("La string leída es: %s\n", buffer);
	return (read_pos);
}

//ssize_t read(int fildes, void *buf, size_t nbyte);
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
