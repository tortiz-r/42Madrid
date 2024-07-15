/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:57:51 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/15 18:47:50 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	dst_len;
	unsigned long	src_len;
	unsigned long	len_cat;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	if ((size - dst_len - 1) < src_len)
		len_cat = size - dst_len - 1;
	else
		len_cat = src_len;
	ft_memcpy((dst + dst_len), src, len_cat);
	dst[dst_len + len_cat] = '\0';
	return (dst_len + src_len);
}
//nº bytes a cocat son: los que caben o si todo src cabe, pues src entero
/*
void	dest_cat(char *dst, const char *src, size_t dst_len1, size_t size)
{
	unsigned long	i;

	i = 0;
	while (i < (size - dst_len1 - 1) && src[i] != '\0')
	{
		dst[dst_len1 + i] = src[i];
		i++;
	}
	dst[dst_len1 + i] = '\0';
}*/