/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:03:49 by piesito           #+#    #+#             */
/*   Updated: 2024/10/29 20:23:44 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* adiaz-lo */

#include "get_next_line.h"

#include <stdio.h>
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
				write(1, RED, 5);  // Comienza el texto rojo
				write(1, "\\", 1);
				write(1, "n", 1);    // Imprime "n" en rojo
				write(1, RESET, 4); // Resetea el color
				write(1, "\n", 1);   // Imprime un salto de línea real
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
	char	*line;

	fd = open("prueba.txt", 0); // Asegúrate de que el archivo "test.txt" exista
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		print_line(line);
		free(line); // Liberar la memoria asignada para la línea
		line = get_next_line(fd);
	}
	print_line(line);
	printf("%s", line);
	close(fd);
	return (0);
}

