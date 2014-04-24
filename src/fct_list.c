#include <stdio.h>
#include "fdf.h"

void 		show_list(t_grille *head)
{
	t_grille	*temp;


	temp = head;
	
	while (temp != NULL)
	{
		print_list(temp->map);
		temp = temp->next;
	}
}

void		line_to_list(t_grille *new_line, t_grille **head)
{
	t_grille	*temp;

	temp = *head;
	if (temp == NULL)
	{
		ft_putendl("entro en el head");
		*head = new_line;
		return ;
	}
	while (temp->next != NULL)
	{
		ft_putendl("entro en la boucle");
		temp = temp->next;
	}
	temp->next = new_line;
		ft_putendl("salgo de line to list");
	return ;
}

t_grille	*new_element(char ***map_c)
{
	t_grille	*new;

	new = (t_grille *)malloc(sizeof(t_grille));
	new->map = *map_c;
	new->next = NULL;
	return (new);
}