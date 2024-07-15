/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:01:06 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/15 19:15:41 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	s_len;

	s_len = ft_strlen(s);
	result = (char *) malloc(s_len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s, s_len + 1);
	return (result);
}
