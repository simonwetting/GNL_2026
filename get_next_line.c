/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 10:50:27 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/30 17:51:55 by swetting      ########   odam.nl         */
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

void	use_rest(char *rest, char **buf1, int fd, int *bytes_read)
{
	if (!(rest))
	{
		*bytes_read = read(fd, *buf1, BUFFER_SIZE);
		*buf1 = malloc(BUFFER_SIZE + 1);
		(*buf1)[*bytes_read] = 0;
	}
	else
	{
		//free(*buf1);
		*buf1 = ft_strdup(rest);
		//free(*rest);
		//*rest = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*buf1;
	char		*buf2;
	int			bytes_read;
	char		*newline;
	//static char	*rest = NULL;
	static char	rest[BUFFER_SIZE];
	char		*output;

	if (BUFFER_SIZE < 1)
		return (0);
	use_rest(rest, &buf1, fd, &bytes_read);
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
		if (bytes_read < BUFFER_SIZE && ft_strchr(buf1, '\n') == 0)
			return (buf1);
	}
	ft_subcpy(ft_strchr(buf1, '\n') + 1,
			ft_strlen(buf1) - (ft_strchr(buf1, '\n') - buf1), rest);
	output =  ft_substr(buf1, ft_strchr(buf1, '\n') - buf1 + 1);
	//return (ft_substr(buf1, ft_strchr(buf1, '\n') - buf1 + 1));
	free(buf1);
	return (output);
}

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