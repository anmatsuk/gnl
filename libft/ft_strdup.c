/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:03:38 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/13 14:03:39 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*res;
	const char	*str1;
	int			i;
	int			len;

	str1 = s1;
	len = ft_strlen(str1);
	i = 0;
	res = (char*)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		*(res + i) = *(str1 + i);
		i++;
	}
	*(res + i) = '\0';
	return (res);
}
