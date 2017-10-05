/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:30:17 by gvilmont          #+#    #+#             */
/*   Updated: 2016/01/25 16:51:36 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_mapisvalid(char *str);
char	*ft_read_txt(char *dst);
char	**ft_intab(char *str);
char	*ft_rapl_fonctions(char *str);
char	**ft_initmap(int size);
void	ft_showtab(char **tab, int size);
int		ft_carlen(char **tab, int size);
char	**ft_putintab(char **tab, char *str, int x, int y);
int		ft_count_tet(char *str);
int		ft_checkpos(char **tab, char *str, int x, int y);
int		ft_count(char **str);
int		ft_largeurpiece(char *str);
int		ft_longueurpiece(char *s);
int		ft_try(char *str, int x, int y, char **tetriminos);
char	**ft_putingrid(char *str, int x, int y, char **tetriminos);
char	**ft_delete(char *str, int x, int y, char **tetriminos);
int		ft_recursive(char **grille, int size, char **tetriminos, int nbrtet);
char	**ft_changedouble(char **tet);
char	**ft_init(int size);
char	**ft_recreate(char **grille, int size);
int		ft_retet(char **tetriminos);
int		ft_countn(char *str);
int		ft_checkslash(char *str);
void	ft_draw(char **tab, int size);

#endif
