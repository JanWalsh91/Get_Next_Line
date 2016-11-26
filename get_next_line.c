/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:57:42 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/26 20:13:13 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
** Attempts to read the file pointed to by p->fd BUFF_SIZEF_SIZE characters
** at a time. Contatenates the strings into the p->static_buf string.
** Repeats until 
*/

int	read_file(t_list *p, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	printf("reading file\n");
	while (!ft_strchr(p->content, '\n'))
	{
		printf("no newline found in buf\n");
		if ((ret = read(p->content_size, &buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[BUFF_SIZE] = '\0';
		p->content = ft_strjoinfree(p->content, buf, 'l');
		if (ret == 0)
			*line = ft_strjoinfree(*line, ft_strsplit(p->content, '\n')[0], 'b');
		printf("content copied: %s\n", p->content);
	}
	return (read_buf(p, line));
}

/*
** Attempts to read from the buffer. If a \n is found, copy into line until
** the \n and returns 1.
** If no \n is found, copy the whole buffer and read from the file.
*/

int	read_buf(t_list *p, char **line)
{
	char	*end;

	printf("reading buf\n");
	end = ft_strchr(p->content, '\n');
	if (*end == '\n')
	{
		printf("found a newline\n");
		if (!(*line = (char *)ft_memalloc(sizeof(char) * ft_strlen(ft_strsplit(p->content, '\n')[0]))))
			return (0);
		printf("memalloc successful\n");
		*line = ft_strjoinfree(*line, ft_strsplit(p->content, '\n')[0], 'r');
		printf("copied to line: %s\n", *line);
		return (1);
	}
	else if (end == NULL)
	{
		printf("no newline found\n");
		*line = ft_strjoinfree(*line, p->content, 'b');
		return (read_file(p, line));
	}
	return (read_file(p, line)); //necessary?
}

/*
** Checks for valid fd values and line.
** Finds the appropriate static buffer or creates a new one.
*/

int	get_next_line(const int fd, char **line)
{
	t_list			*p;
	static t_list	*lst;
	t_list			*new;

	if (!line || fd < 0 || fd == 1 || fd == 2)
		return (-1);
	printf("passed error cases\n");
	p = lst;
	while (p && fd != (int)p->content_size)
		p = p->next;
	printf("iterating through list\n");
	if (!p)
	{
		printf("creating new chain\n");
		new = ft_lstnew("", 1);
		new->content_size = fd;
		ft_lstadd(&lst, new);
		printf("new chain created\n");
		p = lst;
	}
	else
		p = lst;
	if (!ft_strchr(p->content, '\n'))
		return (read_file(p, line));
	return (read_buf(p, line));
}
