/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:10:57 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/10 15:11:11 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	i;
	size_t	n;

	i = ft_strlen(str);
	cpy = (char *)malloc((i + 1) * sizeof(char));
	if (cpy)
	{
		n = 0;
		while (str[n] != '\0')
		{
			cpy[n] = str[n];
			n++;
		}
		cpy[n] = '\0';
	}
	return (cpy);
}
