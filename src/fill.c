/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwok <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:12:10 by jiwok             #+#    #+#             */
/*   Updated: 2019/07/29 17:35:37 by jiwok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "funcs.h"

void	display_nice_map(char **map, int nrows, int ncols, char ch, sqre a)
{
	int i;
	int j;

	i = 0;
	while (i < nrows)
	{
		j = 0;
		while (j < ncols)
		{
			if (i >= (a.i + 1 - a.size) && i <= a.i && j >= (a.j + 1 - a.size) && j <= a.j)
				write(1, &ch, 1);
			else
				write(1, &map[i][j], 1);
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
}

int		find_smallest(int i, int j, int k)
{
	if (i <= j && i <= k)
		return (i);
	else if (j <= i && j <= k)
		return (j);
	else
		return (k);
}

int		compute_neighbours(int row, int col, int i, int j, int k)
{
	if (row == 0 || col == 0)
		return (1);
	else
		return 1 + find_smallest(i, j, k);
}

void	update_struct(sqre *a, int i, int j, int size)
{
	a->i = i;
	a->j = j;
	a->size = size;
}

sqre	size_map(char **map, char *defs, int nrows, int ncols)
{
	int		i;
	int		j;
	int		sizemap[nrows][ncols];
	sqre	a;

	i = 0;
	update_struct(&a, 0, 0, 1);
	while (i < nrows)
	{
		j = 0;
		while (j < ncols)
		{
			if (map[i][j] == defs[0])
				sizemap[i][j] = compute_neighbours(i, j, sizemap[i][j - 1], sizemap[i - 1][j],
						sizemap[i - 1][j - 1]);
			else if (map[i][j] == defs[1])
				sizemap[i][j] = 0;
			if (sizemap[i][j] > a.size)
				update_struct(&a, i, j, sizemap[i][j]);
			j += 1;
		}
		i += 1;
	}
	display_nice_map(map, nrows, ncols, defs[2], a);
	return (a);
}

