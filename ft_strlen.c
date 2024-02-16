/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:38:35 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/02/16 13:07:42 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
/*
#include<unistd.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ft_strlen(const char *s);
 int main(void)
{
	int j;
	const char *s = "hola";
	j = ft_strlen(*s);
	printf("%i", j);
}*/
