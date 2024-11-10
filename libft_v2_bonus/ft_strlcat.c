/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:57:51 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/17 01:08:16 by tortiz-r         ###   ########.fr       */
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

//nº bytes to cocat are the ones that fit or all of src if it fits