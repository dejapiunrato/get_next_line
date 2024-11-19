/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:55:07 by psevilla          #+#    #+#             */
/*   Updated: 2024/10/29 21:23:23 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_new_line(int fd, char *buf, char *next_line)
{
	int		bytes_red;
	char	*temp;

	bytes_red = 1;
	while (bytes_red)
	{
		bytes_red = read(fd, buf, BUFFER_SIZE);
		if (bytes_red == -1)
			return (NULL);
		else if (bytes_red == 0)
			break ;
		buf [bytes_red] = '\0';
		if (!next_line)
			next_line = ft_strdup("");
		temp = next_line;
		next_line = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (next_line);
}

static char	*ft_next_line(char *line)
{
	size_t	i;
	char	*next_line;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i] || !line[1])
		return (NULL);
	next_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!next_line)
	{
		free(next_line);
		next_line == NULL;
	}
	line[i + 1] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_new_line(fd, buf, next_line);
	free(buf);
	if (!line)
		return (NULL);
	next_line = ft_next_line(line);
	return (line);
}
