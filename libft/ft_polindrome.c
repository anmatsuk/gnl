/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_polindrome.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 12:48:02 by amatsuk           #+#    #+#             */
/*   Updated: 2017/07/06 12:48:04 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_polindrome(const char *str)
{
	size_t	len;
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	len = ft_strlen(str);
	while (++i < len / 2)
	{
		if (*(str + i) != *(str + len - i - 1))
			return (0);
	}
	return (1);
}
