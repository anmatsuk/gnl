/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:15:43 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/12 17:15:45 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;
	char		cc;

	str = s;
	cc = c;
	i = 0;
	while (i < n)
	{
		if (*(str + i) == cc)
			return (void*)(str + i);
		i++;
	}
	return (NULL);
}
