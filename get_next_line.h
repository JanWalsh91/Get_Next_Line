/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:55:46 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/30 12:30:35 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"

# define BUFF_SIZE 32

int			get_next_line(const int fd, char **line);
int			read_file(t_list *p, char **line);
int			read_buf(t_list *p, char **line);

#endif
