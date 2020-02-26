/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:42:48 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/26 11:45:07 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

//	ac = ac + 0;
	fd = open("test_noline", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("[%d] | %s\n", i, line);
		free (line);
		i++;
	}
		get_next_line(fd, &line);
		printf("[%d] | %s\n", i, line);
		close (fd);
//		system("leaks a.out");
		return (0);
}
