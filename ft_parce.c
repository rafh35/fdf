/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parce.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/26 15:44:45 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/26 12:04:13 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		fill_parce(t_parce *p)
{
	ft_memset(&p, 0, sizeof(p));
}

int			**ft_parce(char *str, t_parce *p)
{
	int		**tab;

	p->len = ft_count_line(str);
	p->col = ft_count_nbr(str);
	p->x = 0;
	p->i = 0;
	tab = (int**)malloc(sizeof(int*) * p->len);
	while (str[p->i])
	{
		tab[p->x] = (int*)malloc(sizeof(int) * p->col);
		p->y = 0;
		p->nb = 0;
		while (str[p->i] && str[p->i] != '\n')
		{
			if (str[p->i] != ' ')
			{
				tab[p->x][p->y] = ft_atoi(&str[p->i]);
				p->nb = ft_nbrlen(tab[p->x][p->y]);
				p->i += p->nb;
				p->y++;
			}
			else
				p->i++;
		}
		p->x++;
		p->i++;
	}
	return (tab);
}
