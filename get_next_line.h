/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:52:33 by psevilla          #+#    #+#             */
/*   Updated: 2024/11/21 20:27:19 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
int			ft_strlen(char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(const char *s, unsigned int start, size_t len);

#endif
