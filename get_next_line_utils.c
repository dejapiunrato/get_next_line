/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piesito <piesito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:46:04 by gmacias-          #+#    #+#             */
/*   Updated: 2024/10/17 22:04:13 by piesito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strenter(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (buf + i);
		i++;
	}
	return (NULL);
}

char	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	char	*s;

	s = malloc(n * size);
	if (!s)
		return (NULL);
	i = 0;
	while (i < n * size)
		((char *)s)[i++] = 0;
	return (s);
}

char	*ft_strjoin(char *buf, char *temp)
{
	char	*s;
	int		i;

	s = (char *)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(temp) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (*buf)
		s[i++] = *buf++;
	while (*temp)
		s[i++] = *temp++;
	s[i] = '\0';
	return (s);
}

char	*ft_strdup(const char *buf)
{
	size_t	size;
	char	*s;
	char	*aux;

	size = ft_strlen((char *)buf) + 1;
	s = ft_calloc(size, sizeof(char));
	if (s == NULL)
		return (NULL);
	aux = s;
	while (*buf)
		*s++ = *buf++;
	return (aux);
}
