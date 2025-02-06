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

char	*ft_u_itoa(unsigned int n)
{
	unsigned int	orden_magn;
	unsigned int	n_cpy;
	char			*str_num;

	n_cpy = (unsigned int) ft_val_abs((long) n);
	//printf("n_cpy es: %u\n", n_cpy);
	orden_magn = 0;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 10;
		n_cpy = n_cpy / 10;
		orden_magn++;
	}
	//printf("orden_magn es: %u\n", orden_magn);
	if (n > 0)
		str_num = malloc(orden_magn + 1);
	else
		str_num = malloc(2);
	if (str_num == NULL)
		return (NULL);
	if (n_cpy == 0)
		str_num[0] = '0';
	str_num = u_int_to_char(str_num, (unsigned int) ft_val_abs(n), orden_magn);
	return (str_num);
}

char	*u_int_to_char(char *str_num, unsigned int n, unsigned int orden_magn)
{
	unsigned int	i;

	i = 0;
	//printf("n es: %u\n", n);
	if (n == 0)
		str_num[1] = '\0';
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
