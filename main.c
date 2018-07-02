/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:11:08 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/22 16:14:50 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_print(char **sqr)
{
	int		i;
	int		j;

	i = 0;
	while (sqr[i])
	{
		j = 0;
		while (sqr[i][j])
		{
			write(1, &sqr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

static void		ft_create(char ***sqr, int count)
{
	int		i;
	int		j;

	*sqr = (char**)malloc(sizeof(char*) * (count + 1));
	if (sqr)
	{
		i = 0;
		while (i < count)
		{
			(*sqr)[i] = ft_strnew(count);
			j = 0;
			while (j < count)
			{
				(*sqr)[i][j] = '.';
				j++;
			}
			i++;
		}
		(*sqr)[i] = 0;
	}
}

static int		ft_count(t_tets *lst, int c)
{
	int		i;

	while (lst)
	{
		i = 0;
		while (i < 4)
		{
			if ((lst->index[i][1] == 3 || lst->index[i][0] == 3) && c == 3)
				return (4);
			i++;
		}
		lst = lst->next;
	}
	return (c);
}

static void		ft_happy_end(t_tets *tetr, int count)
{
	char	**square;
	char	letter;
	int		i;

	letter = 'A';
	ft_create(&square, count);
	while (tetr)
	{
		i = 0;
		while (i < 4)
		{
			square[tetr->index[i][0]][tetr->index[i][1]] = letter;
			i++;
		}
		tetr = tetr->next;
		letter++;
	}
	ft_print(square);
}

int				main(int ac, char **av)
{
	char	**tets;
	t_tets	*tetr;
	int		count;
	int		mv;

	mv = 0;
	ft_usage(ac);
	tets = ft_get_tetriminos(av[1]);
	if (ft_count_blocks(tets) > 26)
	{
		while (*tets)
			ft_strdel(tets++);
		ft_putendl("error");
		exit(0);
	}
	tetr = ft_create_indexarr(tets);
	count = ft_size(tets);
	while (*tets)
		ft_strdel(tets++);
	count = ft_count(tetr, count);
	tetr = ft_x(tetr, &count, mv);
	ft_happy_end(tetr, count);
	return (0);
}
