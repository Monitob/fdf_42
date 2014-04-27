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
			ft_putchar(map[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}