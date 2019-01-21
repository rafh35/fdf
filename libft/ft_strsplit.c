/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 09:00:12 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 14:57:18 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str;
	int		j;
	int		k;
	int		l;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = ft_memalloc(sizeof(char *) * (ft_nbrword(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		l = i;
		j = 0;
		while (s[i] != c && s[i] && ++i)
			j++;
		if (j)
			str[k++] = ft_strndup(s + l, j);
	}
	return (str);
}
