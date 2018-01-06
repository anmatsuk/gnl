/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asciisort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:39:51 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/27 15:39:53 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char			*ft_asciisort(char *s)
{
	size_t	i;
	size_t	j;
	char	tmp;

	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (s);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s) - 1)
	{
		j = -1;
		while (++j < ft_strlen(s) - i - 1)
		{
			if (*(s + j) > *(s + j + 1))
			{
				tmp = *(s + j);
				*(s + j) = *(s + j + 1);
				*(s + j + 1) = tmp;
			}
		}
	}
	return (s);
}
