/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:02:46 by arepnovs          #+#    #+#             */
/*   Updated: 2017/01/03 18:23:22 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_f(char *str, int i)
{
	if (str[i + 1] != '#' && str[i + 5] != '#'
			&& (str[i - 1] == '#' || str[i - 5] == '#'))
	{
		if (str[i + 4] != '#' || str[i - 1] != '#')
			return (0);
	}
	if (str[i + 5] == '#' && str[i + 10] != '#'
			&& str[i + 1] != '#' && str[i + 6] != '#' && str[i - 1] != '#'
			&& str[i + 4] != '#')
		return (0);
	return (1);
}

int		tetr_check(char *str, size_t i)
{
	int	f;

	f = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] != '#' && str[i + 5] != '#'
					&& (str[i - 1] == '#' || str[i - 5] == '#'))
				f++;
			else if (str[i + 1] == '#' || str[i + 5] == '#')
				f++;
			else if ((str[i + 1] != '#' && str[i + 5] != '#'))
				return (0);
			if (f == 2 && check_f(str, i) == 0)
				return (0);
			if (f == 4)
				f = 0;
		}
		i++;
	}
	return (1);
}

int		m_check(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '2')
			return (1);
		i++;
	}
	return (0);
}

int		s_check(char *str)
{
	int	s;

	s = 4;
	while (*str)
	{
		if (str[s] == '\n' && (str[s + 2] == '.' || str[s + 2] == '#'))
		{
			if (str[s + 1] == '1')
				s = s + 5;
			else
				s = s + 4;
		}
		else if (str[s] != '\n' && (str[s + 2] == '.' || str[s + 2] == '#'))
			return (0);
		str++;
	}
	return (1);
}

int		f_check(char *str)
{
	int	p;
	int	sh;
	int	i;

	p = 0;
	sh = 0;
	i = 0;
	while (*str)
	{
		if (*str == '.')
			p++;
		else if (*str == '#')
			sh++;
		else if (*str == '1' || *str == '2')
			i++;
		if ((*str == '1' || *str == '2') && ((p / i) != 12 || (sh / i) != 4
					|| (p / sh) != 3 || i > 26))
			return (0);
		str++;
	}
	return (i);
}
