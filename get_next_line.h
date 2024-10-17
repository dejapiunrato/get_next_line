/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piesito <piesito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:52:33 by psevilla          #+#    #+#             */
/*   Updated: 2024/10/17 22:45:50 by piesito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h> //para open esto hay que quitarlo para entregar
# include <stdlib.h>

# define BUFFER_SIZE 1000

int		ft_strlen(char *s);
char	*ft_strenter(char *buf);
char	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char *buf, char *temp);
char	*ft_strdup(const char *buf);
char	*ft_free(int chars, char *buf, char *temp);
char	*ft_new_line(int fd, char *buf);
char	*ft_line(char **buf);
char	*get_next_line(int fd);

#endif
