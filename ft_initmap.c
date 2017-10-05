/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:56:47 by hlouar            #+#    #+#             */
/*   Updated: 2016/01/22 16:45:06 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_initmap(int size)
{
	char	**tab;
	int		x;
	int		y;

	tab = (char**)malloc(sizeof(char*) * size);
	if (!tab)
		return (0);
	x = 0;
	while (x < size)
	{
		y = 0;
		tab[x] = (char*)malloc(sizeof(char) * size);
		if (!tab[x])
			return (NULL);
		while (y < size)
			tab[x][y++] = '.';
		x++;
	}
	return (tab);
}
