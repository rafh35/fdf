/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_line.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 16:44:44 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 14:38:48 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_read_line(char *str, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		nbr_oct;
	char	*tmp;

	if (fd < 0 || !str || read(fd, *line, 0) < 0 || BUFF_SIZE < 1)
	{
		ft_putstr("error\n");
		exit(0);
	}
	while ((nbr_oct = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbr_oct] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (str);
}
