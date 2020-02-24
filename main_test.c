/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:19:15 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/24 17:13:10 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   main(void)
{
    printf("Main for utils %c", '\n');
    printf("strlen : %zu\n", ft_strlen("hello goodbye"));
    printf("strchr : %s\n", ft_strchr("hello goodbye", 'g'));
    printf("substr : %s\n", ft_substr("hello goodbye", 0, 3));
    printf("strdup : %s\n", ft_strdup("hello goodbye"));
    char dst[5] = "hello";
    size_t  strlcpy;
    strlcpy = ft_strlcpy(dst, "hello goodbye", 5);
    printf("strlcpy (length of dest) : %zu\n", strlcpy);
    printf("strlcpy (dest) : %s\n", dst);
    printf("%c", '\n');

    printf("Main for get next line %c", '\n');
    char *store;
    char *buffer;
    store = (char *)malloc(sizeof(char) * 2);
    buffer = (char *)malloc(sizeof(char) * 3);
    store[0] = 'h';
    store[1] = '\0';
    buffer[0] = 'a';
    buffer[1] = 'b';
    buffer[2] = '\0';
    char *str;
    str = ft_strjointwo(store, buffer);
    printf("strjointwo - store : %p\n", store);
    printf("strjointwo - buffer : %s\n", buffer);
    printf("strjointwo : %s\n", str);

	char **line2;
	char **store2;
	line2 = (char **)malloc(sizeof(char *) * 1);
	line2[0] = (char *)malloc(sizeof(char) * 1);
	line2[0] = 0;
	store2 = (char **)malloc(sizeof(char *) * 2);
	store2[0] = (char *)malloc(sizeof(char) * 3);
	store2[1] = (char *)malloc(sizeof(char) * 1);
	store2[0][0] = 'a';
	store2[0][1] = '\n';
	store2[0][2] = 'b';
	store2[1] = 0;
	printf("is_line : %d\n", is_line(store2, line2));
    printf("is_line - store : %s\n", store2[0]);
    printf("is_line - line : %s\n", line2[0]);

	char **line;
    line = (char **)malloc(sizeof(char *) * 2);
    line[0] = (char *)malloc(sizeof(char) * 3);
    line[1] = (char *)malloc(sizeof(char) * 1);
    line[0][0] = 'e';
    line[0][1] = '\n';
    line[0][2] = 'f';
    line[1] = 0;
	printf("%d\n", get_next_line(1, line));
}
