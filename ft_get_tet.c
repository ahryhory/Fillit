/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:02:58 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/22 15:13:58 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_tet(int fd, const char *path)
{
	int		bytes_count;
	char	*tet;

	bytes_count = ft_read_full(fd);
	close(fd);
	if ((fd = open(path, O_RDONLY)) < 0 || bytes_count < 0)
		return (NULL);
	if ((tet = ft_strnew(bytes_count)) == NULL)
		return (NULL);
	if ((read(fd, tet, bytes_count)) < 0)
		return (NULL);
	tet[bytes_count] = '\0';
	return (tet);
}
