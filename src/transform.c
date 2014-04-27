#include <stdio.h>
#include <unistd.h>
#include "fdf.h"

void			list_to_tab(t_grille *head, t_fdf *ptr)
{
	int			i;
	int			j;
	char		**tab_pos;
	t_grille	*temp;
	t_pos		*p;

	temp = head;
	p = ft_single_pos();
	tab_pos = (char **)malloc(sizeof(char *) * size_list(head) + 1);
	while (temp != NULL)
	{
		i = 0;
		read_to_transform(ptr, temp->map++, temp->count++);
		while (temp->map[i] != NULL)
		{
			j = 0;
			set_point(ptr, temp->map, i, temp->count);
			
printf("pos->x_p %d, pso->y_p%d, ps->x_h %d y ps->y_h %d\n", p->x_p, p->y_p, p->x_h, p->y_h);
			tab_pos[i] = ft_strnew(ft_tab_len(temp->map) + 1);
			while (temp->map[i][j] != '\0')
			{
				//ft_draw_line(p->x_p, p->x_p, ptr);
				tab_pos[i][j] = temp->map[i][j];
				j++;
			}
			i++;
		}
		temp = temp->next;
	}
	tab_pos[i] = NULL;
}
