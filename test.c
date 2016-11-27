/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:52:54 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/27 18:37:16 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	**line;
	int		fd;
	char	*string;

	line = &string;
	if (ac != 2)
		printf("Please enter the name of the file to open.\n");
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	while (get_next_line(fd, line) != 0)
		printf("------------------------------%s\n", *line);
	close(fd);
	return (0);
}
