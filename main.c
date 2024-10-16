#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Abre el archivo para lectura (cambia "archivo.txt" al nombre de tu archivo).
    fd = open("prueba.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Lee y muestra cada línea del archivo.
    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line); // Asegúrate de liberar la memoria asignada por ft_strdup
    }

    // Cierra el archivo.
    close(fd);
    return 0;
}
