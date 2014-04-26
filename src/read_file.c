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


int	ft_abs(int i)
{
	i = (i < 0 ? -i : i);
	return (i);
}

// void		ft_draw_line(t_pix_plan a, t_pix_plan b, t_env *e)
// {
// 	t_pix_plan	d;
// 	t_pix_plan	inc;
// 	t_pix_plan	p;

// 	p.x = a.x;
// 	p.y = a.y;
// 	d.x = b.x - a.x;
// 	d.y = b.y - a.y;
// 	inc.x = ((d.x > 0) ? 1 : -1);
// 	inc.y = ((d.y > 0) ? 1 : -1);
// 	d.x = ft_iabs(d.x);
// 	d.y = ft_iabs(d.y);
// 	mlx_pixel_put(e->mlx, e->win, p.x, p.y, 0xFFFFFF);
// 	if (d.x > d.y)
// 		ft_draw_1(d, inc, p, e);
// 	else
// 		ft_draw_2(d, inc, p, e);
// }

/*oid 	fct_line2(t_fdf *ptr, char **line)
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
	while (i < 20)
	{
		y1 += y_increment;
		x1 += 1;
	//	d += 2 * (pos->x_p - pos->x_h) - (pos->y_p - pos->y_h);
 		mlx_pixel_put(ptr->mlx, ptr->win,x1, y1, 0xee6e1);
		x1++;
		y1++;
		i++;

	}
}
*/
void 	fct_line(t_fdf *ptr, char **line, t_grille *lines)
{
	t_pos		*p;
	t_grille	*temp;
	int			x;


	x = p->x_p;
	p = ft_single_pos();
	temp = lines;
	while (x < 20)
	{
		mlx_pixel_put(ptr->mlx, ptr->win, x, p->y_h, 0xFFFe1);
		temp = temp->next;
		x++;
		printf("pos->x %d pos->y %d\n", x, p->y_h);
	}
}

void	set_point(t_fdf *ptr, char **line, int i, int j)
{
	t_pos	*pos;

	pos = ft_single_pos();
	pos->x_h = VISION * i + VISION * j + PX_INI;
	pos->y_h = PY_INI - (VISION * i) / 3 + (VISION * j) / 3;
	pos->y_h -= 2 * ft_atoi(line[i]);
}

void	read_to_transform(t_fdf *ptr, char **line, int j, t_grille *list)
{
	t_pos		*pos;
	t_grille	*temp;
	int			x;
	int			i;

	x = 0;
	i = 0;
	pos = ft_single_pos();
	temp = list;
	// if (!line1)     last_lign(line2, y, e); else if (!line2)
	// last_lign(line1, y, e);
	while (line[x])
	{
		pos->x_p = VISION * x + VISION * j + PX_INI;
		pos->y_p = PY_INI - (VISION * x) / 3 + (VISION * j) / 3;
		pos->y_p -= 2 * ft_atoi(line[x]);
		mlx_pixel_put(ptr->mlx, ptr->win, pos->x_p, pos->y_p, 0x1797CF);
		if (temp->map[i] != NULL)
		{
		 	set_point(ptr, temp->map, i++, j + 1);
			fct_line(ptr, line, list);
		}
		if (temp->map[i + 1] != NULL)
		{
		 	//set_point(ptr, temp->map, i + 1, j);
		 	fct_line(ptr, temp->map, list);
		}
		x++;
	}
}

int 	size_list(t_grille *head)
{
	t_grille *temp;
	int		i;

	temp = head;
	i = 0;
	while(temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void list_to_tab(t_grille *head)
{
	int			i;
	int			j;
	char		**tab_pos;
	t_grille	*temp;

	i = 0;
	temp = head;
	tab_pos = (char **)malloc(sizeof(char *) * size_list(head) + 1);
	while (temp != NULL)
	{
		while (temp->map[i] != NULL)
		{
			j = 0;
			tab_pos[i] = (char *)malloc(sizeof(char) * ft_tab_len(temp->map) + 1);
			while (temp->map[i][j] != '\0')
			{
				tab_pos[i][j] = temp->map[i][j];
				printf("%c", temp->map[i][j]);
				j++;
			}
			tab_pos[i][j] = '\0';
 				ft_putendl("toot\n");
			i++;
		}
		temp = temp->next;
	}
	tab_pos[size_list(head)] = NULL;
}

void	read_file(int fd, t_fdf *ptr)
{
	int			ret;
	char		*map;
	int			j;
	char		**temp_line;
	t_grille	*list;

	list = NULL;
	j = 0;
	while ((ret = get_next_line(fd, &map)))
	{
		printf("map-> %s\n", map);
		temp_line = ft_strsplit(map, ' ');
		
		line_to_list(new_element(temp_line), &list);
		read_to_transform(ptr, temp_line, j++, list);
		free(map);
		if (ret == 0)
			break ;
	}
	list_to_tab(list);
	//show_list(list);
}
