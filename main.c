#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> // para open esto hay que quitarlo para entregar
#include <stdlib.h>

#define BUFFER_SIZE 20

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strenter(char *buf)
{
	int i;

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

// Concatena en buf buf+temp y libera temp.
char	*ft_strjoin(char *buf, char *temp)
{
	char	*s;
	int		i;
	char	*temp_cpy;

	temp_cpy = temp;
	s = (char *)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(temp) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (*buf)
			s[i++] = *buf++;
	while (*temp && *temp != '\n')
		s[i++] = *temp++;
	if (*temp == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}
char	*ft_strdup(const char *buf)
{
	size_t	size;
	char	*s;
	char	*aux;

	size = ft_strlen((char *)buf) + 1;
	s = ft_calloc(size, size);
	if (s == NULL)
		return (NULL);
	aux = s;
	while (*buf)
		*s++ = *buf++;
	return (aux);
}

char	*ft_new_line(int fd, char *buf)
{
	int		chars; //Número de bytes leidos
	char	*temp; //String que almacena carácteres leidos de fd

	if (!buf)
		buf = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (1)
	{
		chars = read(fd, temp, BUFFER_SIZE);
		if (chars < 0) //Si falla la lectura se libera la memoria
		{
			free(temp);
			free(buf);
			return (NULL);
		}
		buf = ft_strjoin(buf, temp); //Concatenar buf y temp en buf
		if (ft_strenter(buf) || chars == 0) //Parar de leer si se encuentra salto de línea o fina del archivo
			break ;
	}
	free(temp);
	return (buf);
}
char	*get_next_line(int fd)
{
	static char *buf;
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
	return (NULL);
}

int	main(void)
{
	int fd = open("prueba.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	return (0);
}
