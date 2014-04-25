/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:30:12 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/10 15:30:38 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			n = 1;
			while ((s1[i + n] == s2[n]) && (s1[i + n] != '\0'))
				n++;
			if (s2[n] == '\0')
				return ((char *)&(s1[i]));
		}
		i++;
	}
	return (NULL);
}
