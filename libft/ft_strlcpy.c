/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:56:39 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/15 16:59:57 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	char			*src_cpy;

	i = 0;
	src_cpy = (char *) src;
	if (size == 0)
		return ((unsigned long) ft_strlen(src_cpy));
	while (i < (size - 1) && src_cpy[i] != '\0')
	{
		dst[i] = src_cpy[i];
		i++;
	}
	dst[i] = '\0';
	return ((unsigned long) ft_strlen(src_cpy));
}
