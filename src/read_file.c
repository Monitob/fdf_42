/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 18:50:11 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/22 16:33:40 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include <stdlib.h>
#include "fdf.h"


void	read_to_transform(t_fdf *ptr, char **line, int j)
{
	t_pos 	*pos;
	int		x;
	int		x2;

	x = 0;
	x2 = 0;
	pos = ft_single_pos();
	// if (!line1)
	// 	last_lign(line2, y, e);
	// else if (!line2)
	// 	last_lign(line1, y, e);
	while (line[x])
	{
		pos->x_p = VISION * x + VISION * j + PX_INI;
		pos->y_p = PY_INI - (VISION * x) / 3 + (VISION * j) / 3;
		pos->y_p -= 2 * ft_atoi(line[x]);
		// if (line2[x2] != '\0')
		// {
		// 	set_point(&pos, line2, x2++, y + 1);
		// 	ligne(e, &pos);
		// }
		// if (line[x + 1])
		// 	set_point(&pos, line1, x + 1, y);
		// ligne(e, &pos);
		x++;
	}
}


void	read_file(int fd, t_fdf *ptr)
{
	int			ret;
	char		*map;
	int			j;
	t_grille	*list;

	list = NULL;
	j = 0;
	while ((ret = get_next_line(fd, &map)))
	{
		printf("map-> %s\n", map);
		read_to_transform(ptr, ft_strsplit(map, ' '), j++);
		free(map);
		if (ret == 0)
			break ;
	}
	(void)ptr;
}