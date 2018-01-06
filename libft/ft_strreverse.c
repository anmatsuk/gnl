/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 13:36:14 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/28 13:36:16 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_strreverse(char *s)
{
	size_t	i;
	char	tmp;

	if (s)
	{
		i = -1;
		while (++i < (ft_strlen(s) / 2))
		{
			tmp = *(s + i);
			*(s + i) = *(s + ft_strlen(s) - 1 - i);
			*(s + ft_strlen(s) - 1 - i) = tmp;
		}
	}
}
