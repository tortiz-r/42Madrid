/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:59:12 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/11 16:13:34 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	char			*src_cpy;
	char			*dest_cpy;

	i = 0;
	src_cpy = (char *) src;
	dest_cpy = (char *) dest;
	if (dest_cpy < (src_cpy + n))
	{
		while (i < n)
		{
			dest_cpy[n - 1 - i] = src_cpy[n - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest_cpy[i] = src_cpy[i];
			i++;
		}
	}
	return (dest_cpy);
}
