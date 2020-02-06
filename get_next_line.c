/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <ajuncosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:01:13 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/02/06 11:07:20 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int get_next_line(int fd, char **line)
{
	char		*buf;
	size_t		bytes;
	static char	*stat[4096];
	size_t		i;

	if (fd == -1 || !line || read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!stat[fd])
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		if (!(stat[fd] = ft_strdup(buf)))
			return (-1);
	}
	i = 0;
	while (stat[fd][i] != '\n' && stat[fd][i] != '\0')
		i++;
	if (stat[fd][i] == '\n')
	{
		if (!(*line = ft_substr(stat[fd], 0, i)))
			return (-1);
		if (!(stat[fd] = ft_substr(stat[fd], i + 1, ft_strlen(stat[fd]) - i)))
			return (-1);
		return (1);
	}
	else
	{
		while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[bytes] = '\0';
			if (!(stat[fd] = ft_strjoin(stat[fd], buf)))
				return (-1);
			i = 0;
			while (stat[fd][i] != '\n' && stat[fd][i] != '\0')
				i++;
			if (stat[fd][i] == '\n')
			{
				if (!(*line = ft_substr(stat[fd], 0, i)))
					return (-1);
				if (!(stat[fd] = ft_substr(stat[fd], i + 1, ft_strlen(stat[fd]) - i)))
					return (-1);
				return (1);
			}
		}
	}
	if (stat[fd][i] == '\0')
	{
		/* si el archivo hubiese estado vacío, stat habría tenido solo 		*/
		/* un '\0', i sería igual a 0 y el substr a continuación retornará 	*/
		/* un strdup de un string vacío, por eso no me hace falta comprobar */
		/* antes si el archivo tiene algo 									*/
		if (!(*line = ft_substr(stat[fd], 0, i)))
			return (-1);
	}
	free(stat[fd]);
	stat[fd] = NULL;
	return (0);
}
