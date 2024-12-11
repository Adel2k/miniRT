/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:45:57 by adel              #+#    #+#             */
/*   Updated: 2024/12/10 01:05:25 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	is_rt(char *str)
{
	size_t	len;

	if (!str || !*str)
		return (1);
	len = ft_strlen(str) - 1;
	if (len > 3)
	{
		if (str[len--] != 't')
			return (1);
		if (str[len--] != 'r')
			return (1);
		if (str[len--] != '.')
			return (1);
		return (0);
	}
	return (1);
}

int	comment_line(char *str)
{
	int	i;

	i = 0;
	while ((str[i] && (str[i] >= 9 && str[i] <= 13)) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '#')
		return (1);
	return (-1);
}

int	only_trim_symbols(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '\n' && str[i] != '\v'
				&& str[i] != '\f' && str[i] != '\r'
				&& str[i] != '\t') && ((str[i] < 9 || str[i] > 13)
				&& str[i] != 32))
			return (-1);
		else
			i++;
	}
	return (1);
}

int	only_new_line_or_spaces(char *res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] == '\n' || res[i] == 32)
			i++;
		else
			return (-1);
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	if (c < 0)
		return ((char *)s);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
