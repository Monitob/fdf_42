/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:07:44 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/10 17:35:54 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	int				res;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (UCHAR *)s1;
	str2 = (UCHAR *)s2;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	res = (str1[i] - str2[i]);
	return (res);
}
