/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:11:47 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/09/29 09:54:25 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }
// size_t	ft_strlen(const char *s)
// {
// 	unsigned long	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }
// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	unsigned long	i;
// 	char			*src_cpy;

// 	i = 0;
// 	src_cpy = (char *) src;
// 	if (size == 0)
// 		return ((unsigned long) ft_strlen(src_cpy));
// 	while (i < (size - 1) && src_cpy[i] != '\0')
// 	{
// 		dst[i] = src_cpy[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return ((unsigned long) ft_strlen(src_cpy));
// }
// char	*ft_strdup(const char *s)
// {
// 	char	*result;
// 	size_t	s_len;

// 	s_len = ft_strlen(s);
// 	result = (char *) malloc(s_len + 1);
// 	if (result == NULL)
// 		return (NULL);
// 	ft_strlcpy(result, s, s_len + 1);
// 	return (result);
// }

int	ft_printf(char const *str, ...)
{
	int		i;
	int		write_ok;
	va_list	args;

	i = 0;
	va_start (args, str);
	write_ok = 1;
	while (i < (int) ft_strlen(str) && write_ok == 1)
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
		}
		else if (str[i] == '%' && check_placeholder(str, i) > 0)
		{
			print_placeholder(args, str, i, check_placeholder(str, i));
			i = i + 2;
		}
		// else if (str[i] == '%' && check_placeholder(str, i) == 0)
		// 	write_ok = 0;
		else
			write_ok = 0;
		i++;
	}
	return (0);
}
//me sirve de algo??
int	count_args(char const *str)
{
	int		i;
	int		len;
	int		num_args;

	i = 0;
	len = 0;
	num_args = 0;
	if (str == NULL)
		return (-1);
	while (str[len] != '\0')
		len++;
	while (i < len)
	{
		if (str[i] == '%' && str[i+1] != '%' && str[i+1] != '\0')
			num_args++;
		i++;
	}
	return (num_args);
}

//str[i] es un '%',
//check_placeholder comprueba que str[i+1] sea algún placeholder
//si str[i+1]== '\0' -> devuelve 0
//si str[i+1]== OTRO -> devuelve -1
int	check_placeholder(char const *str, int pos)
{
	int	i;

	i = 0;
	if (str[pos + 1] == '\0')
		return (0);
	if (str[pos + 1] == 'c')
		return (1);
	if (str[pos + 1] == 's')
		return (2);
	if (str[pos + 1] == 'p')
		return (3);
	if (str[pos + 1] == 'd')
		return (4);
	if (str[pos + 1] == 'i')
		return (5);
	if (str[pos + 1] == 'u')
		return (6);
	if (str[pos + 1] == 'x')
		return (7);
	if (str[pos + 1] == 'X')
		return (8);
	if (str[pos + 1] == '%')
		return (9);
	return (-1);
}
//en función del ph code, llama a funciones para imprimir cada cosa
void	print_placeholder(va_list args, char const *str, int pos, int ph_code)
{
	char	*temp;

	if (ph_code == 1)
		ft_putchar_fd(va_arg(args, int), 1);
	else if (ph_code == 2)
	{
		temp = ft_strdup(va_arg(args, char *));
		ft_putstr_fd(temp, 1);
		free(temp);
	}
	else if (ph_code == 4 || ph_code == 5)
	{

	}
}
//pregunta: se imprimen los '\0' al final del printf???
//necesito saber el número de placeholders que tengo??
int main(void)
{
	char *str = "hola que ta%%l j\n";
	printf("num_args es: %i", 97);
	ft_printf("num_args es: %s", "holi\n");
	// printf("num_args es: %i", 5);
	return (0);
}