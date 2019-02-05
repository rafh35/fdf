/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_projection.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 12:39:21 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 14:07:14 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

double		ft_isometric_x(int x, int y, t_pos *p)
{
	double	x_iso;

	x_iso = (sqrt(2) / 2) * ((x - y) * p->ko);
	return (x_iso);
}

double		ft_isometric_y(int x, int y, int z, t_pos *p)
{
	double	y_iso;

	y_iso = sqrt(2 / 2) * z + 1 / (sqrt(3) * ((x + y) * p->ko));
	return (y_iso);
}
