/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwok <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:12:10 by jiwok             #+#    #+#             */
/*   Updated: 2019/07/29 13:55:31 by jiwok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_size_map(int map[4][8], int nrows, int ncols)
{
	int i;
	int j;

	i = 0;
	while (i < nrows)
	{
		j = 0;
		while (j < ncols)
		{
			printf("%i ", map[i][j]);
			j += 1;
		}
		printf("\n");
		i += 1;
	}
}

int		find_smallest(int i, int j, int k)
{
	if (i < j && i < k)
		return (i);
	else if (j < i && j < k)
		return (j);
	else
		return (k);
}

void	size_map(char map[4][8], char *defs, int nrows, int ncols)
{
	int		i;
	int		j;
	int		sizemap[nrows][ncols];

	i = 0;
	while (i < nrows)
	{
		j = 0;
		while (j < ncols)
		{
			if (map[i][j] == defs[0])
			{
		 		if (i == 0 || j == 0)
					sizemap[i][j] = 1;
				else
					sizemap[i][j] = 1 + find_smallest(sizemap[i][j - 1],
							sizemap[i - 1][j], sizemap[i - 1][j - 1]);
			}
			else if (map[i][j] == defs[1])
				sizemap[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
	print_size_map(sizemap, nrows, ncols);
}

int		main(void)
{
	char map[4][8] = {
		{'.', '.', '.', '.', '.', '.', 'o', '.'},
		{'o', 'o', '.', '.', 'o', '.', '.', '.'},
		{'.', 'o', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', 'o', 'o', '.', '.', 'o'}
	};
	char defs[3] = {'.', 'o', 'x'};
	size_map(map, defs, 4, 8);
	return (0);
}
