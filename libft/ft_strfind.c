/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 13:14:28 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/28 13:14:30 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strfind(char const *s, int c)
{
	size_t	i;
	size_t	res;

	if (!s)
		return (0);
	i = -1;
	res = 0;
	while (++i < ft_strlen(s))
	{
		if (*(s + i) == c)
			res++;
	}
	return (res);
}
