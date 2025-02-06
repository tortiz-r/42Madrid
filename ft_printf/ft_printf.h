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

# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

int				ft_printf(char const *str, ...);
int				check_placeholder(char const *str, int position);
int				print_placeholder(va_list args, int ph_code);
int	            print_more_placeholders(va_list args, int ph_code);


char			*ft_itoa(int n);
char			*ft_u_itoa(unsigned int n);
char			*ft_hex_itoa(int n, char optn);
char			*ft_str_ptr_hex(void *str);

int				ft_atoi(const char *nptr);
char			*ft_strdup(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);

int				ft_val_abs(int n);
unsigned int	ft_u_val_abs(long n);
char	        hex_ascii(int num, char optn);
char	        *int_to_hex_str(char *str_num, unsigned int n,
			        unsigned int orden_magn, char c);

#endif