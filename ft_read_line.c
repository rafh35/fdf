/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_line.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 16:44:44 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 14:36:39 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_read_line(char *str, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		nbr_oct;
	char	*tmp;

	while ((nbr_oct = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbr_oct] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (str);
}
