/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 18:27:40 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/29 10:49:34 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error(int i)
{
	char *err0;
	char *err1;

	err0 = "usage: ./fillit target_file";
	err1 = "error";
	if (i == 0)
		ft_putendl(err0);
	else if (i == 1)
		ft_putendl(err1);
	exit(0);
}

char	*ft_read_file(char *file)
{
	char	buf[600];
	char	*str;
	size_t	ret;
	int		fd;

	str = (char*)ft_memalloc(sizeof(char));
	if ((fd = open(file, O_RDONLY)) == -1)
		error(1);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		if (ret == 21 || ret == 20)
		{
			if (ret == 20)
				buf[ret] = '2';
			else
				buf[ret - 1] = '1';
			str = ft_strjoin(str, buf);
		}
		else
			error(1);
	}
	close(fd);
	return (str);
}

int		main(int argc, char **argv)
{
	size_t	i;
	char	*file;
	char	**res;
	t_tetr	*tetr;

	i = 0;
	res = NULL;
	if (argc != 2)
		error(0);
	else
	{
		file = ft_read_file(argv[1]);
		if (m_check(file) != 0 && f_check(file) != 0
				&& s_check(file) == 1 && tetr_check(file, i) == 1)
		{
			tetr = ft_put_in_tetr(file);
			tetr = ft_put_xy_in_tetr(tetr);
			res = ft_result(tetr, ft_map_size(tetr));
			free(tetr);
		}
		else
			error(1);
		ft_arr_putstr(res);
	}
	return (0);
}
