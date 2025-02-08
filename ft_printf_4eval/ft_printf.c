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

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int	ft_printf(char const *str, ...)
{
	int		i;
	int 	j;
	int		write_ok;
	va_list	args;

	i = 0;
	j = 0;
	va_start (args, str);
	write_ok = 1;
	while (i < (int) ft_strlen(str) && write_ok == 1)
	{
		if (str[i] != '%')
		{
			j += ft_putchar_fd(str[i], 1);
		}
		else if (str[i] == '%' && check_placeholder(str, i + 1) > 0)
		{
			j += print_placeholder(args, check_placeholder(str, i + 1));
			i++;
		}
		else
			write_ok = 0;
		i++;
	}
	va_end(args);
	return (j);
}

//str[i] es un '%',
//check_placeholder comprueba que str[i+1] sea algún placeholder
//si str[i+1]== '\0' -> devuelve 0
//si str[i+1]== OTRO -> devuelve -1
int	check_placeholder(char const *str, int pos)
{
	if (str[pos] == '\0')
		return (0);
	if (str[pos] == 'c')
		return (1);
	if (str[pos] == 's')
		return (2);
	if (str[pos] == 'p')
		return (3);
	if (str[pos] == 'd')
		return (4);
	if (str[pos] == 'i')
		return (5);
	if (str[pos] == 'u')
		return (6);
	if (str[pos] == 'x')
		return (7);
	if (str[pos] == 'X')
		return (8);
	if (str[pos] == '%')
		return (9);
	return (-1);
}

//en función del ph code, llama a funciones para imprimir cada cosa
//ph_code es > 0; (1-9)
int	print_placeholder(va_list args, int ph_code)
{
	int		i;

	i = 0;
	if (ph_code == 1)
		i = ft_putchar_fd((char) va_arg(args, int), 1);
	else if (ph_code == 9)
		i = ft_putchar_fd('%', 1);
	else if (ph_code >= 2 && ph_code <= 8)
		i = print_more_placeholders(args, ph_code);
	return (i);
}

int	print_more_placeholders(va_list args, int ph_code)
{
	char	*temp;
	int		i;

	i = 0;
	if (ph_code == 2)
		temp = ft_strdup(va_arg(args, char *));
	else if (ph_code == 3)
		temp = ft_str_ptr_hex(va_arg(args, void *));
	else if (ph_code == 4 || ph_code == 5)
		temp = ft_itoa(va_arg(args, int));
	else if (ph_code == 6)
		temp = ft_u_itoa(va_arg(args, unsigned int));
	else if (ph_code == 7)
		temp = ft_hex_itoa(va_arg(args, int), 'l');
	else if (ph_code == 8)
		temp = ft_hex_itoa(va_arg(args, int), 'u');
	if (ph_code == 3)
		i = ft_putptr_fd(temp, 1);
	else
		i = ft_putstr_fd(temp, 1);
	free(temp);
	return (i);
}
