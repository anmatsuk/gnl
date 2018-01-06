/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:34:43 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/15 16:34:46 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s)
	{
		i = 0;
		res = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (res)
		{
			res[ft_strlen(s)] = '\0';
			while (*s != '\0')
			{
				*(res + i) = f(i, *s);
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
