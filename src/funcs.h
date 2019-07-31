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
	int i;
	int j;
	int size;
} sqre;

int		ft_atoi(char *str);
sqre	size_map(char **map, char *defs, int nrows, int ncols);

#endif
