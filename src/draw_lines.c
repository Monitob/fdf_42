#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include "fdf.h"

void	set_point(t_fdf *ptr, char **line, int i, int j)
{
	t_pos	*pos;

	pos = ft_single_pos();
	pos->x_h = VISION * i + VISION * j + PX_INI;
	pos->y_h = PY_INI - (VISION * i) / 3 + (VISION * j) / 3;
	pos->y_h -= 2 * ft_atoi(line[i]);
	mlx_pixel_put(ptr->mlx, ptr->win, pos->x_h, pos->y_h, 0xFF3300);
}

#include "fdf.h"

static void		ligne_a(t_fdf *ptr, int y1, int y2, int x2, int x1)
{
	int 	d;
	int		xincr;
	int 	x;
	int 	y;

	// if (y1 > >y2)
	// 	change(&point->x1, &point->x2, &point->y1, &point->y2);
	xincr = y2 > y1 ? 1 : -1;
	d = 2 * ft_abs(x2 - x1) - (y2 - y1);
	x = point->x1;
	y = point->y1;
	verif_print(e, x, y);
	while (y++ <= point->y2)
	{
		if (d >= 0)
		{
			x += xincr;
			d += 2 * (ft_abs(point->x2 - point->x1) - (point->y2 - point->y1));
		}
		else
			d = d + 2 * ft_abs(point->x2 - point->x1);
		verif_print(e, x, y);
	}
}
static void		ligne_b(t_fdf *ptr, t_xyz *point)
{
	int 	d;
	int 	yincr;
	int 	x;
	int		y;

	if (point->x1 > point->x2)
		change(&point->x1, &point->x2, &point->y1, &point->y2);
	yincr = point->y2 > point->y1 ? 1 : -1;
	d = 2 * ft_abs(point->y2 - point->y1) - (point->x2 - point->x1);
	x = point->x1;
	y = point->y1;
	verif_print(e, x, y);
	while (x++ <= point->x2)
	{
		if (d >= 0)
		{
			y += yincr;
			d += 2 * (ft_abs(point->y2 - point->y1) - (point->x2 - point->x1));
		}
		else
			d = d + 2 * ft_abs(point->y2 - point->y1);
		verif_print(e, x, y);
	}
}

void			ligne(t_fdf *ptr, t_xyz *point)
{
	if (ft_abs(point->x2 - point->x1) < ft_abs(point->y2 - point->y1))
		ligne_a(e, point);
	else
		ligne_b(e, point);
}
