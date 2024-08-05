/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:53:05 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/05 22:42:32 by vbarsegh         ###   ########.fr       */
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
	else if (!ft_strcmp(matrix[0], "C"))
	{
		parse_camera(matrix, rt);
		printf(":=%f\n", rt->camera.coordinates.x);
		printf(":=%f\n", rt->camera.coordinates.y);
		printf(":=%f\n", rt->camera.coordinates.z);
		printf(":=%f\n", rt->camera.orient.x);
		printf(":=%f\n", rt->camera.orient.y);
		printf(":=%f\n", rt->camera.orient.z);
		printf(":=%d\n", rt->camera.fov);
	}
	if (!ft_strcmp(matrix[0], "L"))
	return ;
	if (!ft_strcmp(matrix[0], "sp"))
	return ;
	if (!ft_strcmp(matrix[0], "cy"))
		return ;
	if (!ft_strcmp(matrix[0], "pl"))
		return ;
}


void	parse_camera(char **matrix, t_minirt *rt)
{
	char	**split_2_line;

	
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for camera", rt);
	
//
	if (if_line_contain_only_digit_and_str(matrix[1], ".,") == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	split_2_line = split_char(matrix[1], ',');
	if (!split_2_line)
		exit_and_free_matrix(matrix, "Error: malloc" ,rt);
	if (matrix_row(split_2_line) != 3)
		exit_and_free(matrix, "Error: bad arguments for camera", rt, split_2_line);
	rt->camera.coordinates.x = ft_atof(split_2_line[0]);
	rt->camera.coordinates.y = ft_atof(split_2_line[1]);
	rt->camera.coordinates.z = ft_atof(split_2_line[2]);
//
	free_matrix(split_2_line);
//
	if (if_line_contain_only_digit_and_str(matrix[2], ".,") == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	split_2_line = split_char(matrix[2], ',');
	if (!split_2_line)
		exit_and_free_matrix(matrix, "Error: malloc" ,rt);
	if (matrix_row(split_2_line) != 3)
		exit_and_free(matrix, "Error: bad arguments for camera", rt, split_2_line);
	rt->camera.orient.x = ft_atof(split_2_line[0]);
	rt->camera.orient.y = ft_atof(split_2_line[1]);
	rt->camera.orient.z = ft_atof(split_2_line[2]);
	printf("aa%d\n",matrix_row(matrix));
	

	if (!(rt->camera.orient.x >= -1.0 && rt->camera.orient.x <= 1.0)
		|| !(rt->camera.orient.y >= -1.0 && rt->camera.orient.y <= 1.0)
		|| !(rt->camera.orient.z >= -1.0 &&rt->camera.orient.z <= 1.0))
		exit_and_free(matrix, "Error: bad value", rt, split_2_line);	
//
	free_matrix(split_2_line);//erevi
//	
	if (if_only_digit(matrix[3]) == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	rt->camera.fov = ft_atoi(matrix[3]);
	if (!(rt->camera.fov >= 0 && rt->camera.fov <= 180))
		exit_and_free(matrix, "Error: bad value", rt, split_2_line);
	printf(":=%d\n",rt->camera.fov);
//
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
	free_matrix(split_2_line);//erevi
}
