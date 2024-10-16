#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> // para open esto hay que quitarlo para entregar
#include <stdlib.h>

#define BUFFER_SIZE 42

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
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (buf + i);
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







char	*ft_new_line(int fd, char *buf)
{
	int		chars; //Número de caracteres leidos
	char	*temp; //String que almacena carácteres leidos de fd

	if (!buf)
		buf = ft_calloc(1, 1);
	chars = 1;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (chars)
	{
		chars = read(fd, temp, BUFFER_SIZE + 1);
		if (chars < 0) //Si falla la lectura se libera la memoria
		{
			free(temp);
			free(buf);
			return (NULL);
		}
		temp[chars] = '\0';
		buf = ft_strjoin(buf, temp); //Concatenar buf y temp en buf
		if (ft_strenter(buf)) //Si se encuentra un salto de línea en buf, se para de leer.
			break ;
	}
	free (temp);
	return (buf);
}

int main(void)
{
    int fd;
    char *s = NULL;

    // Abre el archivo prueba.txt en modo lectura
    fd = open("prueba.txt", O_RDONLY);
    if (fd < 0) // Verifica si se abre correctamente el archivo
    {
        perror("Error opening file");
        return 1;
    }

    // Llama a ft_new_line para leer hasta la primera nueva línea
    s = ft_new_line(fd, s);
    if (s) // Verifica si se leyó correctamente
    {
        printf("Contenido leído: %s\n", s);
        free(s); // Libera la memoria asignada
    }
    else
    {
        printf("No se pudo leer ninguna línea.\n");
    }

    // Cierra el descriptor de archivo
    close(fd);
    return 0;
}
