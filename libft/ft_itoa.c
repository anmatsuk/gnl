/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 15:47:41 by amatsuk           #+#    #+#             */
/*   Updated: 2017/06/20 15:47:43 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static	int		get_size(unsigned int n, int size)
{
	if (n == 0)
		return (size);
	size++;
	n = n / 10;
	return (get_size(n, size));
}

static	void	create_str(char *str, int size, int flag, unsigned int n)
{
	int		i;

	i = 0;
	if (flag)
	{
		*str = '-';
		i++;
	}
	while (size > i)
	{
		*(str + size - 1) = (n % 10) + '0';
		n = n / 10;
		size--;
	}
}

char			*ft_itoa(int n)
{
	unsigned int	res;
	int				flag;
	int				size;
	char			*new;

	flag = 0;
	if (n < 0)
	{
		flag = 1;
		res = n * (-1);
	}
	else
		res = n;
	size = get_size(res, 0);
	if (n == 0)
		size = 1;
	new = (char*)malloc((size + flag + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[size + flag] = '\0';
	create_str(new, size + flag, flag, res);
	return (new);
}
