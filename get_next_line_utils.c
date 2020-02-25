/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:26:44 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/25 16:00:55 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// returns length of string
size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// returns pointer to string after the after and including the character c
/*
char	*ft_strchr(const char *s, int c)
{
	int	i;
	char *tmp;

	i = 0;
	tmp = (char*)s;
	while (tmp[i] || (tmp[i] == '\0' && (char)c == '\0'))
	{
		if (tmp[i] == (char)c)
			return ((char*)&tmp[i]);
		i++;
	}
	return (0);
}
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return((char *)s);
	return (NULL);
}

// returns pointer to string starting at the position 'start', max de longueur len
char	*ft_substr(const char*s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[start] != '\0' && start < (unsigned int)ft_strlen(s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}


// copies string s into a new string str and returns this new string
char	*ft_strdup(const char *s)
{
	int i;
	char	 *str;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// copies the source into the destination and returns the size of the source, but at max dstsize 
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_src;

	i = 0;
	size_src = 0;
	if (!dst || !src)
		return (0);
	while (src[size_src] != '\0')
		size_src++;
	if (dstsize == 0)
		return (size_src);
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}
