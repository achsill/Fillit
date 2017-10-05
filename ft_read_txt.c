/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:00:27 by gvilmont          #+#    #+#             */
/*   Updated: 2016/01/21 16:14:13 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"
#define BUF_SIZE 4096

char	*ft_read_txt(char *str)
{
	int		ret;
	int		fd;
	char	buf[BUF_SIZE + 1];
	char	*dst;
	char	*tmp;

	dst = NULL;
	if ((fd = open(str, O_RDONLY)) < 0)
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (dst == NULL)
			dst = ft_strjoin("", buf);
		else
		{
			tmp = dst;
			dst = ft_strjoin(dst, buf);
			if (tmp != NULL)
				free(tmp);
		}
	}
	return (dst);
}
