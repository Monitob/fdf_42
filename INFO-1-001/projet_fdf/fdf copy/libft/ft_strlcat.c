/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:17:08 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/10 15:17:34 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	n;
	size_t	res;

	n = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (dlen >= size)
		return (size + slen);
	res = dlen + slen;
	while (src[n] != '\0' && dlen < (size - 1))
	{
		dest[dlen] = src[n];
		dlen++;
		n++;
	}
	dest[dlen] = '\0';
	return (res);
}
