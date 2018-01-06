/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:54:27 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/13 15:54:29 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*str1;
	const char	*str2;
	int			i;
	size_t		j;

	j = 0;
	i = ft_strlen(s1);
	str1 = s1;
	str2 = s2;
	while (j < ft_strlen(s2) && j < n)
	{
		*(str1 + i) = *(str2 + j);
		i++;
		j++;
	}
	*(str1 + i) = '\0';
	return (str1);
}
