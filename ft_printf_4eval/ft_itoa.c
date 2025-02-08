/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:27:04 by tortiz-r          #+#    #+#             */
/*   Updated: 2025/02/08 20:00:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_to_char(char *str_num, int n, unsigned int order_magn);

char	*ft_itoa(int n)
{
	unsigned int	order_magn;
	int				n_cpy;
	char			*str_num;

	n_cpy = ft_val_abs(n);
	order_magn = 0;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 10;
		n_cpy = n_cpy / 10;
		order_magn++;
	}
	if (n < 0)
		str_num = malloc(order_magn + 2);
	else if (n > 0)
		str_num = malloc(order_magn + 1);
	else
		str_num = malloc(2);
	if (str_num == NULL)
		return (NULL);
	if (n == 0)
		str_num[0] = '0';
	str_num = int_to_char(str_num, n, order_magn);
	return (str_num);
}

char	*int_to_char(char *str_num, int n, unsigned int order_magn)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		str_num[0] = '-';
		str_num[order_magn + 1] = '\0';
		str_num[order_magn] = ft_val_abs(n % 10) + '0';
		n -= n % 10;
		n = n / 10;
		n *= (-1);
	}
	else if (n == 0)
		str_num[1] = '\0';
	else
		str_num[order_magn] = '\0';
	while (n > 0)
	{
		str_num[order_magn - 1 - i] = (n % 10) + '0';
		n -= n % 10;
		n = n / 10;
		i++;
	}
	return (str_num);
}
