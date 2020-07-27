/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:21:53 by mrahmani          #+#    #+#             */
/*   Updated: 2020/07/19 17:10:34 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void safe_free(void **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char *extract_line(char **str, int eof, int **last_line)
{
	char *line;
	int index = 0;
	char *old_str = *str;
	while (old_str && old_str[index] != '\0')
	{
		if (old_str[index] == '\n')
		{
			line = ft_substr(old_str, 0, index);
			*str = ft_substr(old_str, index + 1, ft_strlen(old_str));
			safe_free((void **)&old_str);
			index++;
			return (line);
		}
		index++;
	}
	if (index >= 0)
	{
		if (eof == 1)
		{
			**last_line = 1;
		}
		return (ft_substr(*str, 0, index));
	}
	return (NULL);
}

#if BUFFER_SIZE > 0
char *read_line(int fd, int **eof)
{
	char *str;
	char buff[BUFFER_SIZE + 1];
	size_t bytes;
	char *val;

	str = ft_strdup("");
	bytes = 1;
	while (ft_strchr(str, '\n') == NULL && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes > 0)
		{
			buff[bytes] = '\0';
			val = ft_substr(buff, 0, bytes);
			char *new_str = ft_strjoin(str, val);
			safe_free((void **)&str);
			safe_free((void **)&val);
			str = new_str;
		}
	}
	if (bytes == 0)
		**eof = 1;
	return (str);
}
#endif

int get_next_line(int fd, char **line)
{
	static char *str;
	int eof;
	int *ptr1;
	int **ptr2;
	if (BUFFER_SIZE <= 0)
	{
		*line = NULL;
		return 0;
	}

	eof = 0;
	ptr1 = &eof;
	ptr2 = &ptr1;
	if (str == NULL)
		str = ft_strdup("");
	char *new_line = read_line(fd, ptr2);
	char *oldStr = str;
	str = ft_strjoin(oldStr, new_line);
	safe_free((void **)&oldStr);
	safe_free((void **)&new_line);
	if (str)
	{
		int i = 0;
		int *last_line = &i;
		*line = extract_line(&str, eof, &last_line);
		if (i == 0)
			return (1);
		safe_free((void **)&str);
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
