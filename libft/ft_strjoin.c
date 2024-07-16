/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:45:24 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/16 13:01:14 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_result;

	str_result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_result == NULL)
		return (NULL);
	str_result = ft_memcpy(str_result, s1, ft_strlen(s1));
	ft_strlcpy((str_result + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (str_result);
}
