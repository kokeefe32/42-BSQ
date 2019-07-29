/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokeefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:37:30 by kaokeefe          #+#    #+#             */
/*   Updated: 2019/07/28 17:22:57 by jiwok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"

void	create_map(char *file_name)
{
	int		fd;
	int		i;
	int		n_columns;
	int		n_rows;
	char	ch;
	char	defs[3];
	char	buf[10];
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ;
	i = 0;
	n_rows = 0;
	n_columns = 0;
	while (read(fd, &ch, 1) > 0)
	{
		if (ch >= '0' && ch <= '9' && !n_rows)
			buf[i] = ch;
		else
		{
			if (!n_rows)
			{
				n_rows = ft_atoi(buf);
				i = 0;
				defs[i] = ch;
			}
			else if (!defs[2])
				defs[i] = ch;
			else if (ch == '\n' && !n_columns)
			{
				n_columns = 1;
				i = 0;
			}
			else if (ch == '\n' && n_columns)
			{
				n_columns = i - 1;
				break ;
			}
		}
		i += 1;
	}
	close(fd);
	printf("rows %i\ncolumns %i\n", n_rows, n_columns);
	i = 0;
	while (i < 3)
	{
		printf("i: %c\n", defs[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		create_map(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
