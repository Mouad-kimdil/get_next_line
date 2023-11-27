/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:55:23 by mkimdil           #+#    #+#             */
/*   Updated: 2023/11/27 03:40:09 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_next_line(char *buffer);
char	*ft_join(char *buffer, char *buf);
char	*ft_get_line(char *buffer);
char	*ft_read_file(int fd, char *res);
char	*get_next_line(int fd);
char	*ft_strrchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *str);

#endif