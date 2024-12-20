/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:59:51 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/15 16:29:12 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int						dif;
	unsigned long			i;
	unsigned char			*s1_cpy;
	unsigned char			*s2_cpy;

	i = 0;
	s1_cpy = (unsigned char *) s1;
	s2_cpy = (unsigned char *) s2;
	while (i < n)
	{
		if (*(s1_cpy + i) == *(s2_cpy + i))
			i++;
		else
		{
			dif = (int)(*(s1_cpy + i) - *(s2_cpy + i));
			return (dif);
		}
	}
	if (i == n)
		return (0);
	if (*(s1_cpy + i) == '\0' && *(s2_cpy + i) != '\0')
		return ((int )((*(s1_cpy + i) - *(s2_cpy + i))));
	if (*(s1_cpy + i) != '\0' && *(s2_cpy + i) == '\0')
		return ((int )((*(s1_cpy + i) - *(s2_cpy + i))));
	return (0);
}
