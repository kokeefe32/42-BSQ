/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokeefe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:37:30 by kaokeefe          #+#    #+#             */
/*   Updated: 2019/07/28 13:43:47 by kaokeefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	create_map(char *file_name)
{
	int		fd;
	char	ch;
	
	fd = open(file_name, O_RDONLY);
	while (read(fd, &ch, 1))
		write(1, &ch, 1);
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		create_map(argv[1]);	
}
