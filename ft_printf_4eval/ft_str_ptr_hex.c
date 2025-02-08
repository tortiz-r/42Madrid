/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ptr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:52:02 by tortiz-r          #+#    #+#             */
/*   Updated: 2025/02/08 20:01:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_to_hex_str_ptr(char *str_num, unsigned long n,
			unsigned int orden_magn, char c);

char	*ft_str_ptr_hex(void *str)
{
	if (str == NULL)
		return (NULL);
	else
		return(ft_ptr_hex_itoa((long) str, 'l'));
}

// optn == l for lowercase; == u for uppercase
char	*ft_ptr_hex_itoa(long n, char optn)
{
	unsigned int	orden_magn;
	unsigned long	n_cpy;
	char			*str_num;

	orden_magn = 0;
	n_cpy = n;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 16;
		n_cpy = n_cpy / 16;
		orden_magn++;
	}
	str_num = malloc(orden_magn + 1 + 2);
	if (str_num == NULL)
		return (NULL);
	return (int_to_hex_str_ptr(str_num, n, orden_magn, optn));
}

char	*int_to_hex_str_ptr(char *str_num, unsigned long n,
			unsigned int orden_magn, char c)
{
	unsigned int	i;

	str_num[0] = '0';
	str_num[1] = 'x';
	str_num[orden_magn + 2] = '\0';
	i = 0;
	while (n > 0)
	{
		if ((n % 16) >= 10 && (n % 16) <= 15)
			str_num[orden_magn - 1 + 2 - i] = hex_ascii(n % 16, c);
		else
			str_num[orden_magn - 1 + 2 - i] = (n % 16) + '0';
		n -= n % 16;
		n = n / 16;
		i++;
	}
	return (str_num);
}
