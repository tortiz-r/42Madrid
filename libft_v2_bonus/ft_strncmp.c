/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:05:09 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/17 01:06:47 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int						dif;
	unsigned long			i;
	unsigned char			*s1_cpy;
	unsigned char			*s2_cpy;

	i = 0;
	s1_cpy = (unsigned char *) s1;
	s2_cpy = (unsigned char *) s2;
	while (i < n && *(s1_cpy + i) != '\0' && *(s2_cpy + i) != '\0')
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
