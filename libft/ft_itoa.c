/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:12:36 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/16 18:28:45 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_val_abs(int n);

char	*int_to_char(char *str_num, int n_cpy, unsigned int orden_magn);

char	*ft_itoa(int n)
{
	unsigned int	orden_magn;
	int				n_cpy;
	char			*str_num;

	n_cpy = ft_val_abs(n);
	orden_magn = 0;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 10;
		n_cpy = n_cpy / 10;
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
	str_num = int_to_char(str_num, n, orden_magn);
	return (str_num);
}

int	ft_val_abs(int n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}

char	*int_to_char(char *str_num, int n, unsigned int orden_magn)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		str_num[0] = '-';
		str_num[orden_magn + 1] = '\0';
		str_num[orden_magn] = ft_val_abs(n % 10) + '0';
		n -= n % 10;
		n = n / 10;
		n *= (-1);
	}
	else if (n == 0)
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

//malloc por lo menos orden_magn + 1 para el \0 del final además de digitos