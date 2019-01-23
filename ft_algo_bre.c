/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo_bre.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-51.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/02 16:22:24 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 16:22:05 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_var	*init_var(int x0, int y0, int x1, int y1, int z, int z2)
{
	t_var *v;
	if (!(v = (t_var*)ft_memalloc(sizeof(t_var))))
		return (0);
	v->x0 = ft_isometric_x(x0, y0) *2;
	v->x1 = ft_isometric_x(x1, y1) *2;
	v->y0 = ft_isometric_y(x0, y0, z) *2;
	v->y1 = ft_isometric_y(x1, y1, z2) *2;
	return (v);
}

t_var	*init_var2(int x0, int y0, int x1, int y1, int z, int z2)
{
	t_var *v;
	if (!(v = (t_var*)ft_memalloc(sizeof(t_var))))
		return (0);
	v->x0 = x0 +0.35 * z;
	v->y0 = y0 +0.35 * z;
	v->x1 = x1 +0.35 * z2;
	v->y1 = y1 +0.35 * z2;
	return(v);
}

void	line(t_var *v, t_window *w)
{
	int 	dx = abs(v->x1 - v->x0);
	int 	sx = (v->x0 < v->x1) ? 1 : -1;
	int 	dy = abs(v->y1 - v->y0);
	int 	sy = (v->y0 < v->y1) ? 1 : -1; 
	int 	err = (dx > dy ? dx : - dy) / 2;
	int 	e2;
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
