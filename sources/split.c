/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:58:25 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/06 22:58:09 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*my_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	foo_sum_tar(char const *s)
{
	int	sum_tar;

	sum_tar = 0;
	while (is_white_space(*s))
		s++;
	while (*s != '\0')
	{
		if (is_white_space(*s))
			return (sum_tar);
		else
		{
			s++;
			sum_tar++;
		}
	}
	return (sum_tar);
}

int	check_00(char **arr, const char *s, int count)
{
	int	i;
	int	len_word;

	i = 0;
	while (i < count)
	{
		while (is_white_space(*s))
			s++;
		len_word = foo_sum_tar(s);
		arr[i] = malloc(sizeof(char) * (len_word + 1));
		if (!arr[i])
		{
			while (i >= 0)
				free(arr[i--]);
			free(arr);
			return (1);
		}
		my_strncpy(arr[i], s, len_word);
		arr[i][len_word] = '\0';
		s += (len_word + 1);
		i++;
	}
	return (0);
}

int	func_count_word(const char *s)
{
	int	i;
	int	count;
	int	ban;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (is_white_space(s[i]) && s[i] != '\0')
		{
			i++;
			ban = 0;
		}
		while (!is_white_space(s[i]) && s[i] != '\0')
		{
			i++;
			ban = 1;
		}
		if (ban == 1)
			count++;
	}
	return (count);
}

char	**split(char const *s)
{
	int		count_word;
	char	**arr;

	if (s == NULL)
		return (NULL);
	count_word = func_count_word(s);
	arr = malloc(sizeof(char *) * (count_word + 1));
	if (!arr)
		return (NULL);
	arr[count_word] = NULL;
	if (check_00(arr, s, count_word))
		return (NULL);
	return (arr);
}
