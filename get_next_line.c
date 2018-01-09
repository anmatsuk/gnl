#include "get_next_line.h"

static void ft_strextend(char **line, char *tmp)
{
	size_t	line_len;
	char 	*line_copy;
	int	i;
	int	j;
	
	line_len = 0;
	if (*line)
		line_len = ft_strlen(*line);
	i = -1;
	j = -1;
	line_copy = (char*)malloc(sizeof(char) * (BUFF_SIZE + line_len + 1));
	*(line_copy + line_len + BUFF_SIZE) = '\0';
	while (++i < line_len)
		*(line_copy + i) = *(*line + i);
	free(*line);
	while (++j < BUFF_SIZE)
	{
		*(line_copy + i) = *(tmp + j);
		i++;
	}
	*line = line_copy;
}

static int	read_from_file(const int fd, char **line)
{
	char	*tmp;
	int		code;
	tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if ((code = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		*(tmp + code) = '\0';
		ft_strextend(&(line[fd]), tmp);
		free(tmp);
		return (1);
	}
	*(tmp) = '\0';
	ft_strextend(&(line[fd]), tmp);
	free(tmp);
	return (code);
}

static char *parse_line(char **line, int i)
{
	int		j;
	char	*result;
	char	*copy;

	j = -1;
	result = (char*)malloc(sizeof(char) * (i + 1));
	*(result + i) = '\0';
	while (++j < i)
		*(result + j) = *(*line + j);
	copy = (char*)malloc(sizeof(char) * (ft_strlen(*line) - i + 1));
	*(copy + ft_strlen(*line) - i) = '\0';
	j = 0;
	while(++i < ft_strlen(*line))
	{
		*(copy + j) = *(*line + i);
		j++;
 	}
 	free(*line);
 	*line = copy;
 	return (result);
}

static char	*get_line(const int fd, char **lines, int *code)
{
	char	*line;
	size_t	len;
	int		i;

	if (!*(lines + fd) || ft_strlen(lines[fd]) == 0)
		*code = read_from_file(fd, lines);
	if (*code == -1)
		return (NULL);
	if (*code == 0 && ft_strlen(lines[fd]) == 0)
		return (NULL);
	i = 0;
	while (lines[fd][i] != '\n' && lines[fd][i] != '\0')
		i++;
	if (lines[fd][i] == '\n')
		return (parse_line((lines + fd), i));
	else
		*code = read_from_file(fd, lines);
	return (get_line(fd, lines, code));	
}

int			get_next_line(const int fd, char **line)
{
	static char **lines;
	char		*result;
	int			code;

	code = 0;
	if (fd < 1 || fd > FD_LIMIT || !line || BUFF_SIZE < 1)
		return (-1);
	if (!lines)
		lines = (char**)malloc(sizeof(char*) * (FD_LIMIT + 1));
	*line = get_line(fd, lines, &code);
	if (code == 0 && !(*line))
		return (0);
	if (code == -1)
		return (-1);
	return (1);
}
