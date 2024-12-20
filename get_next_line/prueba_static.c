/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:35:09 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/06 18:45:50 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	runner(int count);
int	main_func(void);

int	main(void)
{
	printf("%i\n", main_func());
	printf("%i\n", main_func());
	return (0);
}

int	main_func(void)
{
	static int	num = 0;
	// int num;
	// num = 0;
	num = runner(num);
	return (num);
}

int	runner(int count)
{
	count++;
	return (count);
}
