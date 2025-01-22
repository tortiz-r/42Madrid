/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:26:09 by marvin            #+#    #+#             */
/*   Updated: 2024/12/21 13:26:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

char	        *u_int_to_char(char *str_num, unsigned int n, unsigned int orden_magn);

char	*ft_u_itoa(unsigned int n)
{
	unsigned int	orden_magn;
	unsigned int	n_cpy;
	char			*str_num;

	n_cpy = ft_val_abs(n);
	printf("n_cpy es: %u\n", n_cpy);
	orden_magn = 0;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 10;
		n_cpy = n_cpy / 10;
		orden_magn++;
	}
	printf("orden_magn es: %u\n", orden_magn);
	if (n > 0)
		str_num = malloc(orden_magn + 1);
	else
		str_num = malloc(2);
	if (str_num == NULL)
		return (NULL);
	if (n_cpy == 0)
		str_num[0] = '0';
	str_num = u_int_to_char(str_num, ft_val_abs(n), orden_magn);
	return (str_num);
}

char	*u_int_to_char(char *str_num, unsigned int n, unsigned int orden_magn)
{
	unsigned int	i;

	i = 0;
	printf("n es: %u\n", n);
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

//malloc por lo menos orden_magn + 1 para el \0 del final además de digitos

// # include <unistd.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <stddef.h>

// int main(void)
// {
//     char			*str;
// 	unsigned int	integer;
    

//     integer = -298347934874501;
//     //c = 'a';
//     str = ft_u_itoa(integer);
// 	printf("Mi numero de partida es:%u\n", integer);
// 	printf("La string devuelta es:%s\n", str);
// 	free(str);
// }

/*
char	*ft_u_itoa(unsigned int n)
{
	unsigned int	orden_magn;
	unsigned int	n_cpy;
	char			*str_num;

	n_cpy = ft_val_abs(n);
	printf("n_cpy es: %u\n", n_cpy);
	orden_magn = 0;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 10;
		n_cpy = n_cpy / 10;
		orden_magn++;
	}
	printf("orden_magn es: %u\n", orden_magn);
	if (n > 0)
		str_num = malloc(orden_magn + 1);
	else
		str_num = malloc(2);
	if (str_num == NULL)
		return (NULL);
	if (n_cpy == 0)
		str_num[0] = '0';
	str_num = int_to_char(str_num, ft_val_abs(n), orden_magn);
	return (str_num);
}

unsigned int	ft_val_abs(unsigned n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}

char	*int_to_char(char *str_num, unsigned int n, unsigned int orden_magn)
{
	unsigned int	i;

	i = 0;
	// if (n < 0)
	// {
	// 	str_num[0] = '-';
	// 	str_num[orden_magn + 1] = '\0';
	// 	str_num[orden_magn] = ft_val_abs(n % 10) + '0';
	// 	n -= n % 10;
	// 	n = n / 10;
	// 	n *= (-1);
	// }
	printf("n es: %u\n", n);
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
}*/
