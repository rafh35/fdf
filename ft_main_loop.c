/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_main_loop.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/23 09:31:06 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/23 09:31:50 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		main_loop(t_pos *t, t_var *v)
{
	fdf(t, v);
	legend(t);
	mlx_hook(t->win_ptr, 2, 0, push_key, t);
	mlx_loop(t->mlx_ptr);
}

void		main_loop2(t_pos *t, t_var *v)
{
	fdf2(t, v);
	legend(t);
	mlx_hook(t->win_ptr, 2, 0, push_key, t);
	mlx_loop(t->mlx_ptr);
}
