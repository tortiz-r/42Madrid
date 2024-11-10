/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:02:21 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/17 01:05:45 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_strs(char const *s, char c);

char	**cpy_substrs(char **strs, char const *s, char c, unsigned int num_str);

int		ft_strlen_char(char const *str, char c);

char	**free_all_substrs(char **strs, unsigned int j);

char	**ft_split(char const *s, char c)
{
	unsigned int	num_strs;
	char			**str_result;

	num_strs = count_strs(s, c);
	str_result = malloc(sizeof(char *) * (num_strs + 1));
	if (str_result == NULL)
		return (NULL);
	if (cpy_substrs(str_result, s, c, num_strs) == NULL)
	{
		free(str_result);
		return (NULL);
	}
	str_result[num_strs] = NULL;
	return (str_result);
}

int	count_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	flag;
	int				num_strs;

	i = 0;
	flag = 0;
	num_strs = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			num_strs++;
		}
		if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (num_strs);
}

char	**cpy_substrs(char **strs, char const *s, char c, unsigned int num_str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	is_in_word;

	i = 0;
	j = 0;
	is_in_word = 0;
	while (j < num_str)
	{
		if (s[i] != c && is_in_word == 0)
		{
			is_in_word = 1;
			strs[j] = malloc(ft_strlen_char(s + i, c) + 1);
			if (strs[j] == NULL)
				return (free_all_substrs(strs, j));
			ft_strlcpy(strs[j], s + i, ft_strlen_char(s + i, c) + 1);
			i += ft_strlen_char(s + i, c);
			j++;
		}
		if (s[i] == c && is_in_word == 1)
			is_in_word = 0;
		if (s[i] == c)
			i++;
	}
	return (strs);
}

char	**free_all_substrs(char **strs, unsigned int num_substrs_to_free)
{
	unsigned int	j;

	j = 0;
	while (j < num_substrs_to_free)
	{
		free(strs[j]);
		j++;
	}
	return (NULL);
}

int	ft_strlen_char(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}
