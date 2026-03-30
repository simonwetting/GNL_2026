/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 10:50:30 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/30 16:59:13 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	int		length;

// 	length = 0;
// 	printf("ft_strlen1");
// 	while (*(s+length))
// 		length++;
// 	return length;
// }

size_t	ft_strlen(const char *s)
{
	int		length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	index;
	char	*output;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	output = malloc(len_s1 + len_s2 + 1);
	if (!output)
		return (NULL);
	index = -1;
	while (++index < len_s1)
		output[index] = s1[index];
	index = -1;
	while (++index < len_s2)
		output[len_s1 + index] = s2[index];
	output[len_s1 + index] = 0;
	free (s1);
	free (s2);
	return (output);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = -1;
	while (s[++index])
		if (s[index] == c)
			return ((char *)(s + index));
	return (0);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*out;
// 	size_t	index;

// 	out = malloc(len + 1);
// 	index = -1;
// 	printf("substr");
// 	while (++index < len)
// 		out[index] = s[start + index];
// 	printf("substr2");
// 	out[index] = 0;
// 	return (out);
// }

char	*ft_substr(char const *s, size_t len)
{
	char	*out;
	size_t	index;

	out = malloc(len + 1);
	index = -1;
	while (++index < len)
		out[index] = s[index];
	out[index] = 0;
	return (out);
}

char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	index;
	char	*output;

	length = ft_strlen(s);
	output = malloc(sizeof(char) * length + 1);
	if (!output)
		return (NULL);
	index = -1;
	while (++index < length)
		output[index] = s[index];
	output[index] = 0;
	return (output);
}
