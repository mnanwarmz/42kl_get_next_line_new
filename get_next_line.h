/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:06:20 by azaid             #+#    #+#             */
/*   Updated: 2021/12/11 12:30:55 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int		ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
char	*ft_strdel(char **str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strjoin_then_delete(char **str, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t dst_size);
char	*process_line(int reader, char **str);

#endif