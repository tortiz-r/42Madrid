/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:45:28 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/17 01:06:59 by tortiz-r         ###   ########.fr       */
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
