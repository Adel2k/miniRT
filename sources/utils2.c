/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:46:38 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/08 18:02:06 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (sign * num);
}

int if_char_and_digit(char *line, char c)
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

int	if_str_and_digit(char *line, char *set)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= 48 && line[i] <= 57) || have_this_char_in_set(line[i], set) == 1
			|| line[i] == '-' || line[i] == '+')
			i++;
		else
			return (-1);
	}
	return (1);
}


int	have_this_char_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (-1);
}

int	matrix_row(char **matrix)
{
	int	row;

	row = 0;
	while (matrix[row])
		row++;
	return (row);
}

int if_only_digit(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] >= 48 && line[i] <= 57)
			i++;
		else
			return (-1);
	}
	return (1);
}
