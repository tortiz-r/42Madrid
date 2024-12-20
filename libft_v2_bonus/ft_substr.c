/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:02:49 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/16 12:43:06 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (ft_strlen(s) >= (start + len))
	{
		substr = malloc(len + 1);
		if (substr == NULL)
			return (NULL);
		ft_strlcpy(substr, (s + start), len + 1);
	}
	else
	{
		substr = malloc(ft_strlen(s) - start + 1);
		if (substr == NULL)
			return (NULL);
		ft_strlcpy(substr, (s + start), ft_strlen(s) - start + 1);
	}
	return (substr);
}
