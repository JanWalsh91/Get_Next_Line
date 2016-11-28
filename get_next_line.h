/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:55:46 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/28 16:38:33 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./Libft/libft.h"
# include <stdio.h>

# define BUFF_SIZE 150

/*
typedef struct	s_line
{
	void			*content;
	size_t			content_size;;
	struct s_list	*next;
}				t_line;
*/

int			get_next_line(const int fd, char **line);
int			read_file(t_list *p, char **line);
int			read_buf(t_list *p, char **line);

#endif
