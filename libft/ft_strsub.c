/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 09:42:25 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 17:27:42 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tron;
	size_t	i;
	size_t	ch;

	i = 0;
	ch = start;
	if (!(tron = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s == NULL)
		return (0);
	while (s[i] && i < len)
	{
		tron[i] = s[start];
		i++;
		start++;
	}
	tron[i] = '\0';
	return (tron);
}
