/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:51 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/19 16:16:53 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_newline(const char *str);
char	*ft_replace(char *buffer);
char	*ft_extract(char *buffer);
char	*ft_buffer(int fd, char *buffer);
char	*get_next_line(int fd);

#endif
