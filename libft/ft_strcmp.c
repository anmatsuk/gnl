/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:13:47 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/14 14:13:49 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str2 = (unsigned char*)s2;
	str1 = (unsigned char*)s1;
	i = 0;
	while (*(str1 + i) || *(str2 + i))
	{
		if (*(str1 + i) != *(str2 + i))
			return ((*(str1 + i) - *(str2 + i)));
		i++;
	}
	return (0);
}
