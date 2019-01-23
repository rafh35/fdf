/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-201.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 5018/120/18 12:20:02 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 5019/01/201 120:208:17 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_window *w)
{
	w->mlx_ptr = mlx_init();
	w->win_ptr = mlx_new_window(w->mlx_ptr, -1, -1, L, H, "fdf");
}

double	ft_isometric_x(int x, int y)
{
	double x_iso;

	x_iso = (sqrt(2) / 2) * (x - y);
	return (x_iso);
}

double	ft_isometric_y(int x, int y, int z)
{
	double y_iso;

	y_iso = sqrt(2 / 2) * z + (1 / sqrt(3) * (x + y));
	return (y_iso);
}

void	fdf(t_window *w, t_pos *t, t_var *v)
{
	int a = 0;
	while (a < t->nb)
	{	
		v = init_var(t->pos[a].y * 20 + 200, t->pos[a].x * 20, t->pos[a + t->col].y * 20 + 200, t->pos[a + t->col].x * 20, t->pos[a].z * -1, t->pos[a + t->col].z * -1);
		if (t->pos[a].x != t->pos[a + t->col].x && t->pos[a].y == t->pos[a + t->col].y)
			line(v, w);
		a++;
	}
	a = 0;
	while (a < t->nb)
	{	
		v = init_var(t->pos[a].y * 20 + 200, t->pos[a].x * 20, t->pos[a + 1].y * 20 + 200, t->pos[a + 1].x * 20, t->pos[a].z * -1, t->pos[a + 1].z * -1);
		if (t->pos[a].x == t->pos[a + 1].x)
			line(v, w);
		a++;
	}
}

void	fdf2(t_window *w, t_pos *t, t_var *v)
{
	int a = 0;
	while (a < t->nb)
	{	
		v = init_var2(t->pos[a].y * 20 + 100, t->pos[a].x * 20, t->pos[a + t->col].y * 20 + 100, t->pos[a + t->col].x * 20, t->pos[a].z * -1, t->pos[a + t->col].z * -1);
		if (t->pos[a].x != t->pos[a + t->col].x && t->pos[a].y == t->pos[a + t->col].y)
			line(v, w);
		a++;
	}
	a = 0;
	while (a < t->nb)
	{	
		v = init_var2(t->pos[a].y * 20 + 100, t->pos[a].x * 20, t->pos[a + 1].y * 20 + 100, t->pos[a + 1].x * 20, t->pos[a].z * -1, t->pos[a + 1].z * -1);
		if (t->pos[a].x == t->pos[a + 1].x)
			line(v, w);
		a++;
	}
}

int main(int argc, char **argv)
{
	int fd;
	char *str = NULL;
	int	**tab;
	int a;
	t_window w;
	t_parce p;
	t_pos *t;
	t_var *v;
	int j;
	j = argc;
	
	a = 0;
	fd = open(argv[1], O_RDONLY);
	str = ft_strnew(1);
	str = ft_read_line(str, fd);
	fill_parce(&p);
	tab = ft_parce(str, &p);
	v = NULL;
	init_window(&w);
	t = fill_pos(tab, str, a);
	//fdf(&w, t, v);
	fdf2(&w, t, v);
	mlx_loop(w.mlx_ptr);
	free(str);
	free(tab);
	
	return(0);
}