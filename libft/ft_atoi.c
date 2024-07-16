/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:58:15 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/15 19:38:47 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	result = sign * ascii_to_int(str + i);
	return (result);
}

int	ascii_to_int(char *str)
{
	unsigned int	i;
	int				result;

	i = 0;
	while (i < ft_strlen(str))
	{
		result = result + (str[i] - 48) * power(10, i);
	}
	return (result);
}