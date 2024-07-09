/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:05:01 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/09 13:48:38 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = (unsigned char *) s;
	while ((unsigned long) i < n)
	{
		if ((unsigned char) c == *(s_cpy + i))
			return (s_cpy + i);
		else
			i++;
	}
	return (NULL);
}
/*
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char        *result;
    const void  *s;
    size_t      n;
    int         c;
	int			i;

    s = "holaquetal";
    n = 7;
    c = 'a';
    result = (char *) ft_memchr(s, c, n);
	i = 0;
	while (result[i] != '\0')
	{
    	printf("%c", result[i]);
		i++;
	}
}*/
