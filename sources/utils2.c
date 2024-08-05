/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:46:38 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/05 20:14:15 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	to_num(char c)
{
	int	is_float;
	double	num;

	is_float = 0;
	num = 0;
	if (c >= '0' && c <= '9')
	{
		if (is_float)
		{
			num += (c - '0') * fraction;
			fraction *= 0.1;
		}
		else
				num = num * 10.0 + (c - '0');
	}
	else if(c == '.')
	{
		if (is_float)
			break ;
		is_float = 1;
	}
	else
		break ;
	return (num)
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	fraction;
	int		num;

	sign = 1;
	i = 0;
	fraction = 0.1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		num = to_num(str[i]);
		i++;
	}
	return (sign * num);
}
