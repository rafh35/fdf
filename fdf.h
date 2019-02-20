/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 13:26:18 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 14:36:21 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 1000
# define H 1080
# define L 1920

# include "unistd.h"
# include <stdio.h>
# include "fcntl.h"
# include <math.h>
# include "./libft/libft.h"
# include "./libmlx/includes/mlx.h"

typedef	struct	s_algo
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_algo;

typedef struct	s_var
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
}				t_var;

typedef struct	s_parce
{
	int			x;
	int			y;
	int			i;
	int			len;
	int			col;
	int			nb;
}				t_parce;

typedef struct	s_position
{
	int			x;
	int			y;
	int			z;
}				t_position;

typedef struct	s_pos
{
	t_position	*pos;
	void		*mlx_ptr;
	void		*win_ptr;
	int			hori;
	int			verti;
	int			ko;
	double		alti;
	int			line;
	int			col;
	int			nb;
	double		a;
	double		b;
}				t_pos;

char			*ft_read_line(char *str, int fd);
size_t			ft_c_strlen(const char *str, char c);
int				ft_count_line(char *str);
void			fill_parce(t_parce *s);
int				**ft_parce(char *str, t_parce *s);
int				ft_count_nbr(char *str);
t_pos			*fill_var_pos(char *src);
t_pos			*fill_pos(int **str, char *src, int a);
void			init_window(t_pos *p, char **argv);
t_var			*init_var(int x0, int y0, int x1, int y1, int z, int z2);
t_var			*init_var2(int x0, int y0, int x1, int y1, int z, int z2);
void			line(t_var *v, t_pos *p);
void			fdf(t_pos *t, t_var *v);
void			fdf2(t_pos *t, t_var *v);
double			iso_x(int x, int y, t_pos *p);
double			iso_y(int x, int y, int z, t_pos *p);
int				push_key(int key, void *param);
int				ft_cavx(int x, int z, t_pos *p);
int				ft_cavy(int y, int z, t_pos *p);
void			legend(t_pos *t);
void			main_loop(t_pos *t, t_var *v);
int				push_key(int key, void *param);

#endif
