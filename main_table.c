/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apcharpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:57:13 by apcharpe          #+#    #+#             */
/*   Updated: 2020/02/21 16:28:25 by apcharpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char **store;
    char **line;
    int j;
    int i;
    int k;
    int l;

	store = (char**)malloc(sizeof(char *) * 3);
	store[0] = (char*)malloc(3);
	store[1] = (char*)malloc(2);
    store[0][0] = 'a';
    store[0][1] = 'b';
    store[0][2] = '\0';
    store[1][0] = 'c';
    store[1][1] = '\0';
	store[2] = 0;

	line = (char**)malloc(sizeof(char *) * 3);
	line[0] = (char*)malloc(3);
	line[1] = (char*)malloc(2);
    line[0][0] = 'e';
    line[0][1] = 'f';
    line[0][2] = '\0';
    line[1][0] = 'c';
    line[1][1] = '\0';
	line[2] = 0;

	j = 0;
    while (store[j])
    {
        i = 0;
        while (store[j][i])
        {
            printf("%c", store[j][i]);
            i++;
        }
        printf("%c", '\n');
        j++;
    }

    l = 0;
    while (line[l])
    {
        k = 0;
        while (line[l][k])
        {
            printf("%c", line[l][k]);
            k++;
        }
        printf("%c", '\n');
        l++;
    }
}
