/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:01:13 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/01/31 19:50:33 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 1: Se ha leído una línea
 * 0: Se ha terminado la lectura
 * -1: Ha ocurrido un error
 */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	size_t		bytes;
	static char	*stat;
	size_t		i;

	if (fd == -1 || !line || read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	if (!stat)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		if (!(stat = ft_strdup(buf)))
			return (-1);
	}
	i = 0;
	while (stat[i] != '\n' && stat[i] != '\0')
		i++;
	if (stat[i] == '\n')
	{
		if (!(*line = ft_substr(stat, 0, i)))
			return (-1);
		if (!(stat = ft_substr(stat, i + 1, ft_strlen(stat) - i)))
			return (-1);
		return (1);
	}
	else
	{
		while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[bytes] = '\0';
			if (!(stat = ft_strjoin(stat, buf)))
				return (-1);
			i = 0;
			while (stat[i] != '\n' && stat[i] != '\0')
				i++;
			if (stat[i] == '\n')
			{
				if (!(*line = ft_substr(stat, 0, i)))
					return (-1);
				if (!(stat = ft_substr(stat, i + 1, ft_strlen(stat) - i)))
					return (-1);
				return (1);
			}
		}
	}
	free(stat);
	return (0);
}
int main()
{
	char *line;
	int fd = open("hola", O_RDONLY);
	int i = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		printf("%s -> return: %d\n", line, i);
		free(line);
	}
	close(fd);
}
