/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_nbr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/27 11:39:47 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 18:13:52 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_nbr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			count++;
		if (str[i] != ' ' && str[i + 1] != ' ' && str[i + 1] != '\n')
			count--;
		if (str[i] == '\n' && str[i + 1] == ' ')
			count--;
		i++;
	}
	return (count);
}
