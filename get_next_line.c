/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:52:30 by amatsuk           #+#    #+#             */
/*   Updated: 2018/01/05 12:48:09 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	read_input(int fd, char **line)
{
	char	*input;
	int		cur;

	input = malloc(BUFF_SIZE + 1);
	if ((cur = read(fd, input, BUFF_SIZE)) > 0)
	{
		input[cur] = '\0';
		if (ft_strlen(*line) )
		ft_strcat(*line, input);
		free(input);
		return (0);
	}
	else
	{
		free(input);
		if (cur == -1)
			return (-1);
		return (1);
	}
}

static void	copy_str(char **next_line, char **line, size_t pos)
{
	size_t i;
	size_t len;

	i = pos;
	len = ft_strlen(*line);
	(*next_line)[i] = '\0';
	while (i > 0)
	{
		(*next_line)[i - 1] = (*line)[i - 1];
		i--;
	}
	i = 0;
	while (++pos < len)
	{
		(*line)[i] = (*line)[pos];
		i++;
	}
	(*line)[i] = '\0';
}

static char	*get_line(const int fd, char *line, int *err, size_t i)
{
	char		*next_line;
	int			k;

	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		next_line = (char *)malloc(sizeof(char) * (i + 1));
		copy_str(&next_line, &line, i);
		return (next_line);
	}
	k = read_input(fd, &line);
	if (k == -1)
		*err = 1;
	if ((k && line[0] == '\0') || k == -1)
		return (NULL);
	if (k)
	{
		next_line = (char *)malloc(sizeof(char) * (i + 1));
		copy_str(&next_line, &line, i);
		return (next_line);
	}
	return (get_line(fd, line, err, i));
}

int			get_next_line(const int fd, char **line)
{
	static char **rest;
	char		*result;
	int			err;
	int			i;

	err = 0;
	i = -1;
	if (fd > CHAR_SIZE || fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!rest)
		rest = (char**)malloc(sizeof(char*) * (CHAR_SIZE + 1));
	if (!*(rest + fd))
	{
		rest[fd] = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		rest[fd][0] = '\0';
	}
	result = get_line(fd, rest[fd], &err, 0);
	if (result == NULL && err)
		return (-1);
	*line = result;
	if (result == NULL)
		return (0);
	return (1);
}
