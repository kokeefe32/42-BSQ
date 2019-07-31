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

int    ft_map_error(void)
{
    write(2, "map error\n", 11);
    return (0);
}

int    ft_assign_elements(char *filename, char **arr, int ncols, char *defs)
{
    int     i;
    int     j;
    int     fd;
    int     emptybox;
    char    ch;
    char    buf[ncols + 2];

    i = 0;
    fd = open(filename, O_RDONLY);
    while (read(fd, &ch, 1) > 0)
        if (ch == '\n')
            break;
    while (read(fd, buf, ncols + 1) > 0) 
    {
        j = 0;
        while (j < ncols)
        {
            if (emptybox != 1 && (buf[j] == defs[0]))
                emptybox = 1;
            else if (buf[j] != defs[0] && buf[j] != defs[1])
                return (ft_map_error());
            arr[i][j] = buf[j];
            j += 1;
        }
        if (buf[j] != '\n')
            return (ft_map_error());
        i++;
    }
    if (emptybox != 1)
        return (ft_map_error());
    close(fd);
    return (1);
}

mem     ft_demystify2(int fd, int nrows, int *ncols)
{
    int     i;
    char	ch;
    mem     a;

    a.arr = (char **)malloc(sizeof(char *) * nrows);
    a.sizearr = (int **)malloc(sizeof(int *) * nrows);
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
        a.arr[i] = (char *)malloc(sizeof(char) * ((*ncols) + 1));
        a.sizearr[i] = (int *)malloc(sizeof(int) * ((*ncols) + 1));
        i += 1;    
    }
    return (a);
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

void    check_new_line(int *i, int argc)
{
    if (*i != (argc - 1))
        write(1, "\n", 1);
    *i += 1;
}

int		main(int argc, char **argv)
{
	int     i;
	int     fd;
    int     nrows;
    int     ncols;
    char    defs[3];
    mem     a;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY); 
        if (fd == -1)
        {
            check_new_line(&i, argc);
            continue ;
        }
        ft_demystify1(fd, &nrows, defs);
        a = ft_demystify2(fd, nrows, &ncols);
        close(fd);
        if (!ft_assign_elements(argv[i], a.arr, ncols, defs))
        {
            check_new_line(&i, argc);
            continue ;
        }
        size_map(a, defs, nrows, ncols);
        free(a.arr);
        free(a.sizearr);
        check_new_line(&i, argc);
	}
}
