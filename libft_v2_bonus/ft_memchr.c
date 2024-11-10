/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:05:01 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/17 01:05:37 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = (unsigned char *) s;
	while (i < n)
	{
		if ((unsigned char) c == *(s_cpy + i))
			return (s_cpy + i);
		else
			i++;
	}
	return (NULL);
}
