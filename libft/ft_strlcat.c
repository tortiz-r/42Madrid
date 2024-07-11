/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:57:51 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/11 15:36:39 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	result;
	unsigned long	dst_len1;
	char			*src_cpy;

	i = 0;
	result = 0;
	dst_len1 = (unsigned long) ft_strlen(dst);
	src_cpy = (char *) src;
	while (i < (size - dst_len1) && src_cpy[i] != '\0')
	{
		dst[dst_len1 + i] = src_cpy[i];
		i++;
	}
	if (src[i] == '\0')
		dst[dst_len1 + i] = '\0';
	else
		dst[dst_len1 + i] = src_cpy[i];
	result = dst_len1 + (unsigned long) ft_strlen(src_cpy);
	return (result);
}
