/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:50:55 by hlouar            #+#    #+#             */
/*   Updated: 2016/01/25 18:58:29 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_recursive(char **grille, int size, char **tetriminos, int nbrtet)
{
	int x;
	int y;

	x = 0;
	if (nbrtet + 1 > ft_count(tetriminos))
		return (1);
	while (x + ft_largeurpiece(tetriminos[nbrtet]) <= size)
	{
		y = 0;
		while (y + ft_longueurpiece(tetriminos[nbrtet]) <= size + 1)
		{
			if (ft_try(tetriminos[nbrtet], x, y, grille))
			{
				ft_putingrid(tetriminos[nbrtet], x, y, grille);
				if (ft_recursive(grille, size, tetriminos, nbrtet + 1))
					return (1);
				ft_delete(tetriminos[nbrtet], x, y, grille);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	ft_count(char **str)
{
	int i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_largeurpiece(char *str)
{
	int i;
	int largeur;
	int k;

	k = 0;
	i = 0;
	largeur = 4;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			k++;
		if (str[i] == '\n')
		{
			if (k == 4)
				largeur--;
			k = 0;
		}
		i++;
	}
	return (largeur);
}

int	ft_longueurpiece(char *s)
{
	int count;
	int col;
	int x;
	int dots;

	count = 4;
	x = -1;
	dots = 0;
	while (x < 5)
	{
		col = ++x;
		while ((col += 5) < (x + 20))
		{
			if (s[col] == '.')
				dots++;
			if (dots == 4)
			{
				count--;
				dots = 0;
			}
			if (ft_isalpha(s[col]))
				col = x + 20;
		}
	}
	return (count);
}
