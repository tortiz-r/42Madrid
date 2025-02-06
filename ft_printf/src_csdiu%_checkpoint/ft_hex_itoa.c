/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:30:53 by marvin            #+#    #+#             */
/*   Updated: 2024/12/21 14:30:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_hex_val_abs(long n);
char	hex_ascii(int num, char optn);
char	*int_to_hex_str(char *str_num, unsigned int n,
			unsigned int orden_magn, char c);

// optn == l for lowercase; == u for uppercase
char	*ft_hex_itoa(int n, char optn)
{
	unsigned int	orden_magn;
	int				n_cpy;
	char			*str_num;

	n_cpy = ft_hex_val_abs(n);
	orden_magn = 0;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 16;
		n_cpy = n_cpy / 16;
		orden_magn++;
	}
	if (n < 0)
		str_num = malloc(orden_magn + 2);
	else if (n > 0)
		str_num = malloc(orden_magn + 1);
	else
		str_num = malloc(2);
	if (str_num == NULL)
		return (NULL);
	if (n == 0)
		str_num[0] = '0';
	str_num = int_to_hex_str(str_num, ft_hex_val_abs(n), orden_magn, optn);
	return (str_num);
}

long	ft_hex_val_abs(long n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}

char	*int_to_hex_str(char *str_num, unsigned int n,
			unsigned int orden_magn, char c)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		str_num[1] = '\0';
	else
		str_num[orden_magn] = '\0';
	while (n > 0)
	{
		if ((n % 16) >= 10 && (n % 16) <= 15)
			str_num[orden_magn - 1 - i] = hex_ascii(n % 16, c);
		else
			str_num[orden_magn - 1 - i] = (n % 16) + '0';
		n -= n % 16;
		n = n / 16;
		i++;
	}
	return (str_num);
}

char	hex_ascii(int num, char optn)
{
	if (num == 10 && optn == 'l')
		return ('a');
	if (num == 11 && optn == 'l')
		return ('b');
	if (num == 12 && optn == 'l')
		return ('c');
	if (num == 13 && optn == 'l')
		return ('d');
	if (num == 14 && optn == 'l')
		return ('e');
	if (num == 15 && optn == 'l')
		return ('f');
	if (num == 10 && optn == 'u')
		return ('A');
	if (num == 11 && optn == 'u')
		return ('B');
	if (num == 12 && optn == 'u')
		return ('C');
	if (num == 13 && optn == 'u')
		return ('D');
	if (num == 14 && optn == 'u')
		return ('E');
	if (num == 15 && optn == 'u')
		return ('F');
	return ((char) num);
}


