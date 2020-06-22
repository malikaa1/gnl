/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:23:05 by mrahmani          #+#    #+#             */
/*   Updated: 2020/06/22 19:49:04 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFF_SIZE 10
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
char	*read_line(int fd, int **eof);
char	*extract_line(char *str);

#endif
