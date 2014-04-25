/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:33:19 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/12 15:46:18 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cpy;
	size_t	i;

	cpy = NULL;
	if (s)
	{
		i = 0;
		cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (cpy)
		{
			while (ft_isspace(*s))
				s++;
			while (s[i] != '\0')
			{
				cpy[i] = s[i];
				i++;
			}
			i--;
			while (ft_isspace((UCHAR)cpy[i]))
				i--;
			cpy[i + 1] = '\0';
		}
	}
	return (cpy);
}
