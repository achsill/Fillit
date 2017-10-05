/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:59:04 by gvilmont          #+#    #+#             */
/*   Updated: 2016/01/15 05:45:13 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_putintab(char **new, char *tab, int x, int y)
{
	int i;
	int a;
	int b;

	a = x;
	b = y;
	i = 0;
	while (tab[i] != '\0')
	{
		if (ft_isalpha(tab[i]) && ft_isalpha(new[a][b]) == 0)
			new[a][b] = tab[i];
		if (tab[i] == '\n')
		{
			a++;
			b = y - 1;
		}
		b++;
		i++;
	}
	return (new);
}
