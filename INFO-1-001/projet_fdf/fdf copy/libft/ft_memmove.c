/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 14:18:15 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/10 14:33:45 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cpysrc;

	i = 0;
	cpysrc = (char *)malloc(n * sizeof(char));
	ft_memcpy(cpysrc, src, n);
	ft_memcpy(dest, cpysrc, n);
	free (cpysrc);
	return (dest);
}
