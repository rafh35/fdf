/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 11:56:26 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 16:40:25 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*dest;

	if (s)
	{
		start = 0;
		end = ft_strlen(s) - 1;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		if (end + 1 == 0)
		{
			dest = (char*)malloc(sizeof(char));
			*dest = '\0';
			return (dest);
		}
		dest = ft_strsub(s, start, end - start + 1);
		return (dest);
	}
	return ((char*)s);
}
