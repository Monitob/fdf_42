/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curent_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:49:10 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/21 16:52:38 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pix_space		*ft_init_space(int argc, char **argv, int *i, int *nb)
{
	int			fd;
	t_pix_plan	p;
	char		**tab;
	t_pix_space	*space;
	char		*line;

	space = (t_pix_space *)malloc(1000000000);
	p.x = 0;
	fd = ft_open_matrix(argc, argv);
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		*nb = 0;
		while (tab[*nb] != NULL)
		{
			space[*i].x = p.x + 1;
			space[*i].y = *nb + 1;
			space[*i].z = ft_atoi(tab[*nb]);
			(*nb)++;
			(*i)++;
		}
		p.x++;
	}
	space[*i].x = 0;
	return (space);
}

int				ft_open_matrix(int argc, char **argv)
{
	int		fd;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
	{
		write(1, "fdf usage: ./fdf [files]", 24);
		exit(0);
	}
	if (fd == -1)
	{
		write(1, "open() fail", 11);
		exit(0);
	}
	return (fd);
}

t_pix_plan		*ft_turn_space_to_plan(t_pix_space *m, int end)
{
	int			i;
	t_pix_plan	*p;

	i = 0;
	p = (t_pix_plan *)malloc(sizeof(t_pix_plan) * end + 1);
	while (i < end)
	{
		p[i].x = 950 + (-50 * m[i].x) + (35 * m[i].y) + (1 * m[i].z);
		p[i].y = 5 + (20 * m[i].x) + (40 * m[i].y) + (-5 * m[i].z);
		i++;
	}
	return (p);
}
