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
# include <limits.h>

unsigned int	ft_u_val_abs(unsigned int n);
char	*u_int_to_char(char *str_num, unsigned int n, unsigned int orden_magn);


char	*ft_u_itoa(unsigned int n)
{
	unsigned int	orden_magn;
	unsigned int	n_cpy;
	char			*str_num;

	n_cpy = ft_u_val_abs(n);
	orden_magn = 0;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 10;
		n_cpy = n_cpy / 10;
		orden_magn++;
	}
	if (n > 0)
		str_num = malloc(orden_magn + 1);
	else
		str_num = malloc(2);
	if (str_num == NULL)
		return (NULL);
	if (n_cpy == 0)
		str_num[0] = '0';
	str_num = u_int_to_char(str_num, ft_u_val_abs(n), orden_magn);
	return (str_num);
}

unsigned int	ft_u_val_abs(unsigned int n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}

char	*u_int_to_char(char *str_num, unsigned int n, unsigned int orden_magn)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		str_num[1] = '\0';
	else
		str_num[orden_magn] = '\0';
	while (n > 0)
	{
		str_num[orden_magn - 1 - i] = (n % 10) + '0';
		n -= n % 10;
		n = n / 10;
		// printf("%c", str_num[orden_magn - 1 - i]);
		i++;
	}
	return (str_num);
}

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
//ph_code es > 0; (1-9)
void	print_placeholder(va_list args, char const *str, int pos, int ph_code)
{
	char	*temp;

	if (ph_code == 1)
		ft_putchar_fd(va_arg(args, int), 1);
	else if (ph_code == 9)
		ft_putchar_fd('%', 1);
	else if (ph_code >= 2 && ph_code <= 8)
	{
		if (ph_code == 2)
			temp = ft_strdup(va_arg(args, char *));
		else if (ph_code == 3)
			temp = ft_str_ptr_hex(va_args(args, void *));
		else if (ph_code == 4 || ph_code == 5)
			temp = ft_itoa(va_arg(args, int));
		else if (ph_code == 6)
			temp = ft_u_itoa(va_arg(args, int));
		else if (ph_code == 7)
			temp = ft_hex_itoa(va_arg(args, int));
		else if (ph_code == 8)
			temp = ft_str_toupper(ft_hex_itoa(va_arg(args, int)));
		ft_putstr_fd(temp, 1);
		free(temp);
	}
}

//pregunta: se imprimen los '\0' al final del printf??? -> NO
//necesito saber el número de placeholders que tengo?? -> no?
int main(void)
{
	char *str = "hola que ta%%l j\n";
	printf("prueba_printf: c es %c ; string es: %s ; d es: %d ; i es: %i ; u es: %u , percent es: %%\n", 'a', "holii", 5, -10, -1, 4);
	ft_printf("prueba_printf: c es %c ; string es: %s ; d es: %d ; i es: %i ; u es: %u , percent es: %%\n", 'a', "holii", 5, -10, -1, 4);
	// printf("num_args es: %i", 5);
	return (0);
}