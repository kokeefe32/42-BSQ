/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwok <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:21:43 by jiwok             #+#    #+#             */
/*   Updated: 2019/07/30 14:24:02 by jiwok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "funcs.h"

void    ft_assign_elements(char *filename, char **arr, int ncols)
{
    int     i;
    int     j;
    int     fd;
    char    ch;
    char    buf[ncols + 2];

    i = 0;
    fd = open(filename, O_RDONLY);
    while (read(fd, &ch, 1) > 0)
	{
        if (ch == '\n')
        {
            while (read(fd, buf, ncols + 1) > 0) 
            {
                j = 0;
                while (j < ncols)
                {
                    arr[i][j] = buf[j];
                    j += 1;
                }
                i++;
            }
            break ;
        }
    }
    close(fd);
}

char    **ft_demystify2(int fd, int nrows, int *ncols)
{
    int     i;
    char	ch;
    char    **arr;

    arr = (char **)malloc(sizeof(char *) * nrows);
    i = 0;
    while (read(fd, &ch, 1) > 0)
	{
        if (ch == '\n')
            break ;
        i += 1;
    }
    *ncols = i;
    i = 0;
    while (i < nrows)
    {
        arr[i] = (char *)malloc(sizeof(char) * ((*ncols) + 1));
        i += 1;    
    }

    return (arr);
}

void    ft_demystify1(int fd, int *nrows, char *defs)
{
    int     i;
    char	ch;
    char	buf[13];

    i = 0;
    while (read(fd, &ch, 1) > 0)
	{
        if (ch == '\n')
        {
            defs[0] = buf[i - 3];
            defs[1] = buf[i - 2];
            defs[2] = buf[i - 1];
            buf[i - 3] = '\0';
            *nrows = ft_atoi(buf);
            i = 0;
            break ;
        }
        buf[i] = ch;
        i += 1;
    }
}

int		main(int argc, char **argv)
{
	int     i;
	int     fd;
    int     nrows;
    int     ncols;
    char    **arr;
    char    defs[3];

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY); 
        if (fd == -1)
            continue ;
        ft_demystify1(fd, &nrows, defs);
        arr = ft_demystify2(fd, nrows, &ncols);
        close(fd);
        ft_assign_elements(argv[i], arr, ncols);
        size_map(arr, defs, nrows, ncols);
        free(arr);
		write(1, "\n", 1);
		i++;
	}
}
