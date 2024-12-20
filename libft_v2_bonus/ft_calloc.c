/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:00:42 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/07/15 15:54:06 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*ptr_edit;
	size_t	i;

	i = 0;
	ptr = malloc(nmemb * size);
	ptr_edit = (char *) ptr;
	if (ptr_edit != NULL)
	{
		while (i < nmemb * size)
		{
			ptr_edit[i] = 0;
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
