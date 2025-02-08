/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ptr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:52:02 by tortiz-r          #+#    #+#             */
/*   Updated: 2025/02/08 19:06:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	calc_int(char *str_num);

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

// char	*ft_str_ptr_hex_NO(void *str)
// {
// 	unsigned int	orden_magn;
// 	int	n;
// 	char			*str_num;
// 	n = ft_atoi((const char *) str);
// 	if (n == -1)
// 		return (NULL);
// 	orden_magn = 0;
// 	while (n != 0)
// 	{
// 		n -= n % 16;
// 		n = n / 16;
// 		orden_magn++;
// 	}
// 	n = ft_atoi((const char *) str);
// 	if (n > 0)
// 		str_num = malloc(orden_magn + 1 + 2);
// 	else
// 		str_num = malloc(2);
// 	if (str_num == NULL)
// 		return (NULL);
// 	str_num[0] = '0';
// 	str_num[1] = '1';
// 	printf("n es: %x", n);
// 	printf("n_hex es: %x", n);
// 	int_to_hex_str(str_num + 2, (unsigned int) n, orden_magn, 'l');
// 	return (str_num);
// }

// int	ft_atoi(const char *nptr)
// {
// 	unsigned int	i;
// 	char			*str;
// 	int				sign;
// 	int				result;

// 	i = 0;
// 	str = (char *) nptr;
// 	sign = 1;
// 	result = 0;
// 	if (nptr == NULL)
// 		return (-1);
// 	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign *= (-1);
// 		i++;
// 	}
// 	result = sign * calc_int(str + i);
// 	return (result);
// }

// unsigned int	calc_int(char *str_num)
// {
// 	unsigned int	i;
// 	unsigned int	result;

// 	i = 0;
// 	result = 0;
// 	while (i < ft_strlen(str_num) && (str_num[i] >= '0' && str_num[i] <= '9'))
// 	{
// 		result = result * 10 + (unsigned int)(str_num[i] - '0');
// 		i++;
// 	}
// 	return (result);
// }


///lo de debajo estaba comentado de antes


// char	*int_to_hex_str_ptr(char *str_num, unsigned int n,
// 			unsigned int orden_magn, char c)
// {
// 	unsigned int	i;

// 	i = 0;
// 	if (n == 0)
// 		str_num[1] = '\0';
// 	else
// 		str_num[orden_magn] = '\0';
// 	while (n > 0)
// 	{
// 		if ((n % 16) >= 10 && (n % 16) <= 15)
// 			str_num[orden_magn - 1 - i] = hex_ptr_ascii(n % 16, c);
// 		else
// 			str_num[orden_magn - 1 - i] = (n % 16) + '0';
// 		n -= n % 16;
// 		n = n / 16;
// 		i++;
// 	}
// 	return (str_num);
// }

// char	hex_ptr_ascii(int num, char optn)
// {
// 	if (num == 10 && optn == 'l')
// 		return ('a');
// 	if (num == 11 && optn == 'l')
// 		return ('b');
// 	if (num == 12 && optn == 'l')
// 		return ('c');
// 	if (num == 13 && optn == 'l')
// 		return ('d');
// 	if (num == 14 && optn == 'l')
// 		return ('e');
// 	if (num == 15 && optn == 'l')
// 		return ('f');
// 	return ((char) num);
// }
