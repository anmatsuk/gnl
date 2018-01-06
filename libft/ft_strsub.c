/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 17:06:39 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/15 17:06:41 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (s)
	{
		i = 0;
		res = (char*)malloc((len + 1) * sizeof(char));
		if (res == NULL)
			return (NULL);
		res[len] = '\0';
		while (i < len)
		{
			*(res + i) = *(s + start);
			i++;
			start++;
		}
		return (res);
	}
	return (NULL);
}
