/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:36:07 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/09 16:57:17 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*s_cpy;

	i = 0;
	len = 0;
	s_cpy = (char *) s;
	while (*(s_cpy + len) != '\0')
		len++;
	if ((char) c == '\0')
		return (s_cpy + len);
	else
		len--;
	while (*(s_cpy + len - i) != '\0' && i <= len)
	{
		if ((char) c == *(s_cpy + len - i))
			return (s_cpy + len - i);
		i++;
	}
	return (NULL);
}
