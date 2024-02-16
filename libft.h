/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:27:35 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/02/16 15:19:59 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_strlen(const char *s);

void	*ft_memset(void *b, int c, int len);

void	ft_bzero(void *s, int n);

void	*ft_memcpy(void *restrict dst, const void *restrict src, int n);

int		ft_toupper(int c);

int		ft_tolower(int c);

#endif
