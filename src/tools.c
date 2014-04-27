#include <fcntl.h>
#include "fdf.h"

int		ft_abs(int i)
{
	i = (i < 0 ? -i : i);
	return (i);
}

int		ft_open(char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Cannot open output file\n");
		exit(0);
	}
	return (fd);
}

int 	size_list(t_grille *head)
{
	t_grille	*temp;
	int			i;

	temp = head;
	i = 0;
	while(temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}