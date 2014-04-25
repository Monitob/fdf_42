/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 08:10:15 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/12 11:06:20 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_startswith(const char *str, const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && str[i] == s[i])
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}