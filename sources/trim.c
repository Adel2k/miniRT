/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:38:53 by aeminian          #+#    #+#             */
/*   Updated: 2024/12/10 00:57:12 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	symbol_check(char c, char const *set)
{
	if (!set)
		return (0);
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*strtrim_end(char *str)
{
	int		i;
	int		start;
	char	*res;

	i = 0;
	start = 0;
	i = ft_strlen(str);
	while (i >= 0 && (str[i - 1] == 32
			|| (str[i - 1] >= 9 && str[i - 1] <= 13)))
		i--;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	while (start < i)
	{
		res[start] = str[start];
		start++;
	}
	res[start] = '\0';
	return (res);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*arr;
	int		start;
	int		j;
	int		end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	j = 0;
	while (s1[start] != '\0' && symbol_check(s1[start], set) == 1)
		start++;
	while (end >= start && symbol_check(s1[end - 1], set) == 1)
		end--;
	arr = malloc(sizeof(char) * (end - start + 1));
	if (!arr)
		return (NULL);
	while (start < end)
		arr[j++] = s1[start++];
	arr[j] = '\0';
	return (arr);
}
