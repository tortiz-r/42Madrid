/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:22:39 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/16 18:34:58 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_val_abs2(int n);

int		ft_power2(int num, int index);

void	int_to_char_write(unsigned int n, unsigned int orden_magn, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num_units;
	unsigned int	n_cpy;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	if (n == -2147483648)
	{
		write(fd, "2", 1);
		n = 147483648;
	}
	n_cpy = ft_val_abs2(n);
	num_units = 0;
	while (n_cpy != 0)
	{
		n_cpy -= n_cpy % 10;
		n_cpy = n_cpy / 10;
		num_units++;
	}
	int_to_char_write(ft_val_abs2(n), num_units - 1, fd);
	return ;
}

void	int_to_char_write(unsigned int n, unsigned int orden_magn, int fd)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i <= orden_magn)
	{
		c = (n / ft_power2(10, orden_magn - i)) + '0';
		ft_putchar_fd(c, fd);
		n = n % ft_power2(10, orden_magn - i);
		i++;
	}
	return ;
}

int	ft_val_abs2(int n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}

int	ft_power2(int num, int index)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	while (i <= index)
	{
		result *= num;
		i++;
	}
	return (result);
}
