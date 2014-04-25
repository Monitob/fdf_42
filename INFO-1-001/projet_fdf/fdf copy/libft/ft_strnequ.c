/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:24:20 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/11 09:56:33 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		res;
	size_t	i;

	res = 0;
	if (s1 && s2)
	{
		i = 0;
		while (s1[i] != '\0' && i < n)
		{
			if (s1[i] != s2[i])
				return (res);
			i++;
		}
		res = (i == n || s2[i] == '\0') ? 1 : 0;
	}
	return (res);
}
