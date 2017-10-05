/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:18:11 by hlouar            #+#    #+#             */
/*   Updated: 2016/01/22 16:45:12 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_diff_line(char *str, int j)
{
	int	i;
	int	y;

	i = j;
	y = 0;
	while (i < j + 21)
	{
		i += 5;
		if (i >= 20 + j)
		{
			y++;
			i = j;
			i += y;
		}
		if (str[i] == '#')
			break ;
	}
	return (y);
}

int		ft_diff_column(char *str, int j)
{
	int	i;
	int	diff;

	i = j;
	diff = 0;
	while (i < 21 + j)
	{
		if (str[i] == '#')
			break ;
		i++;
		if (str[i] == '\n')
		{
			diff++;
			i++;
		}
	}
	return (diff * 5);
}

char	*ft_change_placeline(char *str, int j)
{
	int	i;
	int	y;

	y = ft_diff_line(str, j);
	i = j;
	while (i < 21 + j)
	{
		if (str[i] == '#')
		{
			str[i] = '.';
			i = i - y;
			str[i] = '#';
			i++;
		}
		i++;
	}
	return (str);
}

char	*ft_change_placecolumn(char *str, int j)
{
	int	i;
	int	y;

	y = ft_diff_column(str, j);
	i = j;
	while (i < 21 + j)
	{
		if (str[i] == '#')
		{
			str[i] = '.';
			i = i - y;
			str[i] = '#';
			i++;
		}
		i++;
	}
	return (str);
}

char	*ft_rapl_fonctions(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] != '#')
		{
			ft_change_placeline(str, j);
			ft_change_placecolumn(str, j);
		}
		j += 21;
	}
	return (str);
}
