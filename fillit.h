/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:30:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/22 14:05:04 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./includes/libft/libft.h"

typedef struct		s_tets
{
	int				**index;
	struct s_tets	*next;
	struct s_tets	*prev;
}					t_tets;

char				**ft_get_tetriminos(const char *path);
char				*ft_get_tet(int fd, const char *path);
int					ft_read_full(int fd);
int					ft_count_blocks(char **tetr);
void				ft_lst_add(t_tets **tets, int **index);
t_tets				*ft_create_indexarr(char **tetr);
void				ft_print_index(t_tets *list);
t_tets				*ft_x(t_tets *tetr, int *count, int mv);
t_tets				**ft_format_list(t_tets **list);
int					ft_size(char **tetr);
int					ft_check(char *s1, char **s2);
int					ft_check_indx(t_tets **t, int cnt, int pi, int pj);
void				ft_usage(int ac);

#endif
