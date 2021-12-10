/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:05:46 by azaid             #+#    #+#             */
/*   Updated: 2021/12/10 07:04:43 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Loop Get Next Line
// Reads line until end of line
// Read must use BUFFER_SIZE gw -D BUFFER_SIZE=n

#include "get_next_line.h"

void ft_strjoin_then_delete(char **str, char *buffer)
{
	char *temp;
	temp = ft_strjoin(*str, buffer);
	ft_strdel(str);
	*str = temp;
	// printf("%s \n ", str);
	return;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;
	size_t new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}

size_t ft_strlcpy(char *dest, const char *src, size_t dst_size)
{
	size_t i;

	i = 0;
	if (!src || !dest)
		return (0);
	if (dst_size)
	{
		while (src[i] && i < dst_size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char *process_line(int reader, char **str)
{
	int len;
	char *tmp;
	char *str_return;

	if (reader == 0 && **str == '\0')
	{
		ft_strdel(str);
		return (NULL);
	}
	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		str_return = ft_substr(*str, 0, len + 1);
		tmp = ft_strdup(&(*str)[len + 1]);
		ft_strdel(str);
		*str = tmp;
		return (str_return);
	}
	str_return = ft_substr(*str, 0, len);
	ft_strdel(str);
	return (str_return);
}

char *get_next_line(int fd)
{
	static char *line;
	char buf[BUFFER_SIZE + 1];
	int reader;

	reader = 1;
	while (reader)
	{
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buf[reader] = '\0';
		if (!line)
			line = ft_strdup(buf);
		else if (line != NULL)
			ft_strjoin_then_delete(&line, buf);
		if (ft_strchr(line, '\n'))
			break;
	}
	return (process_line(reader, &line));
}
