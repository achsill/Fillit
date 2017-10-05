/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:25:44 by hlouar            #+#    #+#             */
/*   Updated: 2016/01/25 17:50:04 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	*fichier;
	char	**tet;
	char	**grille;
	int		size;

	if (ac != 2 || ft_read_txt(av[1]) == NULL
				|| ft_mapisvalid(ft_read_txt(av[1])) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	if ((fichier = ft_read_txt(av[1])) &&
			(tet = ft_intab(ft_rapl_fonctions(fichier))) != NULL)
	{
		ft_changedouble(tet);
		size = ft_retet(tet);
		grille = ft_initmap(size);
		while (ft_recursive(grille, size, tet, 0) == 0)
			grille = ft_recreate(grille, ++size);
		ft_showtab(grille, size);
		free(tet);
		free(grille);
	}
	return (0);
}
