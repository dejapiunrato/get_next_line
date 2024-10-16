/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piesito <piesito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:03:49 by piesito           #+#    #+#             */
/*   Updated: 2024/10/17 23:05:43 by piesito          ###   ########.fr       */
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
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			printf("Linea %d: %s\n", i, line);
		i++;
	}
	return (0);
}
