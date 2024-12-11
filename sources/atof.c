/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 23:42:27 by aeminian          #+#    #+#             */
/*   Updated: 2024/12/06 22:58:09 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <ctype.h>

void	init_atof(t_atof *v)
{
	v->is_double = 0;
	v->sign = 1;
	v->i = 0;
	v->num = 0;
	v->fraction = 0.1;
}

void	sign(t_atof *v, char *str)
{
	if (str[v->i] == '-' || str[v->i] == '+')
	{
		if (str[v->i] == '-')
			v->sign *= -1;
		v->i++;
	}
}

void	fraction(t_atof *v, char*str)
{
	if (v->is_double)
	{
		v->num += (str[v->i] - '0') * v->fraction;
		v->fraction *= 0.1;
	}
	else
		v->num = v->num * 10.0 + (str[v->i] - '0');
}

double	ft_atof(char *str)
{
	t_atof	v;

	init_atof(&v);
	while (is_white_space(str[v.i]))
		v.i++;
	sign(&v, str);
	while (str[v.i])
	{
		if (str[v.i] >= '0' && str[v.i] <= '9')
			fraction(&v, str);
		else if (str[v.i] == '.')
		{
			if (v.is_double)
				break ;
			v.is_double = 1;
		}
		else
			break ;
		v.i++;
	}
	return (v.sign * v.num);
}
