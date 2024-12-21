/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:05:09 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/09 16:42:25 by tortiz-r         ###   ########.fr       */
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
/*
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int        	result;
    const char  *s1;
	const char	*s2;
    size_t      n;
	int			i;

    s1 = "holaquetal";
	s2 = "holzqjkb";
    n = 7;
    result = ft_strncmp(s1, s2, n);
	i = 0;
	printf("Resultado: %i \n", result);
}*/
