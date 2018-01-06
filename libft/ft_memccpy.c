/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:02:53 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/12 16:02:55 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src,
					int c, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char*)dst;
	s = (char*)src;
	while (i < n)
	{
		*(d + i) = *(s + i);
		if (*(s + i) == c)
			return ((void*)&d[i + 1]);
		i++;
	}
	return (NULL);
}
