/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 14:54:22 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/10 14:54:32 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(char const *s)
{
	size_t	i;

	i = ft_strlen(s);
	write(1, s, i);
	write(1, "\n", 1);
}
