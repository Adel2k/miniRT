/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:53:05 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/05 19:56:06 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parsing(char **map, t_minirt *rt)
{
	int	i;
	char	**matrix;
	i = 0;
	while (map[i])
	{
		matrix = split(map[i]);
		found_what_scene_is_it(matrix, rt);
		free_matrix(matrix);//
		i++;
	}
	// free_matrix(map);//
}

void	found_what_scene_is_it(char **matrix, t_minirt *rt)
{
	if (!ft_strcmp(matrix[0], "A"))
	{
		parse_ambient(matrix, rt);
		printf(":%f\n", rt->ambient.ratio_lighting);
		printf(":%d\n", rt->color.red);
		printf(":%d\n", rt->color.green);
		printf(":%d\n", rt->color.blue);
	}
	if (!ft_strcmp(matrix[0], "C"))
		return ;
	if (!ft_strcmp(matrix[0], "L"))
	return ;
	if (!ft_strcmp(matrix[0], "sp"))
	return ;
	if (!ft_strcmp(matrix[0], "cy"))
		return ;
	if (!ft_strcmp(matrix[0], "pl"))
		return ;
}

void	parse_ambient(char **matrix, t_minirt *rt)
{
	char	**split_2_line;

	if (matrix_row(matrix) != 3)
		exit_and_free_matrix(matrix, "Error: bad arguments for ambient", rt);
	if (if_line_contain_only_digit_and_char(matrix[1], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for ambient", rt);
	if (ft_atof(matrix[1]) >= 0.0 && ft_atof(matrix[1]) <= 1.0)
		rt->ambient.ratio_lighting = ft_atof(matrix[1]);	
	if (if_line_contain_only_digit_and_char(matrix[2], ',') == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for ambient", rt);
	split_2_line = split_char(matrix[2], ',');
	if (!split_2_line)
		exit_and_free_matrix(matrix, "Error: malloc" ,rt);
	if (matrix_row(split_2_line) != 3)
		exit_and_free(matrix, "Error: bad arguments for ambient", rt, split_2_line);
	rt->color.red = ft_atoi(split_2_line[0]);
	rt->color.green = ft_atoi(split_2_line[1]);
	rt->color.blue = ft_atoi(split_2_line[2]);
	if (!(rt->color.red >= 0 && rt->color.red <= 255)
		|| !(rt->color.green >= 0 && rt->color.green <= 255)
		|| !(rt->color.blue >= 0 && rt->color.blue <= 255))
		exit_and_free(matrix, "Error: bad value", rt, split_2_line);
}



int if_line_contain_only_digit_and_char(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= 48 && line[i] <= 57) || line[i] == c)
			i++;
		else
			return (-1);
	}
	return (1);
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