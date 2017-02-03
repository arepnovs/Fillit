/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 19:37:02 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/29 10:49:31 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tetr		*ft_move_xy(t_tetr *tetr, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	xmin = 20;
	ymin = 20;
	i = 0;
	while (i != 4)
	{
		if (tetr->x[i] < xmin)
			xmin = tetr->x[i];
		if (tetr->y[i] < ymin)
			ymin = tetr->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		tetr->x[i] = tetr->x[i] - xmin + x;
		tetr->y[i] = tetr->y[i] - ymin + y;
		i++;
	}
	return (tetr);
}

char		**ft_recu_solve(char **tab, t_tetr *tetr, int size)
{
	int		x;
	int		y;
	char	**tmp;

	if (!tetr->next)
		return (tab);
	tmp = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			tetr = ft_move_xy(tetr, x, y);
			if (ft_check(tab, tetr, size))
				tmp = ft_recu_solve(ft_write(tab, tetr, size),
						tetr->next, size);
			if (tmp)
				return (tmp);
			tab = ft_reset(tab, tetr, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

char		**ft_result(t_tetr *tetr, int size)
{
	char	**tab;

	tab = NULL;
	while (!tab)
	{
		tab = ft_empty_map(tab, size);
		tab = ft_recu_solve(tab, tetr, size);
		size++;
	}
	return (tab);
}
