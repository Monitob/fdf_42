/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:32:13 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/11 10:00:02 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	res = NULL;
	if (s)
	{
		i = 0;
		res = (char *)malloc((len + 1) * sizeof(char));
		if (res)
		{
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}
