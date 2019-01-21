/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 10:12:02 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 17:44:10 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char		*str;
	size_t		len;
	size_t		i;

	len = ft_strlen(src);
	if (!(str = ft_memalloc(len)))
		return (NULL);
	i = 0;
	while (i < n && src && str)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
