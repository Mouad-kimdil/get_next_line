/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:38:04 by mkimdil           #+#    #+#             */
/*   Updated: 2023/12/21 19:16:19 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// str_join with adding free
char	*ft_join(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

// preparing the next line
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
// copy line from the buffer(static variable) to another simple buffer
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
// function that help you to read the file till the new line (\n)
char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		line;

	//allocations with protections 
	if (!res)
		res = ft_calloc(1, 1);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer || !res)
		return (free(res), free(buffer), NULL);
	
	line = 1;
	while (line)
	{
		line = read(fd, buffer, BUFFER_SIZE);
		//protection
		if (line == -1)
			return (free(res), free(buffer), NULL);
		buffer[line] = '\0';
		res = ft_join(res, buffer);
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), res);
}
// get next line
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}

int main(void)
{
	char *str = get_next_line(0);
	printf("%s", str);
	free(str);
	return (0);
}