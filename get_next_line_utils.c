/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <ajuncosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:32:34 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/02/10 11:57:16 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*copy;

	if (!(copy = malloc((ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (j < ft_strlen(s1))
	{
		new[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (s == 0)
		return (0);
	if (*s == '\0')
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(new = malloc(len + 1)))
		return (0);
	i = start;
	j = 0;
	while (i < (len + start))
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&copy[i]);
		i++;
	}
	if (s[i] == c)
		return (&copy[i]);
	else
		return (0);
}
