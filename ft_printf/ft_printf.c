/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:11:47 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/09/29 09:54:25 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	va_start (args, str);

	//va_arg(args, int);
	
	va_end(args);
	
	return (0);
}

int	count_args(char const *str)
{
	int		num_args;
	char	*temp;

	num_args = 0;
	temp = str;
	if (str == NULL)
		return (-1);
	while (temp != '\0')
	{
		if (*temp == '%')
			num_args++;
		temp++;
	}
	return (num_args);
}

int main(void)
{
	char *str = "hola que tal %j\n";
	write(1, count_args, 1);
	return (0);
}