/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:03:40 by aeminian          #+#    #+#             */
/*   Updated: 2024/12/06 22:58:09 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/minirt.h"

static void	*foo(char *copy_arr, char **arr)
{
	free (copy_arr);
	free (*arr);
	copy_arr = NULL;
	*arr = NULL;
	return (NULL);
}

char	*func(char **arr, int i, int j)
{
	char	*copy_arr;
	char	*temp;

	while ((*arr)[i] != '\n' && (*arr)[i] != '\0')
		i++;
	copy_arr = malloc(sizeof(char) * (i + 2));
	if (!copy_arr)
		return (NULL);
	while ((*arr)[j] != '\n' && (*arr)[j] != '\0')
	{
		copy_arr[j] = (*arr)[j];
		j++;
	}
	if ((*arr)[j] == '\n')
	{
		copy_arr[j] = (*arr)[j];
		j++;
	}
	copy_arr[j] = '\0';
	temp = ft_strdup((*arr) + j);
	free (*arr);
	if (!temp)
		return (foo(copy_arr, arr));
	*arr = temp;
	return (copy_arr);
}

char	*fre_e(char *buffer, char **arr)
{
	free(buffer);
	free(*arr);
	*arr = NULL;
	buffer = NULL;
	return (NULL);
}

char	*check(int fd, char **arr, char *buffer)
{
	int				len;
	char			*tmp;
	int				i;
	int				j;

	len = 1;
	i = 0;
	j = 0;
	while (!ft_strchr_gnl(*arr, '\n') && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if ((len == 0 && (*arr)[0] == '\0') || len < 0)
			return (fre_e(buffer, arr));
		buffer[len] = '\0';
		tmp = ft_strjoin(*arr, buffer);
		free (*arr);
		if (!tmp)
		{
			free (buffer);
			return (NULL);
		}
		*arr = tmp;
	}
	free (buffer);
	return (func(arr, i, j));
}

char	*get_next_line(int fd)
{
	static char	*arr = NULL;
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (arr == NULL)
		arr = ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	return (check(fd, &arr, buffer));
}
