/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:31 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/26 15:46:11 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** frees the string (str) and sets the pointer to null
** note: *str = 0 and **str= 0
** there is still an adress allocated to str until this memory space is used
*/

void	ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

/*
** joins store (store) and buffer (buffer) into a single string and frees store
** this function is used in get_net_line to fill the store until /n is found
*/

char	*ft_strjointwo(char *store, char *buffer)
{
	char	*s;
	size_t	len_store;
	size_t	len_buff;
	size_t	len;

	len_store = 0;
	len_buff = ft_strlen(buffer);
	if (store)
		len_store = ft_strlen(store);
	len = len_buff + len_store;
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (store)
	{
		ft_strlcpy(s, store, (len + 1));
		ft_free(&store);
	}
	ft_strlcpy(s + len_store, buffer, (len_buff + 1));
	return (s);
}

/*
** checks in the store (store) for \n, returns 1 if yes
** if yes, splits store - puts in store what is after /n
** and in line what is before the /n
** this function is used in get_next_line to print
** what has been read (line) and store what remains
*/

int		is_line(char **store, char **line)
{
	char	*found;
	size_t	len;
	size_t	end;

	len = 0;
	found = NULL;
	if ((found = ft_strchr(*store, '\n')))
	{
		end = found - *store;
		len = ft_strlen(found);
		*line = ft_substr(*store, 0, end);
		ft_strlcpy(*store, (found + 1), (len + 1));
		return (1);
	}
	return (0);
}

/*
** reads file fd using open function in main
** returns 1 if \n is found, 0 if end of the file is reached,
** -1 if there is an error
** returns in line the text before the /n
** stores what is after using static char (store)
** main is used to call function successively until whole file is read
** note: read starts at the end of what has been read so far
** note: store is filled up until \n is found
*/

int		get_next_line(int fd, char **line)
{
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	static char	*store;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (store && is_line(&store, line))
		return (1);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!(store = ft_strjointwo(store, buffer)))
			return (-1);
		if (is_line(&store, line))
			return (1);
	}
	if (store && *store)
		*line = ft_strdup(store);
	else if (bytes_read == -1 || bytes_read == 0)
		*line = ft_strdup("");
	ft_free(&store);
	return (bytes_read);
}
