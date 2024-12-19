/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:27:07 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/19 18:30:43 by tortiz-r         ###   ########.fr       */
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
	static t_line_obj	line_obj = {0, -1, 0, 1, 0, NULL, NULL, NULL};
	char				*buffer;
	char				*check_distrib;

	line_obj.fd = fd;
	if (line_obj.c_status == -1)
	{
		buffer = write_buffer(fd, &line_obj);
		if (buffer == NULL)
		{
			line_obj.c_status = 0;
			return (NULL); //TENDRÍA QUE FREE STRUCT Y POSIBLES SIG NODOS!!!
		}
			check_distrib = distrib_buffer(1, buffer, &line_obj);
		if (check_distrib == NULL)
			return (NULL); //FREE COSIS
	}
	if (check_line(&line_obj) != 1)
		printf(VERDE_T"Check_line da 0\n"RESET_COLOR);
	return (line_obj.l_compl);
}

//lee el contenido de fd (buffer_size) y lo escribe en *buffer
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
	if (line_utils->bytes_read == 0)
	{
		free (buffer);
		return (NULL);
	}
	return (buffer);
}

char	*distrib_buffer(int optn, char *buffer, t_line_obj *l_obj)
{
	int				len_buf;
	int				len_compl;
	int				len_rem;

	len_buf = l_obj->bytes_read;
	len_compl = ft_linelen(buffer, '\n', len_buf);
	len_rem = len_buf - len_compl;
	l_obj->l_compl = ft_linefusion(l_obj->l_compl, buffer, len_compl);
	l_obj->l_rem = ft_linefusion(l_obj->l_rem, buffer+len_compl,len_rem);
	if (optn == 1)
		free(buffer);
	return (l_obj->l_compl);
}
/* Check_line:
LINE_STATUS == 1 -> elimino l_compl pq ya la he pasado antes
LINE_STATUS == 0 -> es que me toca comprobar la línea l_compl 1º
busco si tiene un /n (no busco más alla que bytes_read o si == )
*/
int	check_line(t_line_obj *line_obj)
{
	int	i;
	int	flag;

	i = 0;
	if (line_obj->line_status == 1)
		free(line_obj->l_compl);
	if (line_obj->line_status == 0)
	{
		while (line_obj->l_compl[i] != '\n')
			i++;
		if (i == ft_linelen(line_obj->l_compl, 0, line_obj->bytes_read) - 1)
			line_obj->line_status = 1;
	}
	return (line_obj->line_status);
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
