/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:13:55 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/18 17:57:31 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_env
{
	int			ac;
	void		*mlx;
	void		*win;
	char		**av;
}				t_env;

typedef struct	s_pix_space
{
	int			x;
	int			y;
}				t_pix_space;

typedef struct	s_pix_plan
{
	int			x;
	int			y;
}				t_pix_plan;

int			expose_hook(t_env *e);
int			key_hook(int keycode, t_env *e);
int			ft_open_matrix(int argc, char **argv);
int			ft_link_pix(t_pix_plan *plan, int i, t_pix_plan var, t_env *e);

void		ft_display_pix(void *mlx, void *win, t_pix_plan p, int color);
void		ft_draw_line(t_pix_plan a, t_pix_plan b, void *mlx, void *win);

t_pix_plan	*ft_turn_space_to_plan(t_pix_space *m, int end);
t_pix_space	*ft_init_space(int argc, char **argv, int *i, int *nb);

#endif /* !FDF_H */
