/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parce.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/26 15:44:45 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 17:00:09 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	fill_parce(t_parce *p)
{
	ft_memset(&p, 0, sizeof(p));
}

int				**ft_parce(char *str, t_parce *p)
{
	int		**tab;
	int		i;
	int		len; 
	int		col;
	int		nb;

	len = ft_count_line(str);
	col = ft_count_nbr(str);
	i = 0;
	p->x = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * len)))
		return (0);
	while (str[i])
	{
		if (!(tab[p->x] = (int*)malloc(sizeof(int) * col)))
			return(0);
		p->y = 0;
		while (str[i] && str[i] != '\n')
		{
			if (str[i] != ' ')
			{
				nb = ft_nbrlen(tab[p->x][p->y]);
				tab[p->x][++p->y] = ft_atoi(&str[i+=nb]);
			}
			else
				i++;
		}
		p->x++;
		i++;
	}
	return (tab);
}
