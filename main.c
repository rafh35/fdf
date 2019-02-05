/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 12:05:51 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 14:56:30 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		init_window(t_pos *p)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, -1, -1, L, H, "fdf");
	p->hori = 100;
	p->verti = 50;
	p->ko = 1;
	p->alti = 0.1;
}

void    main_loop(t_pos *t, t_var *v)
{
    //fdf(t, v);
	fdf2(t, v);
	mlx_hook(t->win_ptr, 2, 0, push_key, t);
    mlx_loop(t->mlx_ptr);
}

int        push_key(int key, void *param)
{
    t_pos 		*tmp;
	t_var		*v = NULL;

    tmp = param;
    if (key == 123)
        tmp->hori -= 50;
    if (key == 124)
        tmp->hori += 50;
    if (key == 125)
        tmp->verti += 50;
    if (key == 126)
        tmp->verti -= 50;
	if (key == 78 && tmp->ko >= 10)
		tmp->ko -= 5;
	if (key == 69 && tmp->ko <= 100)
		tmp->ko += 5;
	if (key == 116)
		tmp->alti += 0.1;
	if (key == 121)
		tmp->alti -= 0.1;
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

void		fdf(t_pos *t, t_var *v)
{
	int		a;

	v = ft_memalloc(sizeof(t_var));
	a = -1;
	while (++a < t->nb - t->nb / t->line)
	{
		v->x0 = ft_isometric_x(t->pos[a].x, t->pos[a].y, t);
		v->x1 = ft_isometric_x(t->pos[a + t->col].x, t->pos[a + t->col].y, t);
		v->y0 = ft_isometric_y(t->pos[a].x, t->pos[a].y, -t->pos[a].z/2, t);
		v->y1 = ft_isometric_y(t->pos[a + t->col].x, t->pos[a + t->col].y, -t->pos[a + t->col].z/2, t);
		if (t->pos[a].x != t->pos[a + t->col].x && t->pos[a].y == t->pos[a + t->col].y)
			line(v, t);
	}
	a = -1;
	while (++a < t->nb)
	{
		v->x0 = ft_isometric_x(t->pos[a].x, t->pos[a].y, t);
		v->x1 = ft_isometric_x(t->pos[a + 1].x, t->pos[a + 1].y, t);
		v->y0 = ft_isometric_y(t->pos[a].x, t->pos[a].y, -t->pos[a].z/2, t);
		v->y1 = ft_isometric_y(t->pos[a + 1].x, t->pos[a + 1].y, -t->pos[a + 1].z/2, t);
		if(t->pos[a].x == t->pos[a + 1].x)
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
		v->x0 = (t->pos[a].x + t->alti * t->pos[a].z) * t->ko;
		v->x1 = (t->pos[a + t->col].x + t->alti * t->pos[a + t->col].z) * t->ko;
		v->y0 = (t->pos[a].y + t->alti * t->pos[a].z) * t->ko;
		v->y1 = (t->pos[a + t->col].y + t->alti * t->pos[a + t->col].z) * t->ko;
		if (t->pos[a].x != t->pos[a + t->col].x && t->pos[a].y == t->pos[a + t->col].y)
			line(v, t);
	}
	a = -1;
	while (++a < t->nb)
	{
		v->x0 = (t->pos[a].x + t->alti * t->pos[a].z) * t->ko;
		v->x1 = (t->pos[a + 1].x + t->alti * t->pos[a + 1].z) * t->ko;
		v->y0 = (t->pos[a].y + t->alti * t->pos[a].z) * t->ko;
		v->y1 = (t->pos[a + 1].y + t->alti * t->pos[a + 1].z) * t->ko;
		if(t->pos[a].x == t->pos[a + 1].x)
			line(v, t);
	}
}
int			main(int argc, char **argv)
{
	int			fd;
	char		*str;
	int			**tab;
	int			a;
	t_parce		p;
	t_pos		*t;
	t_var		*v;

	if (argc != 2)
		exit(0);
	a = 0;
	fd = open(argv[1], O_RDONLY);
	str = ft_strnew(1);
	str = ft_read_line(str, fd);
	fill_parce(&p);
	tab = ft_parce(str, &p);
	v = NULL;
	t = fill_pos(tab, str, a);
	init_window(t);
	main_loop(t, v);
	free(str);
	free(tab);

	return (0);
}
