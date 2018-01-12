#include "get_next_line.h"

static void ft_strextend(char **line, char *tmp, size_t tmp_len)
{
	size_t	line_len;
	char 	*line_copy;
	size_t	i;
	
	line_len = 0;
	if (*line)
		line_len = ft_strlen(*line);
	i = 0;
	line_copy = (char*)malloc(sizeof(char) * (tmp_len + line_len + 1));
	*(line_copy + line_len + tmp_len) = '\0';
	line_copy = ft_strncpy(line_copy, *line, line_len);
	i+= line_len;
	free(*line);
	ft_strncpy(line_copy + i, tmp, tmp_len);
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
		ft_strextend(&(line[fd]), tmp, ft_strlen(tmp));
		free(tmp);
		return (1);
	}
	*(tmp) = '\0';
	if (!line[fd])
		ft_strextend(&(line[fd]), tmp, ft_strlen(tmp));
	free(tmp);
	return (code);
}

static char *parse_line(char **line, size_t i)
{
	char	*result;
	char	*copy;
    size_t  len;

    len = ft_strlen(*line);
	result = (char*)malloc(sizeof(char) * (i + 1));
	*(result + i) = '\0';
	result = ft_strncpy(result, *line, i);
	if (i == len)
		**line = '\0';
	else
	{
		copy = (char*)malloc(sizeof(char) * (len - i));
		*(copy + len - i - 1) = '\0';
		i++;
		copy = ft_strncpy(copy, *line + i, len - i);
 		free(*line);
 		*line = copy;
	}
 	return (result);
}

static char	*get_line(const int fd, char **lines, int *code)
{
	int		i;

    if (!(lines[fd]))
        *code = read_from_file(fd, lines);
    i = 0;
    if (lines[fd][0] != '\0')
    	*code = 1;
    else
    	*code = read_from_file(fd, lines);
    while (*code == 1 && lines[fd][i] != '\n')
    {
        if (lines[fd][i] == '\0')
        {
            *code = read_from_file(fd, lines);
            i--;
        }
        i++;
    }
    return (parse_line((lines + fd), i));
}

int			get_next_line(const int fd, char **line)
{
	static char **lines;
	int			code;

	code = 0;
	if (fd < 0 || fd > FD_LIMIT || !line || BUFF_SIZE < 1)
		return (-1);
	if (!lines)
		lines = (char**)malloc(sizeof(char*) * (FD_LIMIT + 1));
	*line = get_line(fd, lines, &code);
	if (code == 0 && ft_strlen(*line) == 0)
	{
		*line = NULL;
		return (0);
	}
	if (code == -1)
		return (-1);
	return (1);
}
