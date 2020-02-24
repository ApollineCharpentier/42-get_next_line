/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:42:48 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/24 16:42:34 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	ac = ac + 0;
	fd = open("toto.txt", O_RDONLY);
	printf("%d\n", fd);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("[%d] | %s\n", i, line);
		free (line);
		i++;
	}
		get_next_line(fd, &line);
		printf("[%d] | %s\n", i, line);
		close (fd);
		return (0);
}
