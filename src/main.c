/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwok <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:21:43 by jiwok             #+#    #+#             */
/*   Updated: 2019/07/31 16:33:19 by jiwok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "funcs.h"

int			ft_assign_elements(int fd, char **arr, int ncols, char *defs)
{
	int		i;
	int		j;
	int		emptybox;
	char	buf[ncols + 2];

	i = 0;
	emptybox = 0;
	while (read(fd, buf, ncols + 1) > 0)
	{
		j = 0;
		while (j < ncols)
		{
			if (emptybox != 1 && (buf[j] == defs[0]))
				emptybox = 1;
			else if (buf[j] != defs[0] && buf[j] != defs[1])
				return (0);
			arr[i][j] = buf[j];
			j += 1;
		}
		if (buf[j] != '\n')
			return (0);
		i += 1;
	}
	return (emptybox == 1 ? i : 0);
}

t_mem		ft_demystify2(int fd, int nrows, int *ncols)
{
	int		i;
	char	ch;
	t_mem	a;

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

void		ft_demystify1(int fd, int *nrows, char *defs)
{
	int		i;
	char	ch;
	char	buf[14];

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
			break ;
		}
		buf[i] = ch;
		i += 1;
	}
}

void		execute(char *filename, char ch, int i)
{
	int		fd;
	int		nrows;
	int		ncols;
	char	defs[3];
	t_mem	a;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	ft_demystify1(fd, &nrows, defs);
	a = ft_demystify2(fd, nrows, &ncols);
	close(fd);
	fd = open(filename, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
		if (ch == '\n')
			break ;
	i = ft_assign_elements(fd, a.arr, ncols, defs);
	if (!i || i != nrows)
		write(2, "map error\n", 11);
	else
		size_map(a, defs, nrows, ncols);
	close(fd);
	free(a.arr);
	free(a.sizearr);
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc == 1 && ft_read_input())
		execute("filefromstdin.txt", 'a', 0);
	i = 1;
	while (i < argc)
	{
		execute(argv[i], 'a', 0);
		if (i != (argc - 1))
			write(1, "\n", 1);
		i += 1;
	}
}
