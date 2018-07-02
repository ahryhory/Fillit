/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:36:32 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/22 12:42:27 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checker(t_tets *tmp)
{
	int		i;
	int		j;
	t_tets	*head;

	head = tmp;
	tmp = tmp->prev;
	while (tmp != NULL)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (head->index[i][0] == tmp->index[j][0])
					if (head->index[i][1] == tmp->index[j][1])
						return (0);
				j++;
			}
			i++;
		}
		tmp = tmp->prev;
	}
	return (1);
}

static void		ft_format(t_tets **tetr, int y)
{
	int		i;
	int		min;

	i = 0;
	min = (*tetr)->index[i][1];
	while (i < 4)
	{
		if (min > (*tetr)->index[i][1])
			min = (*tetr)->index[i][1];
		(*tetr)->index[i][0] -= y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*tetr)->index[i][1] -= min;
		i++;
	}
}

static void		ft_format_x(t_tets **tetr, int y, int x)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		(*tetr)->index[i][1] -= x;
		(*tetr)->index[i][0] -= y;
		i++;
	}
}

static int		ft_move(t_tets **tetr, int count)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	j = 1;
	while ((check = ft_check_indx(tetr, count, i, j)) != 0)
	{
		if (ft_checker(*tetr) && check == 1)
			return (1);
		else if (check != 2)
		{
			ft_format_x(tetr, i, j);
			j++;
		}
		else if (check == 2)
		{
			ft_format(tetr, i);
			i++;
			j = 0;
		}
	}
	ft_format_list(tetr);
	return (0);
}

t_tets			*ft_x(t_tets *tetr, int *count, int mv)
{
	t_tets	*tmp;

	tmp = tetr;
	while (tmp)
	{
		if (ft_checker(tmp))
			tmp = tmp->next;
		else
		{
			mv = ft_move(&tmp, *count);
			while (!mv && tmp->prev != NULL)
			{
				tmp = tmp->prev;
				mv = ft_move(&tmp, *count);
			}
			if (!mv && tmp->prev == NULL)
			{
				(*count)++;
				while (tmp->prev)
					tmp = tmp->prev;
				ft_format_list(&tmp);
			}
		}
	}
	return (tetr);
}
