//# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

#define RESET_COLOR	"\x1b[0m"
#define MAGENTA_T  "\x1b[35m"
#define ROJO_T	"\x1b[31m"
#define VERDE_T	"\x1b[32m"
#define AZUL_T	"\x1b[34m"

/***********TEST DE LINE_FUSION***********/


// char	*ft_linefusion(char *line1, char *line2, int line2_len);
// int 	ft_linelen(char *str, int end, int str_len);

int ft_linelen(char *str, int end, int str_len)
{
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

//line2_len es linelen(end, bytes_read), bytes_read
//line2len es el numero de caracteres que quiero fusionar
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

int main(void)
{
	int			len;
	char		*line1;
	char		*line2;
	char		*result;


	line1 = malloc(5);
	line1[0] = 'h';
	line1[1] = 'o';
	line1[2] = '\0';
	line2 = malloc(6);
	line2[0] = 'a';
	line2[1] = 'd';
	line2[2] = '!';
	line2[3] = 'i';
	line2[4] = 's';
	line2[5] = '\0';
	len = ft_linelen(line2, '!', 6);
	printf("len es %i\n", len);
	result = ft_linefusion(line1, line2, len);
	printf("el resultado es: %s\n", result);
	return (0);
}

// char	*get_next_line(int fd)
// {
// 	static t_line_obj	line_obj = {0, 0, -1, 0, NULL, NULL, NULL};
// 	int					actual_fd;
// 	char				*buffer;
// 	char				*check_ptr;

// 	if (line_obj.read_status == -1)
// 	{
// 		actual_fd = fd;
// 		line_obj.fd = actual_fd;
// 		printf(AZUL_T"------- Llamamos a write_buffer 1 vez\n" RESET_COLOR);
// 		buffer = write_buffer(fd, &line_obj);
// 		if (buffer == NULL)
// 		{
// 			line_obj.read_status = 0;
// 			return (NULL); //TENDRÍA QUE FREE STRUCT Y POSIBLES SIG NODOS!!!
// 		}
// 			check_ptr = distrib_buffer(1, buffer, &line_obj);
// 	printf(VERDE_T"Line_utils.line_complete es:\n"MAGENTA_T"%s\n"RESET_COLOR, line_utils.l_compl);
// 	printf(VERDE_T"Line_utils.line_remainder es:\n"MAGENTA_T"%s\n"RESET_COLOR, line_utils.l_rem);
// 		if (check_ptr == NULL)
// 			return (NULL); //FREE COSIS
// 	}
// 	while (line_obj.line_status != 1)
// 		line_obj.line_status = check_line(&line_obj);
// 	return (line_obj.l_compl);
// }