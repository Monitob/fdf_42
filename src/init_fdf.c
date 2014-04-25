/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 15:05:55 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/25 18:38:44 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <mlx.h>
#include "fdf.h"

static int		expose_hook(t_fdf *ptr)
{
	int 	fd;

	if ((fd = open(ptr->file, O_RDONLY)) == -1)
	{
		perror("Cannot open output file\n");
		exit(0);
	}
	read_file(fd, ptr);
	return (0);
}

t_pos	*ft_single_pos()
{
	static	t_pos	*cor = NULL;

	if (cor == NULL)
	{
		if (!(cor = (t_pos *)malloc(sizeof(t_pos))))
			return (NULL);
		cor->x_p = 0;
		cor->x_h = 0;
		cor->y_p = 0;
		cor->y_h = 0;
		cor->z_h = 0;
		cor->y_p = 0;
	}
	return (cor);
}


int	main(int ac, char **av)
{
	t_fdf	ptr;

	if (ac > 1)
	{
		ptr.mlx = mlx_init();
		ptr.win = mlx_new_window(ptr.mlx, 1280, 1100, "Rtv");
		ptr.file = ft_strdup(av[1]);
		mlx_expose_hook(ptr.win, expose_hook, &ptr);
		mlx_key_hook(ptr.win, &key_control, &ptr);
		mlx_loop(ptr.mlx);
	}
	else
	{
		ft_putendl("Usage: ./fdf map.fdf ");
		return (0);
	
	}
	return (0);
}
