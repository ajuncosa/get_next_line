/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <ajuncosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:01:13 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/02/10 12:38:44 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char		*buf;
	size_t		bytes;
	static char	*stat[4096];
	size_t		i;

	if (fd == -1 || !line || !(buf = malloc(BUFFER_SIZE + 1)) ||
			read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	if (!stat[fd])
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		stat[fd] = ft_strdup(buf);
	}
	i = 0;
	while (stat[fd][i] != '\n' && stat[fd][i] != '\0')
		i++;
	if (stat[fd][i] == '\n')
	{
		*line = ft_substr(stat[fd], 0, i);
		stat[fd] = ft_substr(stat[fd], i + 1, ft_strlen(stat[fd]) - i);
		return (1);
	}
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		stat[fd] = ft_strjoin(stat[fd], buf);
		i = 0;
		while (stat[fd][i] != '\n' && stat[fd][i] != '\0')
			i++;
		if (stat[fd][i] == '\n')
		{
			*line = ft_substr(stat[fd], 0, i);
			stat[fd] = ft_substr(stat[fd], i + 1, ft_strlen(stat[fd]) - i);
			return (1);
		}
	}
	if (stat[fd][i] == '\0')
		*line = ft_substr(stat[fd], 0, i);
	free(stat[fd]);
	stat[fd] = NULL;
	free(buf);
	return (0);
}
