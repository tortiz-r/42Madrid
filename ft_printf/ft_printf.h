/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:24:46 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/08/14 12:57:06 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

# include <stdlib.h>
# include <stdio.h>

int		ft_printf(char const *str, ...);
int		count_args(char const *str);
int		check_placeholder(char const *str, int position);
void	print_placeholder(va_list args, char const *str, int pos, int ph_code);


#endif