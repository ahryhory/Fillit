/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:30:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/20 16:44:36 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_format(t_tets **list, int min, int n)
{
	int		m;
	t_tets	*tmp;

	tmp = *list;
	m = 0;
	while (m < 4)
	{
		tmp->index[m][n] = tmp->index[m][n] - min;
		m++;
	}
}

t_tets			**ft_format_list(t_tets **list)
{
	int		m;
	int		n;
	int		min;
	t_tets	*tmp;

	tmp = *list;
	while (tmp)
	{
		n = 0;
		while (n < 2)
		{
			m = 0;
			min = tmp->index[m][n];
			while (m < 4)
			{
				if (min > tmp->index[m][n])
					min = tmp->index[m][n];
				m++;
			}
			ft_format(&tmp, min, n);
			n++;
		}
		tmp = tmp->next;
	}
	return (list);
}
