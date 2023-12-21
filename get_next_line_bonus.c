/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:55:19 by mkimdil           #+#    #+#             */
/*   Updated: 2023/12/02 19:40:07 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	line = ft_calloc((ft_strlen(buffer) - i + 1), 1);
	if (!line)
		return (free(line), free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	return (free(buffer), line);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(line), free(buffer), NULL);
	line[i] = '\0';
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		line;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer || !res)
		return (free(res), free(buffer), NULL);
	line = 1;
	while (line > 0)
	{
		line = read(fd, buffer, BUFFER_SIZE);
		if (line == -1)
			return (free(res), free(buffer), NULL);
		buffer[line] = '\0';
		res = ft_join(res, buffer);
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}
