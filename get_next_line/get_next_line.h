/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:28:35 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/11/07 13:15:02 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include <sys/stat.h>
# include <fcntl.h>

typedef struct read_list
{
	void				*content;
	struct read_list	*next;
}						t_read_list1;

char				*get_next_line(int fd);
int					write_buffer(int fd, int read_pos);

struct read_list	*create_node(void);
size_t				ft_strlen(const char *s);

#endif