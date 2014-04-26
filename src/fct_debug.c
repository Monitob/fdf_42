#include <stdio.h>
#include "fdf.h"

void print_list(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] !='\0')
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}