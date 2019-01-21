/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 13:06:40 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 15:29:06 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*maill;

	if (!(maill = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (content == NULL)
	{
		maill->content = NULL;
		maill->content_size = 0;
	}
	else
	{
		maill->content = (malloc(content_size));
		maill->content = ft_memcpy(maill->content, content, content_size);
		maill->content_size = content_size;
	}
	maill->next = NULL;
	return (maill);
}
