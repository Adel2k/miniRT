/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:30:00 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/04 16:46:32 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	err(char *str)
{
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	return (1);
}

int	malloc_check(char *s)
{
	if (!s)
		return(err("Malloc error!"));
	return (0);
}

int	check1(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
