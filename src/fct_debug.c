#include <stdio.h>
#include "fdf.h"

void print_list(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("map recibido %s\n", map[i]);
		i++;
	}
}