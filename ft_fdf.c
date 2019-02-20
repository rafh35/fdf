/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/20 14:34:48 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 14:54:49 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_1(t_pos *t, t_var *v)
{
	int		a;

	a = -1;
	while (++a < t->nb)
	{
		v->x0 = (iso_x(t->pos[a].x, t->pos[a].y, t)) * t->ko;
		v->x1 = (iso_x(t->pos[a + 1].x, t->pos[a + 1].y, t)) * t->ko;
		v->y0 = (iso_y(t->pos[a].x, t->pos[a].y, -t->pos[a].z * t->alti, t))
		* t->ko;
		v->y1 = (iso_y(t->pos[a + 1].x, t->pos[a + 1].y, -t->pos[a + 1].z
		* t->alti, t)) * t->ko;
		if (t->pos[a].x == t->pos[a + 1].x)
			line(v, t);
	}
}

void		fdf(t_pos *t, t_var *v)
{
	int		a;

	v = ft_memalloc(sizeof(t_var));
	a = -1;
	while (++a < t->nb - t->nb / t->line)
	{
		v->x0 = (iso_x(t->pos[a].x, t->pos[a].y, t)) * t->ko;
		v->x1 = (iso_x(t->pos[a + t->col].x, t->pos[a + t->col].y, t))
		* t->ko;
		v->y0 = (iso_y(t->pos[a].x, t->pos[a].y, -t->pos[a].z * t->alti, t))
		* t->ko;
		v->y1 = (iso_y(t->pos[a + t->col].x, t->pos[a + t->col].y,
		-t->pos[a + t->col].z * t->alti, t)) * t->ko;
		if (t->pos[a].x != t->pos[a + t->col].x && t->pos[a].y ==
		t->pos[a + t->col].y)
			line(v, t);
	}
	fdf_1(t, v);
}

void		fdf2_1(t_pos *t, t_var *v)
{
	int		a;

	a = -1;
	while (++a < t->nb)
	{
		v->x0 = ft_cavx(t->pos[a].x, t->pos[a].z, t) * t->ko;
		v->x1 = ft_cavx(t->pos[a + 1].x, t->pos[a + 1].z, t) * t->ko;
		v->y0 = ft_cavy(t->pos[a].y, t->pos[a].z, t) * t->ko;
		v->y1 = ft_cavy(t->pos[a + 1].y, t->pos[a + 1].z, t) * t->ko;
		if (t->pos[a].x == t->pos[a + 1].x)
			line(v, t);
	}
}

void		fdf2(t_pos *t, t_var *v)
{
	int		a;

	v = ft_memalloc(sizeof(t_var));
	a = -1;
	while (++a < t->nb - t->nb / t->line)
	{
		v->x0 = ft_cavx(t->pos[a].x, t->pos[a].z, t) * t->ko;
		v->x1 = ft_cavx(t->pos[a + t->col].x, t->pos[a + t->col].z, t)
		* t->ko;
		v->y0 = ft_cavy(t->pos[a].y, t->pos[a].z, t) * t->ko;
		v->y1 = ft_cavy(t->pos[a + t->col].y, t->pos[a + t->col].z, t)
		* t->ko;
		if (t->pos[a].x != t->pos[a + t->col].x && t->pos[a].y ==
		t->pos[a + t->col].y)
			line(v, t);
	}
	fdf2_1(t, v);
}
