/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 11:00:59 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/31 14:04:19 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd = open("41nl", O_RDONLY);
	char	*str = get_next_line(fd);
	printf("GNL>%s", str);
	str = get_next_line(fd);
	printf("GNL>%s", str);
	str = get_next_line(fd);
	printf("GNL>%s", str);
	str = get_next_line(fd);
	printf("GNL>%s", str);
}