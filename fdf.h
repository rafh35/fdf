/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 13:26:18 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 16:07:02 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 10000

# include "unistd.h"
# include <stdio.h>
# include "fcntl.h"
# include <math.h>
# include "./libft/libft.h"
# include "./libmlx/includes/mlx.h"

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

typedef struct	s_var
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	double			a;
	double			b;
}				t_var;

typedef struct	s_parce
{
	int			x;
	int			y;
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
	int			line;
	int			col;
	int			nb;
}				t_pos;

char			*ft_read_line(char *str, int fd);
size_t			ft_c_strlen(const char *str, char c);
int				ft_count_line(char *str);
void			fill_parce(t_parce *p);
int				**ft_parce(char *str, t_parce *p);
int				ft_count_nbr(char *str);
t_pos			*fill_var_pos(char *src);
t_pos			*fill_pos(int **str, char *src, int a);
void 			init_window(t_window *w);
t_var			*init_var(int x1, int y1, int x2, int y2);
void			line(t_var *v, t_window *w);
void			fdf(t_window *w, t_pos *t, t_var *v);
double			ft_isometric_x(int x, int y);
double			ft_isometric_y(int x, int y, int z);

#endif
