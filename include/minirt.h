/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:22:05 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/03 19:19:47 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <../include/mlx.h>
# include "../include/get_next_line.h"

size_t	ft_strlen(const char *str);
int		validation(int ac, char **av);
int		malloc_check(char *s);
int		err(char *str);
char	*ft_strdup(char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(const char *str, int c);
#endif