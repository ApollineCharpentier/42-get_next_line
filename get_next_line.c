/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:31 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/24 16:35:41 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// frees the string and sets the pointer to null (**as is the address of the string to be freed)
void    ft_free(char **str)
{
    if (str && *str)
    {
        free(*str);
        *str = NULL;
    }
}

// joins store and buffer into a single string and frees the store
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

// checks in store for \n, returns 1 if yes and updates the content of the store with what is after /n, and puts in line what is before the /n
int	is_line(char **store, char **line)
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
		ft_strlcpy(*store, (found + 1), (len +1));
		return (1);
	}
	return (0);
}

// returns 1 if finds a \n, 0 if the end of the file is reached, -1 if there is an error. Stores in line the text before the /n.
int		get_next_line(int fd, char **line)
{
	int			bytes_read;
	char		buffer[1000000 + 1];
	static char	*store;

	int BUFFER_SIZE;
	BUFFER_SIZE = 1000000;
	
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
	if	(store && *store)
		*line = ft_strdup(store);
	else if (bytes_read == -1 || bytes_read == 0)
		*line = ft_strdup("");
	ft_free(&store);
	return (bytes_read);
}
