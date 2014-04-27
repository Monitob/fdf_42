/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 18:50:11 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/26 22:30:26 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "fdf.h"

void			read_to_transform(t_fdf *ptr, char **line, int j)
{
	t_pos		*pos;
	int			x;
	int			i;

	x = 0;
	i = 0;
	pos = ft_single_pos();
	while (line[x])
	{
		pos->x_p = VISION * x + VISION * j + PX_INI;
		pos->y_p = PY_INI - (VISION * x) / 3 + (VISION * j) / 3;
		pos->y_p -= 2 * ft_atoi(line[x]);
		mlx_pixel_put(ptr->mlx, ptr->win, pos->x_p, pos->y_p, 0x1797CF);
		x++;
	}

}


void			first_read(int fd, t_fdf *ptr)
{
	int			ret;
	char		*map;
	t_grille	*list;
	int			j;

	list = NULL;
	j = 0;
	while ((ret = get_next_line(fd, &map)))
	{
		line_to_list(new_element(ft_strsplit(map, ' ')), &list);
		read_to_transform(ptr, ft_strsplit(map, ' '), j++);
		free(map);
		if (ret == 0)
			break ;
	}
	list_to_tab(list, ptr);
	close(fd);
}
