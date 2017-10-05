/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:51:15 by gvilmont          #+#    #+#             */
/*   Updated: 2016/01/25 16:31:46 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_showtab(char **tab, int size)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < ft_carlen(tab, size))
	{
		while (b < ft_carlen(tab, size))
		{
			ft_putchar(tab[a][b]);
			b++;
		}
		ft_putchar('\n');
		a++;
		b = 0;
	}
}

int		ft_try(char *str, int x, int y, char **tetriminos)
{
	int i;
	int a;
	int b;
	int k;

	k = 0;
	i = 0;
	a = x;
	b = y;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) && tetriminos[a][b] != '.')
			return (0);
		if (ft_isalpha(str[i]))
			k++;
		if (k == 4)
			return (1);
		b++;
		if (str[i++] == '\n')
		{
			a++;
			b = y;
		}
	}
	return (1);
}

char	**ft_putingrid(char *str, int x, int y, char **tetriminos)
{
	int i;
	int a;
	int b;

	i = 0;
	a = x;
	b = y;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			tetriminos[a][b] = str[i];
			b++;
		}
		if (str[i] == '.')
			b++;
		if (str[i] == '\n')
		{
			b = y;
			a++;
		}
		i++;
	}
	return (tetriminos);
}

char	**ft_delete(char *str, int x, int y, char **tetriminos)
{
	int i;
	int a;
	int b;

	i = 0;
	a = x;
	b = y;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			tetriminos[a][b] = '.';
			b++;
		}
		if (str[i] == '.')
			b++;
		if (str[i] == '\n')
		{
			b = y;
			a++;
		}
		i++;
	}
	return (tetriminos);
}

char	**ft_changedouble(char **tetriminos)
{
	char *p;
	char c;

	c = 'A';
	while (*tetriminos)
	{
		p = *tetriminos;
		while (*p)
		{
			if (*p == '#')
				*p = c;
			p++;
		}
		c++;
		tetriminos++;
	}
	return (tetriminos);
}
