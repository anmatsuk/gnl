/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:32:12 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/20 16:32:14 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_putstr(char const *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < ft_strlen(s))
		{
			ft_putchar(*(s + i));
			i++;
		}
	}
}
