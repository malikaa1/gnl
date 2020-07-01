/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:21:53 by mrahmani          #+#    #+#             */
/*   Updated: 2020/06/28 21:24:07 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_line(char *str)
{
	char *line;
	static int index = 0;
	int start;

	start = index;
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
		{
			line = ft_substr(str, start, (index - start));
			index++;
			return (line);
		}
		index++;
	}
	if ((index - start) > 0)
		return (ft_substr(str, start, (index - start)));
	return (NULL);
}

char *read_line(int fd, int **eof)
{
	#if BUFFER_SIZE > 0
	char *str;
	char buff[BUFFER_SIZE];
	size_t bytes;
	char *val;

	str = ft_strdup("");
	bytes = 1;
	while (ft_strchr(str, '\n') == NULL && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes > 0)
		{
			val = ft_substr(buff, 0, bytes);
			str = ft_strjoin(str, val);
			free(val);
		}
	}
	if (bytes == 0)
		**eof = 1;
	return (str);
	#else
		return NULL;
	#endif
}

int get_next_line(int fd, char **line)
{
	static char *str;
	int eof;
	int *ptr1;
	int **ptr2;
	if(BUFFER_SIZE <= 0){
		*line = ft_strdup("");
		return 0;
	}

	eof = 0;
	ptr1 = &eof;
	ptr2 = &ptr1;
	if (str == NULL)
		str = ft_strdup("");
	str = ft_strjoin(str, read_line(fd, ptr2));
	if (str)
	{
		*line = extract_line(str);
		if ((*line != NULL && ft_strlen(*line) != 0) || eof != 1)
			return (1);
		*line = ft_strdup("");
		return (0);
	}
	return (0);
}
/*
int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *line[1000];
	int ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, line);
		printf("=> %s*/

// int main()
// {
// 	int fd = open("file.txt", O_RDONLY);
// 	char *line[1000];
// 	int ret = 1;
// 	while (ret == 1)
// 	{
// 		ret = get_next_line(fd, line);
// 		if (ret != 0)
// 		{
// 			printf("=> %s\n", *line);
// 			char **c = line;
// 			c++;
// 		}
// 	}
// }
