/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:18:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/22 15:38:08 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_add(t_tets **tets, int **index)
{
	t_tets	*lst;
	t_tets	*new;

	new = (t_tets*)malloc(sizeof(t_tets));
	new->index = index;
	new->prev = NULL;
	new->next = NULL;
	lst = *tets;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		new->prev = lst;
		lst->next = new;
	}
	else
		*tets = new;
}
