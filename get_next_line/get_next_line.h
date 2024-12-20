/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tortiz-r <tortiz-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:28:35 by tortiz-r          #+#    #+#             */
/*   Updated: 2024/12/19 18:32:21 by tortiz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_line_utils_struct
{
	int							fd;
	int							c_status;
	int							l_status;
	int							f_status;
	int							bytes_read;
	char						*l_compl;
	char						*l_rem;
	struct s_line_utils_struct	*next;
}								t_line_obj;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*write_buffer(int fd, t_line_obj *line_utils);
char				*distrib_buffer(int optn, char *buffer, t_line_obj *l_obj);
int					check_line(t_line_obj *line_obj);

// char				*write_distrib_buffer(int fd, t_line_obj *line_utils);

t_line_obj			*ft_lstnew(int fd, int read_status, int line_status);
void				ft_lstadd_back(t_line_obj *lst, t_line_obj *new_node);
void				ft_lstclear_num(t_list **lst, void (*del)(void*),
						size_t size);
int					ft_lstsize(t_line_obj *lst);
char				*write_buffer(int fd, t_line_obj *line_utils);
char				*ft_linefusion(char *line1, char *line2, int line2_len);
int 				ft_linelen(char *str, int end, int str_len);

#endif
