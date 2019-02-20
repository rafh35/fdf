/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_projection.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 12:39:21 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 14:41:06 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

double		iso_x(int x, int y, t_pos *p)
{
	double	x_iso;

	x_iso = (sqrt(2) / 2) * (x - y);
	x_iso = (x_iso * cos(p->a)) + (y * sin(p->a));
	return (x_iso);
}

double		iso_y(int x, int y, int z, t_pos *p)
{
	double	y_iso;

	y_iso = (sqrt(2) / 2) * z + 1 / sqrt(3) * (x + y);
	y_iso = (y_iso * cos(p->b)) - (x * sin(p->b));
	return (y_iso);
}

int			ft_cavx(int x, int z, t_pos *p)
{
	int		cavx;

	cavx = 0;
	cavx = x + p->alti * -z;
	cavx = (cavx * cos(p->a)) + (x * sin(p->a));
	return (cavx);
}

int			ft_cavy(int y, int z, t_pos *p)
{
	int		cavy;

	cavy = 0;
	cavy = y + p->alti * -z;
	cavy = (cavy * cos(p->b)) - (y * sin(p->b));
	return (cavy);
}
