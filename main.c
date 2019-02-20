/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/26 12:05:51 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 14:35:10 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			check_error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == ' '
		|| str[i] == '\n' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

static char	*start(char **argv, int fd)
{
	char	*str;

	fd = open(argv[1], O_RDONLY);
	str = ft_strnew(1);
	str = ft_read_line(str, fd);
	return (str);
}

int			main(int argc, char **argv)
{
	char	*str;
	int		**tab;
	t_parce	p;
	t_pos	*t;
	t_var	*v;

	if (argc != 2)
		exit(0);
	str = start(argv, 0);
	if (check_error(str) == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	fill_parce(&p);
	tab = ft_parce(str, &p);
	v = NULL;
	t = fill_pos(tab, str, 0);
	init_window(t, argv);
	main_loop(t, v);
	free(str);
	free(tab);
	return (0);
}
