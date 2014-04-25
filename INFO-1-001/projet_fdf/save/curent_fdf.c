/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curent_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:49:10 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/18 17:21:27 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pix_space	*ft_init_space(int argc, char **argv, int *i, int *nb)
{
	int	 fd;
	t_pix_plan	p;
	char	 **tab;
	t_pix_space	*space = NULL;
	char	 *line;

	space = (t_pix_space *)malloc(sizeof(t_pix_space) * 500000000);
	p.x = 0;
	fd = ft_open_matrix(argc, argv);
	if (fd == -1)
	{	
		space[0].x = 0;
		space[0].y = 0;
		return (space);
	}
	while (ft_get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		p.y = 0;
		while (tab[p.y] != NULL)
		{
			space[*i].x = p.x + 1;
			space[*i].y = p.y + 1;
			space[*i].z = ft_atoi(tab[p.y]);
			p.y++;
			(*i)++;
		}
		*nb = p.y;
		p.x++;
	}
	space[*i].x = 0;
	return (space);
}

int	 ft_open_matrix(int argc, char **argv)
{
	int	 fd;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("test_42_2.txt", O_RDONLY);
	return (fd);
}

void	 ft_display_pix(void *mlx, void *win, t_pix_plan p, int color)
{
	if (mlx == NULL || win == NULL)
		exit(0);
	mlx_pixel_put(mlx, win, p.x, p.y, color);
}

t_pix_plan	*ft_turn_space_to_plan(t_pix_space *m, int end)
{
	int	 i;
	t_pix_plan	*p;

	i= 0;
	p = (t_pix_plan *)malloc(sizeof(t_pix_plan) * end + 1);
	while (i < end)
	{
		p[i].x = 800 + (-5 * m[i].x) + (4 * m[i].y) + (0 * m[i].z);
		p[i].y = 390 + (0 * m[i].x) + (4 * m[i].y) + (-1 * m[i].z);
		i++;
	}
	return (p);
}
