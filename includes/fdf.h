/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 15:22:46 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/21 21:09:30 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# define ESCAPE 65307

typedef struct	s_pos
{
	int		x_p;
	int		x_h;
	int		y_h;
	int		y_p;
	int		z_h;
	int		z_p;	
}				t_pos;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	char	*file;
}				t_fdf;



int		key_control(int key);
void	read_file(int fd, t_fdf *ptr);

#endif
