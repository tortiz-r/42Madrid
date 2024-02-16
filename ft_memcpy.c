/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:55:05 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/02/16 15:26:07 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		(char *)dst[i] = (char *)src[i];
		i++;
	}
	return (dst);
}
