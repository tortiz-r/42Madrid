/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:12:36 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/17 01:03:29 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_val_abs(int n);

char	*int_to_char(char *str_num, int n_cpy, unsigned int order_magn);

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

int	ft_val_abs(int n)
{
	if (n < 0)
		n *= (-1);
	return (n);
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

//malloc at least order_magn + 1 for \0 plus digits necessary