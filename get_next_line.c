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
void safe_free(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
char *find_line(char *old_str, int *index, char **str)
{
	char *line;

	line = ft_substr(old_str, 0, *index);
	*str = ft_substr(old_str, *index + 1, ft_strlen(old_str));
	free(old_str);
	*index = *index + 1;
	return (line);
}
char *extract_line(char **str, int eof, int *last_line)
{
	int index;
	char *old_str;

	index = 0;
	old_str = *str;
	while (old_str && old_str[index] != '\0')
	{
		if (old_str[index] == '\n')
			return (find_line(old_str, &index, str));
		index++;
	}
	if (index >= 0)
	{
		if (eof == 1)
			*last_line = 1;
		return (ft_substr(*str, 0, index));
	}
	return (NULL);
}
char *ft_read(size_t bytes, char buff[], char *str)
{
	char *val;
	char *new_str;

	if (bytes > BUFFER_SIZE)
	{
		//*error = -1;
		return (NULL);
	}
	if (bytes > 0)
	{
		buff[bytes] = '\0';
		val = ft_substr(buff, 0, bytes);
		new_str = ft_strjoin(str, val);
		free(str);
		free(val);
		str = new_str;
	}
	return (str);
}
char *read_line(int fd, int *eof)
{
	char *str;
	size_t bytes;
	char buff[BUFFER_SIZE + 1];

	str = ft_strdup("");
	bytes = 1;
	// if (BUFFER_SIZE <= 0)
	// {
	// 	*error = -1;
	// 	return NULL;
	// }
	while (ft_strchr(str, '\n') == NULL && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		str = ft_read(bytes, buff, str);
	}
	if (bytes == 0)
		*eof = 1;
	return (str);
}

int get_next_line(int fd, char **line)
{
	static char *str;
	int eof;
	char *new_line;
	int last_line;

	eof = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return -1;
	if (str == NULL)
		str = ft_strdup("");
	new_line = read_line(fd, &eof);
	str = ft_strjoin(str, new_line);
	free(new_line);
	if (str)
	{
		last_line = 0;
		*line = extract_line(&str, eof, &last_line);
		if (last_line == 0)
			return (1);
		safe_free(&str);
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
