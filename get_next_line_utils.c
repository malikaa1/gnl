/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:00:39 by mrahmani          #+#    #+#             */
/*   Updated: 2020/06/22 19:05:26 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t i;
	char *s;
	
	s = (char *)str;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char *ptr;
	int i;

 	i = 0;
 	if (!(ptr = malloc(ft_strlen(src) + 1)))
		return (NULL);
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	 }	
	ptr[i] = 0;
	return (ptr);
}
