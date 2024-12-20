/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:58:15 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/17 01:01:33 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	calc_int(char *str_num);

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

unsigned int	calc_int(char *str_num)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (i < ft_strlen(str_num) && (str_num[i] >= '0' && str_num[i] <= '9'))
	{
		result = result * 10 + (unsigned int)(str_num[i] - '0');
		i++;
	}
	return (result);
}

//srt[i] 9 to 13 are tab, newline, vtab, formfeed and carriage ret