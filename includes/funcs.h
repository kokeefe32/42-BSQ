/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwok <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:15:17 by jiwok             #+#    #+#             */
/*   Updated: 2019/07/29 14:18:27 by jiwok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

typedef struct {
	int		i;
	int		j;
	int		size;
}			sqre;

typedef struct {
	char	**arr;
	int		**sizearr;
}			mem;

int			ft_atoi(char *str);
int			ft_read_input(void);
sqre		size_map(mem a, char *defs, int nrows, int ncols);

#endif
