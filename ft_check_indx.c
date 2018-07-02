/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_indx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:04:54 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/22 15:38:49 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_plus_indx(t_tets **t, int p, int indx)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		(*t)->index[i][indx] += p;
		i++;
	}
}

static int		ft_correct(t_tets **t, int cnt, int p, int indx)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((*t)->index[i][indx] >= cnt)
		{
			i = 0;
			while (i < 4)
			{
				(*t)->index[i][indx] -= p;
				i++;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

int				ft_check_indx(t_tets **t, int cnt, int pi, int pj)
{
	ft_plus_indx(t, pi, 0);
	if (!ft_correct(t, cnt, pi, 0))
		return (0);
	ft_plus_indx(t, pj, 1);
	if (!ft_correct(t, cnt, pj, 1))
		return (2);
	return (1);
}
