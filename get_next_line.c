/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:55:07 by psevilla          #+#    #+#             */
/*   Updated: 2024/10/22 18:57:43 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(int chars, char *buf, char *temp)
{
	if (chars < 0)
	{
		free(buf);
		free(temp);
		return (NULL);
	}
	if (buf)
	{
		free (temp);
		return (buf);
	}
	free(buf);
	free(temp);
	return (NULL);
	return (NULL);
}

char	*ft_new_line(int fd, char *buf)
{
	int		chars;
	char	*temp;
	char	*new_buf;

	if (!buf)
		buf = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (1)
	{
		chars = read(fd, temp, BUFFER_SIZE);
		if (chars <= 0)
			return (ft_free(chars, buf, temp));
		temp[chars] = '\0';
		new_buf = ft_strjoin(buf, temp);
		free(buf);
		buf = new_buf;
		if (ft_strenter(buf))
			break ;
	}
	free(temp);
	return (buf);
}

char	*ft_line(char **buf)
{
	char	*line;
	char	*new_line;
	char	*new_buf;

	new_line = ft_strenter(*buf);
	if (new_line)
	{
		*new_line = '\0';
		line = ft_strdup(*buf);
		if (!line)
			return (NULL);
		new_buf = ft_strdup(new_line + 1);
		free(*buf);
		*buf = new_buf;
		return (line);
	}
	if (**buf)
	{
		line = ft_strdup(*buf);
		free(*buf);
		*buf = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_new_line(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_line(&buf);
	return (line);
}
