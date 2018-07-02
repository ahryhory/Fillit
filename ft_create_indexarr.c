/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_indexarr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:49:54 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/22 12:41:14 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_catarr(char **tetr, t_tets **list, int count)
{
	int		i;
	int		j;
	int		m;
	int		**index;

	i = 0;
	while (count)
	{
		index = (int**)malloc(sizeof(int*) * 4);
		m = 0;
		while (i < (ft_count_blocks(tetr) - count) * 4 + 4)
		{
			j = -1;
			while (tetr[i][++j])
				if (tetr[i][j] == '#')
				{
					index[m] = (int*)malloc(sizeof(int) * 2);
					index[m][0] = i - (ft_count_blocks(tetr) - count) * 4;
					index[m++][1] = j;
				}
			i++;
		}
		ft_lst_add(list, index);
		count--;
	}
}

t_tets			*ft_create_indexarr(char **tetr)
{
	t_tets	*list;
	int		count;

	list = NULL;
	count = ft_count_blocks(tetr);
	ft_catarr(tetr, &list, count);
	list = *ft_format_list(&list);
	return (list);
}
