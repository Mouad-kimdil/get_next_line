/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:55:13 by mkimdil           #+#    #+#             */
/*   Updated: 2023/12/01 15:30:58 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

char	*ft_join(char *buffer, char *buf);
char	*get_next_line(int fd);
char	*ft_strrchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *str);

#endif