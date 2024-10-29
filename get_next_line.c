/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:55:07 by psevilla          #+#    #+#             */
/*   Updated: 2024/10/29 20:58:25 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}

char	*ft_free(char *buf, char *temp)
{
	free(buf);
	free(temp);
	return (NULL);
}

char	*ft_new_line(int fd, char *buf)
{
	int		chars;
	char	*temp;
	char	*new_buf;

	if (!buf)
		buf = ft_calloc(1, sizeof(char));
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (ft_free(buf, NULL));
	while (temp)
	{
		chars = read(fd, temp, BUFFER_SIZE);
		if (chars < 0)
			return (ft_free(buf, temp));
		temp[chars] = '\0';
		new_buf = ft_strjoin(buf, temp);
		free(buf);
		buf = new_buf;
		if (ft_strenter(buf) || chars == 0)
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

	if (!*buf)
		return (NULL);
	new_line = ft_strenter(*buf);
	if (new_line)
	{
		line = ft_substr(*buf, 0, new_line - *buf + 1);
		if (!line)
			return (NULL);
		new_buf = ft_strdup(new_line + 1);
		free(*buf);
		*buf = new_buf;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_new_line(fd, buf);
	if (!buf)
		return (ft_free(buf, NULL));
	line = ft_line(&buf);
	if (!line && ft_strlen(buf) > 0)
	{
		line = ft_strdup(buf);
		free (buf);
		buf = ft_strdup("");
	}
	return (line);
}
