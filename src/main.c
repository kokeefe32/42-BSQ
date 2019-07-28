/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokeefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:37:30 by kaokeefe          #+#    #+#             */
/*   Updated: 2019/07/28 14:35:18 by jiwok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	create_map(char *file_name)
{
	int		fd;
	char	ch;
	
	fd = open(file_name, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
		write(1, &ch, 1);
	close(fd);
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
