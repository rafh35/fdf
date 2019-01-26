/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stock_pos.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/27 17:02:08 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/26 11:53:30 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_pos		*fill_var_pos(char *src)
{
	t_pos	*p;

	if (!(p = ft_memalloc(sizeof(struct s_pos))))
		return (0);
	p->nb = ft_count_nbr(src);
	p->line = ft_count_line(src);
	p->col = p->nb / p->line;
	return (p);
}

t_pos		*fill_pos(int **str, char *src, int a)
{
	t_pos	*p;
	int		i;
	int		j;

	p = fill_var_pos(src);
	if (!(p->pos = ft_memalloc(sizeof(int) * p->nb)))
		return (0);
	i = 0;
	while (i < p->line)
	{
		j = 0;
		while (j < p->col)
		{
			p->pos[a].x = i;
			p->pos[a].y = j;
			p->pos[a].z = str[i][j];
			a++;
			j++;
		}
		i++;
	}
	return (p);
}
