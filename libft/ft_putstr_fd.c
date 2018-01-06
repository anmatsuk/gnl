/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:46:07 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/20 17:46:08 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < ft_strlen(s))
		{
			ft_putchar_fd(*(s + i), fd);
			i++;
		}
	}
}
