/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:16:11 by gvilmont          #+#    #+#             */
/*   Updated: 2016/01/25 17:32:59 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_linelen(char **tab, int x, int size)
{
	int b;
	int y;

	b = 0;
	y = size - 1;
	while (y != 0)
	{
		if (ft_isalpha(tab[x][y]) == 1)
			return (b);
		b++;
		y--;
	}
	return (b);
}

int	ft_xlen(char **tab, int size)
{
	int x;
	int a;
	int b;

	x = 0;
	a = 0;
	b = size;
	while (x < size)
	{
		a = ft_linelen(tab, x, size);
		if (a < b)
			b = a;
		x++;
	}
	return (size - b);
}

int	ft_columnlen(char **tab, int y, int size)
{
	int b;
	int x;

	b = 0;
	x = size - 1;
	while (x != 0)
	{
		if (ft_isalpha(tab[x][y]) == 1)
			return (b);
		b++;
		x--;
	}
	return (b);
}

int	ft_ylen(char **tab, int size)
{
	int y;
	int a;
	int b;

	y = 0;
	a = 0;
	b = size;
	while (y < size)
	{
		a = ft_columnlen(tab, y, size);
		if (a < b)
			b = a;
		y++;
	}
	return (size - b);
}

int	ft_carlen(char **tab, int size)
{
	if (ft_ylen(tab, size) < ft_xlen(tab, size))
		return (ft_xlen(tab, size));
	else
		return (ft_ylen(tab, size));
}
