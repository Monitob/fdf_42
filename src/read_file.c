
#include <stdio.h> //
#include "fdf.h"

void	read_file(int fd, t_fdf *ptr)
{
	int		ret;
	char	*map;

	while ((ret = get_next_line(fd, &map)))
	{
		printf("map-> %s\n", map);
		if (ret == 0)
			break ;
	}
	(void)ptr;	
	//dont forget to free map;
}