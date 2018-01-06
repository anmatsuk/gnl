/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:14:31 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/13 14:14:33 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	const char	*s;
	char		*d;
	int			i;

	i = 0;
	s = src;
	d = dst;
	while (*(s + i) != '\0')
	{
		*(d + i) = *(s + i);
		i++;
	}
	*(d + i) = '\0';
	return (d);
}
