/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:23:59 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/18 17:31:50 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	 expose_hook(t_env *e)
{
	t_pix_space	*space = NULL;
	t_pix_plan	*plan = NULL;
	int	 i;
	t_pix_plan	var;

	i = 0;
	var.x = 0;
	space = ft_init_space(e->ac, e->av, &var.x, &var.y);
	plan = ft_turn_space_to_plan(space, var.x);
	while (space[i].x != 0)
	{
		if (space[i].z == 0)
		{
			i = ft_link_pix(plan, i, var, e);
		}
		else 
		{
			i = ft_link_pix(plan, i, var, e);
		}
	}
	return (0);
}

int	 ft_link_pix(t_pix_plan *plan, int i, t_pix_plan var, t_env *e)
{
	if (((i + 1) % var.y) != 0 && i < (var.x - var.y))
	{	
		ft_draw_line(plan[i], plan[i + 1], e->mlx, e->win);
		ft_draw_line(plan[i + var.y], plan[i], e->mlx, e->win);
	}
	if (((i + 1) % var.y) == 0 && i < (var.x - var.y))
		ft_draw_line(plan[i + var.y], plan[i], e->mlx, e->win);
	if (((i + 1) % var.y) != 0 && i >= (var.x - var.y))
		ft_draw_line(plan[i], plan[i + 1], e->mlx, e->win);
	i++;
	return (i);
}

int	 key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}
