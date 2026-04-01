/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 10:50:27 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/31 15:00:17 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//void	use_rest(char **rest, char **buf1, int fd, int *bytes_read)
//{
//	if (!(*rest))
//	{
//		*bytes_read = read(fd, buf1, BUFFER_SIZE);
//		buf1[*bytes_read] = 0;
//	}
//	else
//	{
//		*buf1 = ft_strdup(*rest);
//		free(*rest);
//		*rest = NULL;
//	}
//}

char	*ft_subcpy(char const *s, size_t len, char *out)
{
	size_t	index;

	index = -1;
	while (++index < len)
		out[index] = s[index];
	out[index] = 0;
	return (out);
}

char	*free_and_return_null(char **p)
{
	free (*p);
	*p = NULL;
	return (NULL);
}

char	*use_rest(char *rest, char **buf1, int fd)
{
	int	i;
	int	bytes_read;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	i = -1;
	*buf1 = malloc(BUFFER_SIZE + 1);
	if (!*buf1)
		return (0);
	if (rest[0] == 0)
	{
		bytes_read = read(fd, *buf1, BUFFER_SIZE);
		if (bytes_read < 0)     // ← ADD THIS CHECK
			return (free_and_return_null(buf1));
		(*buf1)[bytes_read] = 0;
	}
	else
	{
		while (rest[++i])
			(*buf1)[i] = rest[i];
		while (i <= BUFFER_SIZE)
			(*buf1)[i++] = 0;
		rest[0] = 0;
	}
	return ((char *)1);
}

char	*split_buf(char *buf1, char *rest)
{
	ft_subcpy(ft_strchr(buf1, '\n') + 1,
			ft_strlen(buf1) - (ft_strchr(buf1, '\n') - buf1), rest);
	buf1[ft_strchr(buf1, '\n') - buf1 + 1] = 0;
	return (buf1);
}

char	*get_next_line(int fd)
{
	char		*buf1;
	char		*buf2;
	int			bytes_read;
	char		*newline;
	static char	rest[BUFFER_SIZE];

	if(use_rest(rest, &buf1, fd) == 0)
		return (0);
	newline = ft_strchr(buf1, '\n');
	while (!newline)
	{
		buf2 = malloc(BUFFER_SIZE + 1);
		bytes_read = read(fd, buf2, BUFFER_SIZE);
		if (bytes_read < 0)
			return (0);
		buf2[bytes_read] = 0;
		buf1 = ft_strjoin(buf1, buf2);
		newline = ft_strchr(buf1, '\n');
		if (buf1[0] == 0)
			return (free_and_return_null(&buf1));
		if (bytes_read < BUFFER_SIZE && ft_strchr(buf1, '\n') == 0)
			return (buf1);
	}
	return (split_buf(buf1, rest));
}

//return (ft_substr(buf1, ft_strchr(buf1, '\n') - buf1 + 1));



	//buf1 = malloc(BUFFER_SIZE + 1);
	//if (!rest)
	//{
	//	bytes_read = read(fd, buf1, BUFFER_SIZE);
	//	buf1[bytes_read] = 0;
	//}
	//else
	//{
	//	buf1 = ft_strdup(rest);
	//	free(rest);
	//	rest = NULL;
	//}