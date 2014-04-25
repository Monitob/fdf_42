/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 16:34:01 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/13 17:56:36 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putdouble(double d, unsigned int p)
{
	long	l;
	float	r;

	l = (long)d;
	r = 0.5;
	if ((ft_dabs(d - l) >= r) && (p == 0))
		l = ((l > 0) ? l + 1 : l - 1);
	ft_putlong(l);
	d = ft_dabs(d - l);
	if (d > 0 && p > 0)
	{
		write(1, ".", 1);
		while (p--)
		{
			d = d * 10;
			l = (long)d;
			l = l  % 10;
			d = d - l;
			if (p == 0)
				l = (d >= r ? (long)l + 1 : (long)l);
			ft_putchar(l + 48);
		}
	}
}
