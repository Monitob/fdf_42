/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 12:03:53 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/10 12:04:00 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		res;

	res = 0;
	while (ft_isblank(*str) == 1)
		str = str + 1;
	i = ((*str == '+' || *str == '-') ? 1 : 0);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (str[0] == '-')
		res = res * (-1);
	return (res);
}
