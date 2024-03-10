/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:53:33 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/02/24 20:02:19 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		len;
	int		i;
	char	*s_cpy;

	i = 0;
	len = 0;
	s_cpy = (char *) s;
	while (*(s_cpy + len) != '\0')
		len++;
	if ((char) c == '\0')
		return (s_cpy + len);
	while (i <= len)
	{
		if ((char) c == *(s_cpy + i))
			return (s_cpy + i);
		i++;
	}
	return (NULL);
}
