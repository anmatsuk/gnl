/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:52:24 by amatsuk           #+#    #+#             */
/*   Updated: 2017/07/06 11:52:26 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t		ft_wordcount(char const *str)
{
	size_t	count;
	int		f;
	size_t	i;

	count = 0;
	i = 0;
	f = 1;
	while (*(str + i))
	{
		if (*(str + i) != ' ' && *(str + i) != '\n' && *(str + i) != '\r'
			&& *(str + i) != '\t' && *(str + i) != '\f'
			&& *(str + i) != '\v' && f)
		{
			count++;
			f = 0;
		}
		else if (*(str + i) == ' ' || *(str + i) == '\n' || *(str + i) == '\r'
			|| *(str + i) == '\t' || *(str + i) == '\f' || *(str + i) == '\v')
			f = 1;
		i++;
	}
	return (count);
}
