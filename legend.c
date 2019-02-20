/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 10:11:42 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 14:37:53 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		legend(t_pos *t)
{
	char	*str;
	int		pos[2];

	pos[0] = 0;
	pos[1] = 0;
	str = "Legende :";
	mlx_string_put(t->mlx_ptr, t->win_ptr, pos[0], pos[1], 0x00DC143C, str);
	str = "page up or down  : change altitude";
	mlx_string_put(t->mlx_ptr, t->win_ptr, pos[0], pos[1] + 20, 0x90EE90, str);
	str = "W or S           : x rotation";
	mlx_string_put(t->mlx_ptr, t->win_ptr, pos[0], pos[1] + 40, 0x90EE90, str);
	str = "A or D           : y rotation";
	mlx_string_put(t->mlx_ptr, t->win_ptr, pos[0], pos[1] + 60, 0x90EE90, str);
	str = "+ or -           : change zoom";
	mlx_string_put(t->mlx_ptr, t->win_ptr, pos[0], pos[1] + 80, 0x90EE90, str);
	str = "cursor keys      : move map";
	mlx_string_put(t->mlx_ptr, t->win_ptr, pos[0], pos[1] + 100, 0x90EE90, str);
	str = "esc              : close the  program";
	mlx_string_put(t->mlx_ptr, t->win_ptr, pos[0], pos[1] + 120, 0x90EE90, str);
}
