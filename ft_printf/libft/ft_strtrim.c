/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:45:28 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/16 21:26:35 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	look_trim_front(char const *s1, char const *set, unsigned int s1_len);

int	look_trim_end(char const *s1, char const *set, unsigned int s1_len);

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	s1_len;
	int				front_index;
	int				end_index;
	int				str_len;

	s1_len = ft_strlen(s1);
	str_len = s1_len + 1;
	front_index = 0;
	if (ft_strlen(set) != 0)
	{
		front_index = look_trim_front(s1, set, s1_len);
		end_index = look_trim_end(s1, set, s1_len);
		str_len = end_index - front_index + 2;
		if (end_index < front_index)
		{
			str_len = 1;
			front_index = 0;
		}
	}
	str = malloc(str_len);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + front_index, str_len);
	return (str);
}

int	look_trim_front(char const *s1, char const *set, unsigned int s1_len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < s1_len)
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j == ft_strlen(set))
			break ;
		i++;
	}
	return (i);
}

int	look_trim_end(char const *s1, char const *set, unsigned int s1_len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < s1_len)
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[s1_len - 1 - i] == set[j])
				break ;
			j++;
		}
		if (j == ft_strlen(set))
			break ;
		i++;
	}
	return (s1_len - 1 - i);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include "ft_putstr_fd.c"
#include "ft_strlen.c"
#include "ft_strlcpy.c"
#include "ft_putchar_fd.c"


int main(void)
{
	int i = 0;
	int j = 0;
	int index1;
	int index2;

	char *s1 = " \n\t";
	char *esperado = "";
	char *set = " \n\t";

	printf("La string s1 es: %s \nLa string set es: %s \n", s1, set);

	printf("Quito el trozo del principio y queda: \n");
	index1 = look_trim_front(s1, set, ft_strlen(s1));
	ft_putstr_fd(s1 + index1, 1);
	printf("\n");
	printf("El index1 es: %i\n", index1);
	

	printf("Quitamos el final: \n");
	index2 = look_trim_end(s1, set, ft_strlen(s1));
	printf("El index2 es: %i\n", index2);
	printf("%s", s1 + index2 + 1);
	
	return (1);
}*/

/*int main(void)
{
	int i = 0;
	int j = 0;
	int index1;
	int index2;

	char *s1 = "AHLODIMEALOHA";
	char *s2 = "jiji";
	char *set = "HOLA";

	printf("La string s1 es: %s \nLa string set es: %s \n", s1, set);

	printf("Quito el trozo del principio y queda: \n");
	index1 = look_trim_front(s1, set, ft_strlen(s1));
	ft_putstr_fd(s1 + index1, 1);
	printf("\n");
	printf("El index1 es: %i\n", index1);
	

	printf("Quitamos el final: \n");
	index2 = look_trim_end(s1, set, ft_strlen(s1));
	printf("El index2 es: %i\n", index2);
	printf("%s", s1 + index2 + 1);
	
	return (1);
}*/

/*
#include <stdlib.h>
#include <stdio.h>
#include "ft_putstr_fd.c"
#include "ft_strlen.c"
#include "ft_strlcpy.c"
#include "ft_putchar_fd.c"

int main(void)
{
	char *s = "1231231232112333221";
	printf("String: %s\n", ft_strtrim(s, "123"));
	return (0);
}*/