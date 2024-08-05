/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:46:38 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/05 18:44:00 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	ft_atof(const char *str)
{
	int		i;
	double	num;
	int		sign;
	double 	fraction;
	int		is_float = 0;

	sign = 1;
	i = 0;
	num = 0;
	fraction = 0.1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (is_float)
			{
				num += (str[i] - '0') * fraction;
				fraction *= 0.1;
			}
			else
				 num = num * 10.0 + (str[i] - '0');
		}
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

// int main ()
// {
// 	printf("%f\n", ft_atof("5.j8"));
// }