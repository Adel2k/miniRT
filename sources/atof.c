/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:42:27 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/09 14:45:01 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	to_num(char c, int is_float)
{
	double	num;
	double	fraction;

	num = 0;
	fraction = 0.1;
	if (is_float)
	{
		num += (c - '0') * fraction;
		fraction *= 0.1;
	}
	else
		num = num * 10.0 + (c - '0');
	return (num);
	
}

int	choose_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

double	ft_atof(char *str)
{
	int		i;
	double	num;
	int		sign;
	int		is_float;

	is_float = 0;
	i = 0;
	while (is_white_space(str[i]))
		i++;
	sign = choose_sign(str, &i);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = to_num(str[i], is_float);
		else if(str[i] == '.')
		{
			if (is_float)
				break ;
			is_float = 1;
		}
		else
			break ;
		i++;
	}
	return (sign * num);
}
