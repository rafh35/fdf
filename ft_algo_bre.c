/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo_bre.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 11:39:45 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/26 16:40:31 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*void	key_hook(t_var *v, int keycode)
{
	if (keycode == 123)
		v->left--;
	else if (keycode == 124)
		v->right++;
}*/

void	line(t_var *v, t_pos *t)
{
	t_algo *algo;

	algo = ft_memalloc(sizeof(algo));
	algo->dx = abs(v->x1 - v->x0);
	algo->sx = (v->x0 < v->x1) ? 1 : -1;
	algo->dy = abs(v->y1 - v->y0);
	algo->sy = (v->y0 < v->y1) ? 1 : -1;
	algo->err = (algo->dx > algo->dy ? algo->dx : -algo->dy) / 2;
	while (!(v->x0 == v->x1 && v->y0 == v->y1))
	{
		mlx_pixel_put(t->mlx_ptr, t->win_ptr, v->y0 + t->hori, v->x0 + t->verti, 0x40ECFF);
		algo->e2 = algo->err;
		if (algo->e2 > -algo->dx)
		{
			algo->err -= algo->dy;
			v->x0 += algo->sx;
		}
		if (algo->e2 < algo->dy)
		{
			algo->err += algo->dx;
			v->y0 += algo->sy;
		}
	}
	free(algo);
}
