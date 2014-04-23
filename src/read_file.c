/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 18:50:11 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/22 16:33:40 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include "fdf.h"

void	tab_to_int(char **tab_char, t_grille **list_tab_int, t_fdf *ptr)
{
	int i;
	int	j;
	int	len_tab;
	int	**tab_int;

	i = 0;
	j = 0;
	len_tab = ft_tab_len(tab_char);
	if (!(tab_int = (int **)malloc(sizeof(int *) * len_tab)))
		return ;
	while (j < len_tab)
	{
		while (tab_char[i] != ft_strchr(tab_char[i], '\n'))
		{
			tab_int[j] = ft_atoi(tab_char[i]);
			printf("tab_to_int %s\n", tab_char[i]);
			i++;
		}
		j++;
	}
	(void)list_tab_int;
	(void)ptr;
}

t_grille	*init_list(t_grille *new)
{
	if (!(new = (t_grille *)malloc(sizeof(t_grille))))
		exit(0);
	new->map = NULL;
	new->next = NULL;
	return (new);
}

void	read_to_transform(t_fdf *ptr, char **map)
{
	int			i;
	char		**tab_char;
	int			len_tab;
	t_grille	*list_tab_int;

	len_tab = ft_tab_len(map);
	list_tab_int = init_list(list_tab_int);
	if (!(tab_char = (char **)malloc(sizeof(char *) * len_tab + 1)))
	 	exit(0);
	tab_char[len_tab + 1] = NULL;
/*recibimos un doble tab sin espacions, esto lo pasamos a un tab de dos dimensiones
que contiene a la vez un tab de dos dimensiones
de esta manerana

tab_loca[tab[sin espacio1], tab[sin espacion 2]]
0tab[0][0] = 10
1tab[0][1] = 10
2tab[1][0] = 10
3tab[1][1] = 10

----------------
    0         
   2  1     
     3       
             
----------------
*/
	i = 0;
	while (map[i] != NULL)
	{
		tab_char[i] = map[i];
		i++;
	}
	tab_to_int(tab_char, &list_tab_int , ptr);
}	

void	read_file(int fd, t_fdf *ptr)
{
	int		ret;
	char	*map;

	while ((ret = get_next_line(fd, &map)))
	{
		printf("map-> %s\n", map);
		read_to_transform(ptr, (ft_strsplit(map, ' ')));
		free(map);
		if (ret == 0)
			break ;
	}
	(void)ptr;
}