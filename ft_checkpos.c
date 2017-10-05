/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 04:13:19 by gvilmont          #+#    #+#             */
/*   Updated: 2016/01/20 11:09:12 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkpos(char **new, char *tab, int x, int y)
{
	int a;
	int b;
	int i;

	a = x;
	b = y;
	i = 0;
	while (tab[i] != '\0')
	{
		if (ft_isalpha(tab[i]) && ft_isalpha(new[a][b]))
			return (0);
		if (tab[i] == '\n')
		{
			a++;
			b = y - 1;
		}
		b++;
		i++;
	}
	return (1);
}
