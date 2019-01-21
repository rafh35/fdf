/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 11:13:21 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 11:13:53 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char    *ft_realloc(char *str, size_t size)
{
    char        *new;
    size_t        i;

    i = -1;
    new = ft_memalloc(sizeof(char) * size + 1);
    while (++i < size && str[i] != '\0')
        new[i] = str[i];
    free(str);
    return (new);
}