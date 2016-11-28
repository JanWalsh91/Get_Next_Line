/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:57:42 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/28 18:58:38 by jwalsh           ###   ########.fr       */
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

	//printf("reading file\n");
	while (!ft_strchr(p->content, '\n'))
	{
		//printf("no newline found in buf\n");
		if ((ret = read(p->content_size, &buf, BUFF_SIZE)) == -1)
			return (-1);
		//printf("ret: %d\n", ret);
		buf[ret] = '\0';
		if (ret != 0)
		{
			//printf("freeing in ret != 0. p->content: %s\n", (char *)p->content);
			p->content = ft_strjoinfree(p->content, buf, 'l');
		}
		if (ret == 0)
		{
			
			if (*(char *)p->content)//printf("ret == 0: end of file with buf: %s\n", p->content);
			{
				//printf("freeing in ret == 0\n");
				p->content = ft_strjoinfree(p->content, "\n", 'o');
				return(read_buf(p, line));
			}
			return (0);
		}
		//printf("content copied: %s\n", p->content);
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
	char	*tmp;

	//	return (0);
	end = ft_strchr(p->content, '\n');
	if (*end == '\n')
	{
		*end = '\0';
		//printf("found a newline\n");
		end++;
		if (!(tmp = ft_strnew(ft_strlen(end))) ||
			!(*line = (char *)ft_memalloc(sizeof(char) * ft_strlen(p->content))))
			return (0);
		//printf("memalloc successful\n");
		tmp = ft_memcpy(tmp, end, ft_strlen(end));
		//printf("freeing in read buf end == ]n \n");
		*line = ft_strjoinfree(*line, p->content, 'l');
		free(p->content);
		p->content = tmp;
		//printf("copied to line: %s\n", *line);
		return (1);
	}
	else if (end == NULL)
	{
		//printf("no newline found\n");
		//printf("freeing in read buf end == nULL \n");
		*line = ft_strjoinfree(*line, p->content, 'l');
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
	//printf("passed error cases\n");
	p = lst;
	while (p && fd != (int)p->content_size)
	{
		//printf("iterating through list: fd = %i, p->content_size = %i\n", fd, (int)p->content_size);
		p = p->next;
	}
	//printf("found the right node: fd = %i\n", fd);
	if (!p)
	{
		//printf("creating new chain\n");
		new = ft_lstnew("", 1);
		new->content_size = fd;
		ft_lstadd(&lst, new);
		p = lst;
		//printf("new chain created\n");
	}
	//p = lst;
	if (!ft_strchr(p->content, '\n'))
		return (read_file(p, line));
	return (read_buf(p, line));
}
