/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:52:54 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/13 14:52:55 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char		*str1;
	const char	*str2;
	int			i;
	size_t		j;

	j = 0;
	i = ft_strlen(s1);
	str1 = s1;
	str2 = s2;
	while (j < ft_strlen(s2))
	{
		*(str1 + i) = *(str2 + j);
		i++;
		j++;
	}
	*(str1 + i) = '\0';
	return (str1);
}
