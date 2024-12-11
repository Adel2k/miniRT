/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:59:36 by aeminian          #+#    #+#             */
/*   Updated: 2024/12/06 22:58:09 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

void		ft_strncpy(char *dest, const char *src, unsigned int n);
char		*get_next_line(int fd);
char		*ft_strchr(const char *str, int argument);
char		*func(char **arr, int i, int j);
char		*fre_e(char *buffer, char **arr);
char		*check(int fd, char **arr, char *buffer);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(char *src);

#endif