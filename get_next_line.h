/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 10:50:24 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/17 10:50:24 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 50

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

typedef struct s_list
{
	char	*content;
	struct	s_list *next;
}			t_List;

char	*get_next_line(int fd);

#endif