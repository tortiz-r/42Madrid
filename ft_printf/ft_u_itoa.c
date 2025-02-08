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

#include "ft_printf.h"

char			*u_int_to_char(char *str_num, unsigned int n,
					unsigned int orden_magn);

char	*ft_u_itoa(int n)
{
	unsigned int	orden_magn;
	unsigned int	n_cpy;
	char			*str_num;

	orden_magn = 0;
	n_cpy = n;
	if (n < 0)
		n_cpy = UINT_MAX - (unsigned int) ft_val_abs((long) n) + 1;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 10;
		n_cpy = n_cpy / 10;
		orden_magn++;
	}
	if (n < 0)
		n_cpy = UINT_MAX - (unsigned int) ft_val_abs((long) n) + 1;
	else
		n_cpy = n;
	if (n == 0)
		str_num = malloc(2);
	else
		str_num = malloc(orden_magn + 1);
	if (str_num == NULL)
		return (NULL);
	return (u_int_to_char(str_num, n_cpy, orden_magn));
}

char	*u_int_to_char(char *str_num, unsigned int n, unsigned int orden_magn)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		str_num[0] = '0';
		str_num[1] = '\0';
	}
	else
		str_num[orden_magn] = '\0';
	while (n > 0)
	{
		str_num[orden_magn - 1 - i] = (n % 10) + '0';
		n -= n % 10;
		n = n / 10;
		i++;
	}
	return (str_num);
}
