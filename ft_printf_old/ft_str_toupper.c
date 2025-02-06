/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:30:03 by marvin            #+#    #+#             */
/*   Updated: 2024/12/21 14:30:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "ft_printf.h"

char			*ft_str_toupper(char *str_lowcase)
{
	int		i;
	
	i = 0;
	while ((str_lowcase + i) != 0)
	{
		if (str_lowcase[i] >= 'a' && str_lowcase[i] <= 'z')
			str_lowcase[i] -= 32;
		i++;
	}
	return (str_lowcase);
}

int main(void)
{
	char	*str_low = "hola245adios!";

	printf("la string es: %s\n", ft_str_toupper(str_low));
}
