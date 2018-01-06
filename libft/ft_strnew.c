/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:50:09 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/15 14:50:11 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	if ((mem = (char*)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}
