/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 20:05:28 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/29 10:49:29 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_reset(char **tab, t_tetr *tetr, int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tab[y][x] == tetr->c)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

char		**ft_write(char **tab, t_tetr *tetr, int size)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetr->x[i] == x && tetr->y[i] == y)
			{
				tab[y][x] = tetr->c;
				i++;
			}
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

int			ft_check(char **tab, t_tetr *tetr, int size)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetr->x[i] == x && tetr->y[i] == y && tab[y][x] != '.')
				return (0);
			else if (tetr->x[i] == x && tetr->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

char		**ft_empty_map(char **tab, int size)
{
	int y;
	int x;

	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		tab[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

int			ft_map_size(t_tetr *tetr)
{
	int	i;
	int	size;

	i = 0;
	size = 2;
	while (tetr->next)
	{
		i++;
		tetr = tetr->next;
	}
	while (size * size < i * 4)
		size++;
	return (size);
}
