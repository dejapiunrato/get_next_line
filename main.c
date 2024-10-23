/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piesito <piesito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:03:49 by piesito           #+#    #+#             */
/*   Updated: 2024/10/23 19:19:49 by piesito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("prueba.txt", O_RDONLY);
	i = 1;
	if (fd < 0)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (line)
			printf("Linea %d: %s\n", i, line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	return (0);
}
