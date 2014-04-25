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
#include <math.h>
#include "fdf.h"



void 	fct_line2(t_fdf *ptr, char **line)
{
	t_pos	*pos;
	int		x1;
	int		y1;
	int		d;
	int 	y_increment;
	int 	i;

	i = 0;
	pos = ft_single_pos();
	x1 = pos->x_p;
	y1 = pos->y_p;
	y_increment = pos->y_h > pos->y_p ? 1 : -1;
	d = 2 * (pos->x_h - pos->x_p) - (pos->y_h - pos->y_p);
	while (line[i])
	{
		y1 += y_increment;
		d += 2 * (pos->x_p - pos->x_h) - (pos->y_p - pos->y_h);
 		mlx_pixel_put(ptr->mlx, ptr->win,x1, y1, 0xFFF7AF);
		x1++;
		y1++;
		i++;

	}
}

void 	fct_line(t_fdf *ptr, char **line)
{
	t_pos	*pos;
	int		x1;
	int		y1;
	int		d;
	int 	i;
	int 	x_increment;

	pos = ft_single_pos();
	y1 = pos->y_p;
	x1 = pos->x_p;
	i = 0;
	x_increment = pos->x_p > pos->x_h ? 1 : -1;
	d = 2 * (pos->x_p + pos->x_h) - (pos->y_p - pos->y_h);
	while (line[i])
	{
		printf("valor de d %i pos->x_p %i pos->x_p %i\n", d, pos->x_p, pos->y_p);
		//print_list(line);
		x1 += x_increment;
		//d += 2 * (pos->x_h - pos->x_p) - (pos->y_h - pos->y_p);
 		mlx_pixel_put(ptr->mlx, ptr->win,x1, y1, 0xFA97AF);
		x1++;
		i++;
		y1++;;
	}
	fct_line2(ptr, line);
}

void	read_to_transform(t_fdf *ptr, char **line, int j)
{
	t_pos 	*pos;
	int		x;
	int		x2;

	x = 0;
	x2 = 0;
	pos = ft_single_pos();
	// if (!line1)     last_lign(line2, y, e); else if (!line2)
	// last_lign(line1, y, e);
	while (line[x])
	{
		pos->x_p = VISION * x + VISION * j + PX_INI;
		pos->y_p = PY_INI - (VISION * x) / 3 + (VISION * j) / 3;
		pos->y_p -= 2 * ft_atoi(line[x]);
		pos->x_h = VISION * x + VISION * j + PX_INI;
		pos->y_h = PY_INI - (VISION * x) / 3 + (VISION * j) / 3;
		pos->y_h -= 2 * ft_atoi(line[x]);
		mlx_pixel_put(ptr->mlx, ptr->win, pos->x_p, pos->y_p, 0x1797CF);
		mlx_pixel_put(ptr->mlx, ptr->win, pos->x_h, pos->y_h, 0xf797CF);
		fct_line(ptr, line);
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