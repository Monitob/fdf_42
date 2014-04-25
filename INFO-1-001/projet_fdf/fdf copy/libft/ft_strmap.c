/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:18:55 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/11 09:54:02 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*res;
	unsigned int	i;

	res = NULL;
	if (s && f)
	{
		i = 0;
		res = (char *)malloc((ft_strlen(s)) * sizeof(char) + 1);
		if (res)
		{
			while (s[i] != '\0')
			{
				res[i] = f(s[i]);
				i++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}
