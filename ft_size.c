/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:18:29 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/22 15:55:39 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_size(char **tetr)
{
	int		i;
	int		count;

	count = ft_count_blocks(tetr) * 4;
	i = 2;
	while (i)
	{
		while (i < (count / 3 + 1))
		{
			if (i * i == count)
				return (i);
			i++;
		}
		count++;
		i = 2;
	}
	return (0);
}
