/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:54:05 by ahryhory          #+#    #+#             */
/*   Updated: 2017/11/22 12:40:50 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_tet(char *s)
{
	int		count;

	s += 4;
	count = 2;
	while (*s)
	{
		if (*s != '\n')
			return (0);
		if ((count - 1) % 5 == 0)
			if (*(s + 1) == '\n' || *(s + 1) == '\0')
				return (0);
		if (count % 5 == 0)
			s++;
		else
			s += 5;
		count++;
	}
	return (1);
}

static int		ft_check_condition(char **s, int i, int j, int *ar)
{
	int		flag;

	flag = 0;
	if (s[i][j] == '#')
	{
		if (s[i + 1] != '\0' && (i + 1) < ar[0] && s[i + 1][j] == '#')
			flag++;
		if (s[i][j + 1] == '#')
			flag++;
		if ((i - 1) >= 0 && (i - 1) >= (ar[0] - 4) && s[i - 1][j] == '#')
			flag++;
		if ((j - 1) >= 0 && s[i][j - 1] == '#')
			flag++;
		if (flag == 0)
			return (5);
		ar[1] += flag;
		return (1);
	}
	return (0);
}

static int		ft_check_location(char **s, int ct)
{
	int		i;
	int		j;
	int		count;
	int		ar[2];

	i = 0;
	while (s[i])
	{
		count = 0;
		ar[1] = 0;
		while (i < ct)
		{
			j = -1;
			while (s[i][++j])
			{
				ar[0] = ct;
				count += ft_check_condition(s, i, j, ar);
			}
			i++;
		}
		if (count != 4 || ar[1] < 6)
			return (0);
		ct += 4;
	}
	return (1);
}

static int		ft_check_tetriminos(char **s)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != '.' && s[i][j] != '#')
				return (0);
			j++;
		}
		if (j < 4)
			return (0);
		i++;
	}
	if (i % 4 != 0 || !ft_check_location(s, 4))
		return (0);
	return (1);
}

int				ft_check(char *s1, char **s2)
{
	if (ft_check_tet(s1) && ft_check_tetriminos(s2))
		return (1);
	return (0);
}
