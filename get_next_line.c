/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:55:07 by psevilla          #+#    #+#             */
/*   Updated: 2024/10/16 21:55:14 by psevilla         ###   ########.fr       */
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
	else
	{
		if (buf)
		{
			free (temp);
			return (buf);
		}
		free(buf);
		free(temp);
		return (NULL);
	}
	return (NULL);
}

char	*ft_new_line(int fd, char *buf)
{
	int		chars;
	char	*temp;

	if (!buf)
		buf = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	chars = 1;
	while (chars)
	{
		chars = read(fd, temp, BUFFER_SIZE);
		if (chars <= 0)
			return (ft_free(chars, buf, temp));
		temp[chars] = '\0';
		buf = ft_strjoin(buf, temp);
		if (ft_strenter(buf) || chars == 0)
			break ;
	}
	free(temp);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = ft_new_line(fd, buf);
	if (!buf)
		return (NULL);
	new_line = ft_strenter(buf);
	if (new_line)
	{
		*new_line = '\0';
		line = ft_strdup(buf);
		if (!line)
			return (NULL);
		buf = new_line + 1;
		return (line);
	}
	if (*buf)
	{
		line = ft_strdup(buf);
		free(buf);
		buf = NULL;
		return (line);
	}
	return (NULL);
}
