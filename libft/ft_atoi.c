/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:58:15 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/16 10:50:57 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_int(char *str_num);

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	char			*str;
	int				sign;
	int				result;

	i = 0;
	str = (char *) nptr;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	result = sign * calc_int(str + i);
	return (result);
}

int	calc_int(char *str_num)
{
	unsigned int	i;
	int				result;

	i = 0;
	result = 0;
	while (i < ft_strlen(str_num) && (str_num[i] >= '0' && str_num[i] <= '9'))
	{
		result = result * 10 + (int)(str_num[i] - 48);
		i++;
	}
	return (result);
}

/*int	ft_power(int num, int index)
{
	int	i;

	i = 1;
	while (i < index)
	{
		num *= num;
		i++;
	}
	return (num);
}*/
//srt[i] 9 al 13 son: tab, newline, vtab, formfeed y carriage ret

/*Forma alternativa que hice primero pero más fea
int	char_to_int(char s)
{
	int	unit;

	if (s == '0')
		unit = 0;
	if (s == '1')
		unit = 1;
	if (s == '2')
		unit = 2;
	if (s == '3')
		unit = 3;
	if (s == '4')
		unit = 4;
	if (s == '5')
		unit = 5;
	if (s == '6')
		unit = 6;
	if (s == '7')
		unit = 7;
	if (s == '8')
		unit = 8;
	if (s == '9')
		unit = 9;
	return (unit);
}
int	calc_int(char *str_num)
{
	unsigned int	i;
	int				result;

	i = 0;
	while (i < ft_strlen(str_num) && (str_num[i] >= '0' && str_num[i] <= '9'))
	{
		result = result * 10 + char_to_int(str_num[i]);
	}
	return (result);
}*/