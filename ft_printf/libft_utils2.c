/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:32:09 by marvin            #+#    #+#             */
/*   Updated: 2025/01/23 15:32:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_val_abs(int n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}
unsigned long	ft_u_val_abs(long n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}
int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	if (s == NULL)
		{
			ft_putstr_fd("(null)", 1);
			return (ft_strlen("(null)"));
		}
	return (i);
}
int	ft_putptr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	if (s == NULL)
		{
			ft_putstr_fd("(nil)", 1);
			return (ft_strlen("(nil)"));
		}
	return (i);
}