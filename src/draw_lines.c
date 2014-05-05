/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:45:46 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/30 16:25:22 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include "fdf.h"



void			set_point(t_fdf *ptr, char **line, int i, int j)
{
	t_pos	*pos;

	pos = ft_single_pos();
	pos->x_h = VISION * i + VISION * j + PX_INI;
	pos->y_h = PY_INI - (VISION * i) / 3 + (VISION * j) / 3;
	pos->y_h -= 2 * ft_atoi(line[i]);
	mlx_pixel_put(ptr->mlx, ptr->win, pos->x_h, pos->y_h, 0xFF3300);
}
