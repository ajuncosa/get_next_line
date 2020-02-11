/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <ajuncosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:01:13 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/02/10 15:07:27 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_complete_the_line(int fd, char **stat, char **line)
{
	int	i;

	if (stat[fd])
	{
		i = ft_strchr_edit(stat[fd], '\n');
		if (i != -1)
		{
			*line = ft_substr(stat[fd], 0, i);
			stat[fd] = ft_substr(stat[fd], i + 1, ft_strlen(stat[fd]) - i);
			return (1);
		}
		else
			*line = ft_substr(stat[fd], 0, ft_strlen(stat[fd]));
		free(stat[fd]);
		stat[fd] = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	size_t		bytes;
	static char	*stat[4096];
	int			result;

	if (fd == -1 || !line || !(buf = malloc(BUFFER_SIZE + 1)) ||
			read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	if (!stat[fd] || ft_strchr_edit(stat[fd], '\n') == -1)
	{
		while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[bytes] = '\0';
			if (!stat[fd])
				stat[fd] = ft_strdup(buf);
			else
				stat[fd] = ft_strjoin(stat[fd], buf);
			if (ft_strchr_edit(stat[fd], '\n') != -1)
				break ;
		}
	}
	result = ft_complete_the_line(fd, stat, line);
	free(buf);
	return (result);
}
