/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:02:00 by bjacob            #+#    #+#             */
/*   Updated: 2013/12/12 11:49:27 by bjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_strs(char **tab, int n)
{
	int		i;
	int		ordered;

	ordered = FALSE;
	while (ordered == FALSE)
	{
		ordered = TRUE;
		i = 0;
		while (i < (n - 1))
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap_ptr((void **)&(tab[i]), (void **)&(tab[i + 1]));
				ordered = FALSE;
			}
			i++;
		}
	}
	return (tab);
}
