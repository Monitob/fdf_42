/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:55:40 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/18 16:19:08 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_pix_plan a, t_pix_plan b, void *mlx, void *im)
{
	int dx,dy,i,xinc,yinc,cumul ;
	t_pix_plan p;

	p.x = a.x ;
	p.y = a.y ;
	dx = b.x - a.x ;
	dy = b.y - a.y ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = ft_abs(dx) ;
	dy = ft_abs(dy) ;
	mlx_pixel_put(mlx, im, p.x, p.y, 0xFFFFFF);
	if ( dx > dy )
	{
		cumul = dx / 2 ;
		for ( i = 1 ; i <= dx ; i++ )
		{
			p.x += xinc ;
			cumul += dy ;
			if ( cumul >= dx )
			{
				cumul -= dx ;
				p.y += yinc ;
			}
			mlx_pixel_put(mlx, im, p.x, p.y, 0xFFFFFF);
		}
	}
	else
	{
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ )
		{
			p.y += yinc ;
			cumul += dx ;
			if ( cumul >= dy )
			{
				cumul -= dy ;
				p.x += xinc ;
			}
			mlx_pixel_put(mlx, im, p.x, p.y, 0xFFFFFF);
		}
	}
}
