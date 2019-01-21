/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo_bre.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/02 16:22:24 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 17:07:53 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_var	*init_var(int x0, int y0, int x1, int y1)
{
	t_var *v;

	if (!(v = (t_var*)ft_memalloc(sizeof(t_var) * 10)))
		return (0);
	v->x0 = x0 * 2;
	v->x1 = x1 * 2;
	v->y0 = y0 * 2;
	v->y1 = y1 * 2;
	return (v);
}

void	line(t_var *v, t_window *w)
{
	int dx = abs(v->x1 - v->x0);
	int sx = v->x0 < v->x1 ? 1 : -1;
	int dy = abs(v->y1 - v->y0);
	int sy = v->y0 < v->y1 ? 1 : -1; 
	int err = (dx > dy ? dx : - dy) / 2;
	int e2;

	while (1)
	{

		mlx_pixel_put(w->mlx_ptr, w->win_ptr, v->x0, v->y0, 0x40ECFF);
		if (v->x0 == v->x1 && v->y0 == v->y1)
			break;
		e2 = err;
		if (e2 > - dx)
		{
			err -= dy;
			v->x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			v->y0 += sy;
		}
	}
}
