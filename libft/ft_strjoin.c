/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 17:17:02 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/15 17:17:04 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*join(char const *s1, char const *s2, char *res)
{
	int i;

	i = 0;
	if (s1)
	{
		while (*s1 != '\0')
		{
			*(res + i) = *(s1);
			i++;
			s1++;
		}
	}
	if (s2)
	{
		while (*s2 != '\0')
		{
			*(res + i) = *(s2);
			i++;
			s2++;
		}
	}
	return (res);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;

	len = 0;
	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	if (!(res = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	res[len] = '\0';
	return (join(s1, s2, res));
}
