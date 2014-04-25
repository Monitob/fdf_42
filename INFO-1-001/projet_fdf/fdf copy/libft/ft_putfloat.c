/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 17:55:26 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/13 18:05:12 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putfloat(float f, unsigned int p)
{
	long	l;
	float	r;

	l = (long)f;
	r = 0.5;
	if ((ft_fabs(f - l) >= r) && (p == 0))
		l = ((l > 0) ? l + 1 : l - 1);
	ft_putlong(l);
	f = ft_fabs(f - l);
	if (f > 0 && p != 0)
	{
		write(1, ".", 1);
		while (p--)
		{
			f = f * 10;
			l = (long)f;
			l = l % 10;
			f = f - l;
			ft_putchar(l + 48);
		}
	}
}
