/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:46:38 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/05 22:36:05 by vbarsegh         ###   ########.fr       */
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
	//  printf("num=%d\n",num);
	return (sign * num);
}
int if_line_contain_only_digit_and_char(char *line, char c)
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

int if_line_contain_only_digit_and_str(char *line, char *set)
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

int	check_is_white_space(char c)
{
	if ((c >= 9 && c <= 12) || c == 32)
		return (1);
	return (-1);
}

int	matrix_row(char **matrix)
{
	int		row;

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