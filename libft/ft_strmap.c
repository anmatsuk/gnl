/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:44:24 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/15 15:44:26 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	if (s)
	{
		i = 0;
		res = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (res)
		{
			res[ft_strlen(s)] = '\0';
			while (*s != '\0')
			{
				*(res + i) = f(*s);
				i++;
				s++;
			}
		}
		else
			return (NULL);
		return (res);
	}
	return (NULL);
}
