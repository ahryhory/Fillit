/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:25:21 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/22 16:12:44 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_get_tetriminos(const char *path)
{
	int		fd;
	char	*t;
	char	**tet;

	if ((fd = open(path, O_RDONLY)) < 0)
	{
		ft_putendl("error");
		exit(0);
	}
	t = ft_get_tet(fd, path);
	close(fd);
	tet = ft_strsplit(t, '\n');
	if (!ft_check(t, tet) || t == NULL || tet == NULL || t[0] == '\0')
	{
		ft_putendl("error");
		ft_strdel(&t);
		while (*tet)
			ft_strdel(tet++);
		exit(0);
	}
	ft_strdel(&t);
	return (tet);
}
