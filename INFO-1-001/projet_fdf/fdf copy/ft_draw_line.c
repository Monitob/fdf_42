/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:55:40 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/21 15:46:44 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_1(t_pix_plan d, t_pix_plan inc, t_pix_plan p, t_env *e);
void	ft_draw_2(t_pix_plan d, t_pix_plan inc, t_pix_plan p, t_env *e);

void		ft_draw_line(t_pix_plan a, t_pix_plan b, t_env *e)
{
	t_pix_plan	d;
	t_pix_plan	inc;
	t_pix_plan	p;

	p.x = a.x;
	p.y = a.y;
	d.x = b.x - a.x;
	d.y = b.y - a.y;
	inc.x = ((d.x > 0) ? 1 : -1);
	inc.y = ((d.y > 0) ? 1 : -1);
	d.x = ft_iabs(d.x);
	d.y = ft_iabs(d.y);
	mlx_pixel_put(e->mlx, e->win, p.x, p.y, 0xFFFFFF);
	if (d.x > d.y)
		ft_draw_1(d, inc, p, e);
	else
		ft_draw_2(d, inc, p, e);
}

void	ft_draw_1(t_pix_plan d, t_pix_plan inc, t_pix_plan p, t_env *e)
{
	int	i;
	int cumul;

	i = 1;
	cumul = d.x / 2;
	while (i <= d.x)
	{
		p.x += inc.x;
		cumul += d.y;
		if ( cumul >= d.x )
		{
			cumul -= d.x;
			p.y += inc.y;
		}
		mlx_pixel_put(e->mlx, e->win, p.x, p.y, 0xFFFFFF);
		i++;
	}
}

void	ft_draw_2(t_pix_plan d, t_pix_plan inc, t_pix_plan p, t_env *e)
{
	int	i;
	int cumul;

	i = 1;
	cumul = d.y / 2;
	while(i <= d.y)
	{
		p.y += inc.y;
		cumul += d.x;
		if ( cumul >= d.y )
		{
			cumul -= d.y;
			p.x += inc.x ;
		}
		mlx_pixel_put(e->mlx, e->win, p.x, p.y, 0xFFFFFF);
		i++;
	}
}
