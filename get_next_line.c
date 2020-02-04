/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <ajuncosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:01:13 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/02/04 14:11:46 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (stat[i] == '\0')
	{
		/* si el archivo hubiese estado vacío, stat habría tenido solo 		*/
		/* un '\0', i sería igual a 0 y el substr a continuación retornará 	*/
		/* un strdup de un string vacío, por eso no me hace falta comprobar */
		/* antes si el archivo tiene algo 									*/
		if (!(*line = ft_substr(stat, 0, i)))
			return (-1);
	}
	free(stat);
	stat = NULL;
	/* si no pones = NULL, stat se queda siendo un puntero al sitio donde 			*/
	/* estaba el malloc (es decir que dentro tiene la dirección de ese sitio) 		*/
	/* y como es static, al pasar los tests cuando vuelve a llamar a la 			*/
	/* función pero con otro archivo distinto, la stat existe pero sigue apuntando 	*/
	/* a un sitio que no está alocado, que va a tener memoria random. Para 			*/
	/* los casos que no está vacío el archivo no pasa nada porque se vuelve a 		*/
	/* alocar, pero en el vacío pasa directamente a abajo 							*/
	return (0);
}
