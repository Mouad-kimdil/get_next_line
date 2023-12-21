/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:55:06 by mkimdil           #+#    #+#             */
/*   Updated: 2023/11/29 17:52:01 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str) + 1;
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return (str + i);
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(str) + 1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	char	*str;
	char	*str1;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (ft_strdup(""));
	else
		str1 = ft_strdup(s1);
	str = malloc(sizeof (char) * ((ft_strlen(str1)) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (str1[++i])
		str[i] = str1[i];
	j = i;
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	free(str1);
	return (str);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
