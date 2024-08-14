/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:11:47 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/08/14 12:57:11 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(char const *str, ...)
{
	
	va_start (args, num_args);
	va_arg(args, int);
	va_copy();
	va_end(args);

	return (0);
}
