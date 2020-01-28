/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:01:13 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/01/27 15:06:02 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE];
	static size_t	bytes;

	if (fd == -1)
		return (0);
	bytes = read(fd, buf, BUFFER_SIZE);
	while(bytes > 0)
	{
		
		bytes = bytes + read(fd, buf, BUFFER_SIZE);
	}
	
}
int main()
{
	char *line;
	int fd = open("hola", O_RDONLY)
	get_next_line(fd, &line);
	printf("Línea 1: %s\n", line);
	get_next_line(fd, &line);
	printf("Línea 2: %s\n", line);
	get_next_line(fd, &line);
	printf("Línea 3: %s\n", line);
	close(fd);
}
