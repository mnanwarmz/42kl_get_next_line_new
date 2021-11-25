/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:05:46 by azaid             #+#    #+#             */
/*   Updated: 2021/11/25 13:07:43 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Loop Get Next Line
// Reads line until end of line
// Read must use BUFFER_SIZE gw -D BUFFER_SIZE=n
#include <unistd.h>
#include <stdlib.h>

void *ft_memset(void *s, int c, size_t n)
{
	size_t i;
	char *ch;

	i = 0;
	ch = s;
	while (i < n)
	{
		ch[i] = c;
		i++;
	}
	return (s);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	static char *line;
	static int i;
	int j;
	int c;

	if (read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = 0;
		while (buffer[i] != '\n' || buffer[i] != '\0')
			i++;
		buffer = ft_memset(buffer, 0, BUFFER_SIZE);
		j += i;
	};
	line = malloc(sizeof(char) * j);
	i = 0;
	while (read(fd, line, BUFFER_SIZE) > 0)
		while (line[i] != '\n' || line[i] != '\0')
			i++;
}
