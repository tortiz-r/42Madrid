/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:28:31 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/07 13:19:42 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//basicamente aquí meto las funciones de la libft que vaya a necesitar
//por la norma solo puede haber un máximo de 5 funciones por archivo
//así que ft_strlen, ft_strjoin, ft_strchr, ft_strnchr, ft_substr

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// struct read_list	*create_node(void)
// {
// 	return (struct read_list)
// }