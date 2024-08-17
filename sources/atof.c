/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:42:27 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/17 14:44:37 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <ctype.h>

double to_num(char c, int is_float, double num, double *fraction)
{
	if (is_float)
	{
		num += (c - '0') * (*fraction);
		*fraction *= 0.1;
	}
	else
		num = num * 10.0 + (c - '0');
	return num;
}

int choose_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return sign;
}

double ft_atof(char *str)
{
	t_atof	n;
	int		i;
	
	n.num = 0.0;
	n.is_float = 0;
	n.fraction = 0.1;
	i = 0;
	while (isspace(str[i]))
		i++;
	n.sign = choose_sign(str, &i);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n.num = to_num(str[i], n.is_float, n.num, &n.fraction);
		else if (str[i++] == '.')
		{
			if (n.is_float)
				break;
			n.is_float = 1;
		}
		else
			break;
		i++;
	}
	return (n.sign * n.num);
}
