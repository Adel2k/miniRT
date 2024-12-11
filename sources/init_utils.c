/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:47:46 by adel              #+#    #+#             */
/*   Updated: 2024/12/09 00:55:12 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	overflow_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 11 || ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (-1);
	return (1);
}

int	if_str_and_digit(char *line, char *set)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= 48 && line[i] <= 57)
			|| have_this_char_in_set(line[i], set) == 1
			|| line[i] == '-' || line[i] == '+')
			i++;
		else
			return (-1);
	}
	return (1);
}

int	if_char_and_digit(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= 48 && line[i] <= 57) || line[i] == c
			|| line[i] == '-' || line[i] == '+')
			i++;
		else
			return (-1);
	}
	return (1);
}

int	matrix_row(char **matrix)
{
	int	row;

	row = 0;
	while (matrix[row])
		row++;
	return (row);
}
