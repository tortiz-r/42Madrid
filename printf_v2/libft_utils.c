/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:16:09 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/21 20:38:13 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	result = (char *) malloc(s_len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s, s_len + 1);
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	char			*src_cpy;

	i = 0;
	src_cpy = (char *) src;
	if (size == 0)
		return ((unsigned long) ft_strlen(src_cpy));
	while (i < (size - 1) && src_cpy[i] != '\0')
	{
		dst[i] = src_cpy[i];
		i++;
	}
	dst[i] = '\0';
	return ((unsigned long) ft_strlen(src_cpy));
}

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
