/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:52:54 by jwalsh            #+#    #+#             */
/*   Updated: 2016/11/28 18:52:48 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*line;
	//int		fd;
	int		fd2;
	int		fd3;

	if (ac != 3)
	{
		printf("Please enter three files for the GNL test.\n");
		return (0);
	}
	//if (!(fd = open(av[1], O_RDONLY)))
	//	return (0);
	if (!(fd2 = open(av[1], O_RDONLY)))
		return (0);
	if (!(fd3 = open(av[2], O_RDONLY)))
		return (0);
	//while (get_next_line(fd, &line) != 0)
	//{
//		printf("----------------------------%i--%s\n", fd, line);
//		free(line);
//	}
	//close(fd);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("fd3: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("fd3: %s\n", line);
	free(line);
	close(fd2);
	close(fd3);

	return (0);
}
