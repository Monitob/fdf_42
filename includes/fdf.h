/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 15:22:46 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/26 22:35:08 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# define ESCAPE 65307
# define VISION 20
# define PX_INI 100
# define PY_INI 300

typedef struct	s_pos
{
	int		x_p;
	int		x_h;
	int		y_h;
	int		y_p;
	int		z_h;
	int		z_p;
	int		dx;
	int		dy;	
}				t_pos;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	char	*file;
}				t_fdf;

typedef struct 		s_grille
{
	char			**map;
	int				count;
	struct s_grille	*next;
}					t_grille;


int			key_control(int key);
int			ft_open(char *file);
int			ft_abs(int i);
void		read_to_transform(t_fdf *ptr, char **line, int j);
void		show_list(t_grille *head);
int			size_list(t_grille *head);
void		set_point(t_fdf *ptr, char **line, int i, int j);
void		line_to_list(t_grille *new_line, t_grille **head);
void		first_read(int fd, t_fdf *ptr);
void		print_list(char **map);
t_grille	*new_element(char **map_c);
t_pos		*ft_single_pos();
void		fct_line(t_fdf *ptr, char **line, t_grille *lines);
void		list_to_tab(t_grille *head, t_fdf *ptr);

#endif
