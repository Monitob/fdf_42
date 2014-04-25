/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 14:10:59 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/10 17:18:35 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (UCHAR *)str;
	while (n > i)
	{
		if (ptr[i] == (UCHAR)c)
			return (&(ptr[i]));
		i++;
	}
	return (NULL);
}
