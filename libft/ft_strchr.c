/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:56:46 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/13 16:56:49 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	const char	*str;
	char		cc;

	cc = c;
	str = s;
	while (*str != '\0')
	{
		if (*str == cc)
			return ((char*)str);
		str++;
	}
	if (cc == '\0')
		return ((char*)str);
	return (NULL);
}
