/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:14:18 by hlouar            #+#    #+#             */
/*   Updated: 2016/01/22 20:27:30 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_recreate(char **grille, int size)
{
	char **new;

	free(grille);
	new = ft_initmap(size);
	return (new);
}

int		ft_retet(char **tetriminos)
{
	int i;
	int size;

	size = ft_count(tetriminos) * 2;
	i = 0;
	while ((i * i) < size)
		i++;
	return (i);
}

void	ft_draw(char **grille, int size)
{
	int x;
	int y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
			ft_putchar(grille[x][y++]);
		ft_putchar('\n');
		x++;
	}
}

int		ft_countn(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n'
					|| str[i + 1] == ft_isalpha(str[i])
					|| str[i + 1] == '\0'))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_checkslash(char *str)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (str[a] != '\0')
	{
		if (str[a] != '\n')
			b++;
		if (str[a] == '\n' && str[a + 1] != '\n')
		{
			if (b == 4)
				b = 0;
			else
				return (0);
		}
		a++;
	}
	return (1);
}
