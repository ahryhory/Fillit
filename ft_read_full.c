/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:26:54 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/22 13:58:52 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read_full(int fd)
{
	int		b_count;
	int		temp;
	char	*str;
	int		size;

	size = 1;
	str = ft_strnew(size);
	b_count = 0;
	while ((temp = read(fd, str, 1)) > 0)
		b_count += temp;
	if (temp < 0)
		return (-1);
	ft_strdel(&str);
	return (b_count);
}
