/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:55:07 by psevilla          #+#    #+#             */
/*   Updated: 2024/11/20 21:03:11 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!line[i] || !line[i + 1])
		return (NULL);
	next_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!next_line)
	{
		free(next_line);
		next_line = NULL;
	}
	line[i + 1] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*next_line[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || FOPEN_MAX <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_new_line(fd, buf, next_line[fd]);
	free(buf);
	if (!line)
		return (NULL);
	next_line[fd] = ft_next_line(line);
	return (line);
}
/* #include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define RED "\033[31m"
#define RESET "\033[0m"

void	print_line(const char *line)
{
	if (line)
	{
		for (int i = 0; line[i] != '\0'; i++)
		{
			if (line[i] == '\n')
			{
				write(1, RED, 5);
				write(1, "\\", 1);
				write(1, "n", 1);
				write(1, RESET, 4);
				write(1, "\n", 1);
			}
			else
			{
				write(1, &line[i], 1);
			}
		}
	}
}

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;

	fd = open("prueba.txt", O_RDONLY);
	fd2 = open("prueba2.txt", O_RDONLY);

	if (fd < 0 || fd2 < 0)
	{
		perror("Error opening file");
		return (1);
	}

	line = get_next_line(fd);
	line2 = get_next_line(fd2);

	while (line || line2)
	{
		if (line)
		{
			print_line(line);
			free(line);
			line = get_next_line(fd);
		}

		if (line2)
		{
			print_line(line2);
			free(line2);
			line2 = get_next_line(fd2);
		}
	}
	printf("%s", line);
	print_line(line);
	printf("%s", line2);
	print_line(line2);

	if (line)
	{
		print_line(line);
		free(line);
	}
	if (line2)
	{
		print_line(line2);
		free(line2);
	}

	close(fd);
	close(fd2);

	return (0);
}
 */