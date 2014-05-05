/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:45:46 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/30 17:25:16 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"
#include "mlx.h"
#include "stdio.h"


void			ft_draw_line(t_point p1, t_point p2, t_fdf *ptr)
{
	float	a;
	float	b;

	a = (p1.y - p2.y) / (p1.x - p2.x);
	b = p1.y - a * p1.x;
	while (p1.x != p2.x)
	{
		mlx_pixel_put(ptr->mlx, ptr->win, p1.x, p1.y, 0xffffff);
		p1.x += (p1.x > p2.x) ? -1 : 1;
		p1.y = a * p1.x + b;
	}
}

void			ft_draw(t_point p1, t_grille *li, int i, t_fdf *ptr)
{
	t_point	p2;

	if (li->map[i + 1])
	{
		p2.x = p1.x + 20;
		p2.y = p1.y + 20 - atoi(li->map[i + 1]) + atoi(li->map[i]);
//		p2.y = p1.y + 20;
		ft_draw_line(p1, p2, ptr);
	}
	if (li->next)
	{
		p2.x = p1.x - 20;
		p2.y = p1.y + 20 - atoi(li->next->map[i]) + atoi(li->map[i]);
//		p2.y = p1.y + 20;
		ft_draw_line(p1, p2, ptr);
	}
}

void			list_to_tab(t_grille *head, t_fdf *ptr)
{
	int			i;
	int			j;
	t_grille	*temp;
	t_pos		*p;
	t_point		p1;
	t_point		tmp;

	p1.x = PX_INI;
	p1.y = PY_INI;
	while (head)
	{
		i = 0;
		tmp.x = p1.x;
		tmp.y = p1.y;
		while (head->map[i])
		{
			p1.x += 20;
//			p1.y += 20;
			if (i > 0)
				p1.y += 20 - atoi(head->map[i]) + atoi(head->map[i - 1]);
			else
				p1.y += 20 - atoi(head->map[i]);
						printf("%s\n", head->map[i]);
			mlx_pixel_put(ptr->mlx, ptr->win, p1.x, p1.y, 0xffffff);
			ft_draw(p1, head, i, ptr);
			i++;
		}
		p1.x = tmp.x - 20;
		p1.y = tmp.y + 20;
		printf("\n\n\n");
		head = head->next;
	}
	(void)p1;
	return ;
	temp = head;
	p = ft_single_pos();
	while (temp != NULL)
	{
		i = 0;
		read_to_transform(ptr, temp->map++, temp->count++);
		while (temp->map[i] != NULL)
		{
			j = 0;
			set_point(ptr, temp->map, i, temp->count);
			while (temp->map[i][j] != '\0')
			{
				j++;
			}
			i++;
		}
		temp = temp->next;
	}
}
