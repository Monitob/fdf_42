/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:45:46 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/27 22:48:16 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include "fdf.h"

void			verif_print(t_fdf *ptr, int x, int y)
{
	if (x >= 0 && x <= 2000 && y >= 0 && y <= 1200)
		mlx_pixel_put(ptr->mlx, ptr->win, x, y, 0x1797CF);
}

void			change(int *x1, int *y1, int *x2, int *y2)
{
	int		t;

	t = *x1;
	*x1 = *y1;
	*y1 = t;
	t = *x2;
	*x2 = *y2;
	*y2 = t;
}

int				ft_abs(int i)
{
	i = (i < 0 ? -i : i);
	return (i);
}

int				ft_open(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Cannot open output file\n");
		exit(0);
	}
	return (fd);
}

int				size_list(t_grille *head)
{
	t_grille	*temp;
	int			i;

	temp = head;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
