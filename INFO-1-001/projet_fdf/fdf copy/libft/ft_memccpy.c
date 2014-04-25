/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 14:08:01 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/10 17:13:50 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)dest;
	str2 = (char *)src;
	i = 0;
	while (n > i)
	{
		str1[i] = str2[i];
		if (str2[i] == (UCHAR)c)
			return (&str1[(i + 1)]);
		i++;
	}
	return (NULL);
}
