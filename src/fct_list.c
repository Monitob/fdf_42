/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:45:46 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/27 22:40:11 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void			show_list(t_grille *head)
{
	t_grille	*temp;

	temp = head;
	while (temp != NULL)
	{
		print_list(temp->map);
		temp = temp->next;
	}
}

void			line_to_list(t_grille *new_line, t_grille **head)
{
	t_grille	*temp;
	int			counter;

	temp = *head;
	counter = 1;
	if (temp == NULL)
	{
		*head = new_line;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}
	temp->next = new_line;
	new_line->count = counter;
	return ;
}

t_grille		*new_element(char **map_c)
{
	t_grille	*new;

	if (!(new = (t_grille *)malloc(sizeof(t_grille))))
		return (NULL);
	new->map = map_c;
	new->count = 0;
	new->next = NULL;
	return (new);
}
