/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data_in_tetr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 19:34:51 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/29 10:40:32 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tetr		*ft_put_in_tetr(char *str)
{
	int		i;
	int		j;
	char	c;
	t_tetr	*tetr;
	t_tetr	*tmp;

	j = 0;
	c = 64;
	i = f_check(str);
	if (!(tetr = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	tmp = tetr;
	while (i > 0)
	{
		tmp->str = ft_strndup(&str[j], 20);
		tmp->c = ++c;
		j = j + 21;
		if (!(tmp->next = (t_tetr *)malloc(sizeof(t_tetr))))
			return (NULL);
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	return (tetr);
}

t_tetr		*ft_find_xy(t_tetr *tetr, char **s)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '#')
			{
				tetr->x[i] = x;
				tetr->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (tetr);
}

t_tetr		*ft_put_xy_in_tetr(t_tetr *tetr)
{
	t_tetr	*tmp;

	tmp = tetr;
	while (tetr->next)
	{
		tetr = ft_find_xy(tetr, ft_strsplit(tetr->str, '\n'));
		free(tetr->str);
		tetr = tetr->next;
	}
	return (tmp);
}
