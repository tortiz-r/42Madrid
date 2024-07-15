/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:58:35 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/15 16:27:35 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copies_strnstr(char *big_cpy, char *little_cpy, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_cpy;
	char	*little_cpy;

	big_cpy = (char *) big;
	little_cpy = (char *) little;
	if (little_cpy[0] == '\0')
		return (big_cpy);
	else if (big_cpy[0] == '\0')
		return (NULL);
	else
		return (ft_copies_strnstr(big_cpy, little_cpy, len));
}

char	*ft_copies_strnstr(char *big_cpy, char *little_cpy, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	while (i < len && big_cpy[i] != '\0')
	{
		j = 0;
		while ((i + j) < len
			&& little_cpy[j] != '\0' && big_cpy[i + j] == little_cpy[j])
			j++;
		if (j == (unsigned long) ft_strlen(little_cpy))
			return (big_cpy + i);
		i++;
	}
	return (NULL);
}
