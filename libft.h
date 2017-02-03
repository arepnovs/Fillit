/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:56:17 by arepnovs          #+#    #+#             */
/*   Updated: 2016/12/24 20:22:21 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_tetr
{
	char			c;
	char			*str;
	int				x[4];
	int				y[4];
	struct s_tetr	*next;
}					t_tetr;

size_t				ft_strlen(const char *str);
void				*ft_memalloc(size_t size);
char				*ft_strjoin(const char *s1, const char *s2);
void				ft_putendl(char *str);
char				*read_file(char *file);
void				error(int i);
int					tetr_check(char *str, size_t i);
int					f_check(char *str);
int					s_check(char *str);
t_tetr				*ft_put_in_tetr(char *str);
t_tetr				*ft_find_xy(t_tetr *tetr, char **s);
t_tetr				*ft_put_xy_in_tetr(t_tetr *tetr);
char				**ft_result(t_tetr *tetr, int max);
char				**ft_recu_solve(char **tab, t_tetr *tetr, int max);
t_tetr				*ft_move_xy(t_tetr *tetr, int x, int y);
int					ft_map_size(t_tetr *tetr);
char				**ft_empty_map(char **tab, int size);
int					ft_check(char **tab, t_tetr *tetr, int max);
char				**ft_write(char **tab, t_tetr *tetr, int max);
char				**ft_reset(char **tab, t_tetr *tetr, int max);
char				**ft_strsplit(const char *s, char c);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strnew(size_t size);
int					ft_check(char **tab, t_tetr *tetr, int size);
void				ft_clean_str(char *str);
int					m_check(char *str);
void				ft_arr_putstr(char **str);

#endif
