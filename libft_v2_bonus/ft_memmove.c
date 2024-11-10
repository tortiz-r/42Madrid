/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:59:12 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/15 16:24:35 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*move_to_dest(char *dest_cpy, char *src_cpy, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*src_cpy;
	char			*dest_cpy;

	src_cpy = (char *) src;
	dest_cpy = (char *) dest;
	if (dest == 0 && src == 0)
		return (NULL);
	dest_cpy = move_to_dest(dest_cpy, src_cpy, n);
	return (dest_cpy);
}

char	*move_to_dest(char *dest_cpy, char *src_cpy, size_t n)
{
	unsigned long	i;

	i = 0;
	if (dest_cpy < (src_cpy) || dest_cpy >= (src_cpy + n))
	{
		while (i < n)
		{
			dest_cpy[i] = src_cpy[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest_cpy[n - 1 - i] = src_cpy[n - 1 - i];
			i++;
		}
	}
	return (dest_cpy);
}
