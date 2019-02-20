/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_window.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/20 14:15:12 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 14:49:23 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		init_window(t_pos *p, char **argv)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, -1, -1, L, H, "fdf");
	p->hori = 0;
	p->verti = 0;
	if (ft_strcmp(argv[1], "maps/42.fdf") == 0)
		p->ko = 30;
	else
		p->ko = 5;
	p->alti = 1;
	p->a = 0;
	p->b = 0;
}

void		main_loop(t_pos *t, t_var *v)
{
	fdf(t, v);
	//fdf2(t, v);
	legend(t);
	mlx_hook(t->win_ptr, 2, 0, push_key, t);
	mlx_loop(t->mlx_ptr);
}

void		push_key2(int key, void *param)
{
	t_pos	*tmp;
	t_var	*v;

	v = NULL;
	tmp = param;
	if (key == 123)
		tmp->hori -= 50;
	if (key == 124)
		tmp->hori += 50;
	if (key == 125)
		tmp->verti += 50;
	if (key == 126)
		tmp->verti -= 50;
	if (key == 78 && tmp->ko >= 5)
		tmp->ko -= 1;
	if (key == 69 && tmp->ko <= 100)
		tmp->ko += 1;
	if (key == 116)
		tmp->alti += 0.1;
}

int			push_key(int key, void *param)
{
	t_pos	*tmp;
	t_var	*v;

	v = NULL;
	tmp = param;
	push_key2(key, param);
	if (key == 121)
		tmp->alti -= 0.1;
	if (key == 13)
		tmp->a += 0.1;
	if (key == 1)
		tmp->a -= 0.1;
	if (key == 0)
		tmp->b -= 0.1;
	if (key == 2)
		tmp->b += 0.1;
	if (key == 53)
	{
		mlx_clear_window(tmp->mlx_ptr, tmp->win_ptr);
		ft_putstr("dégage!!\n");
		exit(0);
	}
	mlx_clear_window(tmp->mlx_ptr, tmp->win_ptr);
	main_loop(tmp, v);
	return (1);
}
