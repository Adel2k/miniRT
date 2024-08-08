/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:08:21 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/08 18:10:45 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	found_what_scene_is_it(char **matrix, t_minirt *rt)
{
	if (!ft_strcmp(matrix[0], "A"))
	{
		parse_ambient(matrix, rt);
		// printf("ambient=%f\n", rt->ambient.ratio_lighting);
		// printf("ambient=%d\n", rt->color.red);
		// printf("ambient=%d\n", rt->color.green);
		// printf("ambient=%d\n", rt->color.blue);
	}
	else if (!ft_strcmp(matrix[0], "C"))
	{
		parse_camera(matrix, rt);
		// printf("camera=%f\n", rt->camera.coords.x);
		// printf("camera=%f\n", rt->camera.coords.y);
		// printf("camera=%f\n", rt->camera.coords.z);
		// printf("camera=%f\n", rt->camera.orient.x);
		// printf("camera=%f\n", rt->camera.orient.y);
		// printf("camera=%f\n", rt->camera.orient.z);
		// printf("camera=%d\n", rt->camera.fov);
	}
	else if (!ft_strcmp(matrix[0], "L"))
	{
		parse_light(matrix, rt);
		// printf("light=%f\n", rt->light->coords.x);
		// printf("light=%f\n", rt->light->coords.y);
		// printf("light=%f\n", rt->light->coords.z);
		// printf("light=%f\n", rt->light->brightness);
		// printf("light=%d\n", rt->light->color.red);
		// printf("light=%d\n", rt->light->color.green);
		// printf("light=%d\n", rt->light->color.blue);
	}
	else if (!ft_strcmp(matrix[0], "sp"))
	{
		parse_sphere(matrix, rt);
		// printf("sphere=%f\n", rt->objects.sphere->coords.x);
		// printf("sphere=%f\n", rt->objects.sphere->coords.y);
		// printf("sphere=%f\n", rt->objects.sphere->coords.z);
		// printf("sphere=%f\n", rt->objects.sphere->diameter);
		// printf("sphere=%d\n", rt->objects.sphere->color.red);
		// printf("sphere=%d\n", rt->objects.sphere->color.green);
		// printf("sphere=%d\n", rt->objects.sphere->color.blue);	
	}
	else if (!ft_strcmp(matrix[0], "pl"))
	{
		parse_plane(matrix, rt);
	}
	else if (!ft_strcmp(matrix[0], "cy"))
	{
		
		parse_cylinder(matrix, rt);
	}
	else
		exit_and_free_matrix(matrix, "Error: wrong shape", rt);
}

int	count_shape(char **matrix, char *shape)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (matrix[i])
	{
		if (!ft_strcmp(matrix[i], shape))
		{
			count++;
		}
		i++;
	}
	return (count);
}


void	parse_camera(char **matrix, t_minirt *rt)
{
	char	**split_2_line = NULL;
	int		i;

	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for camera", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", rt);
	}
	
	
//
	init_coords(&rt->camera.coords ,matrix, rt, 1);
	// if (if_str_and_digit(matrix[1], ".,") == -1)
	// 	exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	// split_2_line = split_char(matrix[1], ',');
	// if (!split_2_line)
	// 	exit_and_free_matrix(matrix, "Error: malloc" ,rt);
	// if (matrix_row(split_2_line) != 3)
	// 	exit_and_free(matrix, "Error: bad arguments for camera", rt, split_2_line);
	// rt->camera.coords.x = ft_atof(split_2_line[0]);
	// rt->camera.coords.y = ft_atof(split_2_line[1]);
	// rt->camera.coords.z = ft_atof(split_2_line[2]);
//
	// free_matrix(split_2_line);
//
	init_orient(&rt->camera.orient, matrix, rt, 2);
	// if (if_str_and_digit(matrix[2], ".,") == -1)
	// 	exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	// split_2_line = split_char(matrix[2], ',');
	// if (!split_2_line)
	// 	exit_and_free_matrix(matrix, "Error: malloc" ,rt);
	// if (matrix_row(split_2_line) != 3)
	// 	exit_and_free(matrix, "Error: bad arguments for camera", rt, split_2_line);
	// rt->camera.orient.x = ft_atof(split_2_line[0]);
	// rt->camera.orient.y = ft_atof(split_2_line[1]);
	// rt->camera.orient.z = ft_atof(split_2_line[2]);
	// printf("aa%d\n",matrix_row(matrix));
	

	// if (!(rt->camera.orient.x >= -1.0 && rt->camera.orient.x <= 1.0)
	// 	|| !(rt->camera.orient.y >= -1.0 && rt->camera.orient.y <= 1.0)
	// 	|| !(rt->camera.orient.z >= -1.0 &&rt->camera.orient.z <= 1.0))
	// 	exit_and_free(matrix, "Error: bad value", rt, split_2_line);	
//
	// free_matrix(split_2_line);//erevi
//	
	if (if_only_digit(matrix[3]) == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	rt->camera.fov = ft_atoi(matrix[3]);
	if (!(rt->camera.fov >= 0 && rt->camera.fov <= 180))
		exit_and_free(matrix, "Error: bad value", rt, split_2_line);

//
}

void	parse_ambient(char **matrix, t_minirt *rt)
{
	// char	**split_2_line=NULL;
	if (matrix_row(matrix) != 3)
		exit_and_free_matrix(matrix, "Error: bad arguments for ambient3", rt);
	if (if_char_and_digit(matrix[1], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for ambient4", rt);
	if (ft_atof(matrix[1]) >= 0.0 && ft_atof(matrix[1]) <= 1.0)
		rt->ambient.ratio_lighting = ft_atof(matrix[1]);

	init_color(&rt->color, matrix, rt, 2);	
	// if (if_char_and_digit(matrix[2], ',') == -1)
	// 	exit_and_free_matrix(matrix,"Error: bad arguments for ambient", rt);
	// split_2_line = split_char(matrix[2], ',');
	// if (!split_2_line)
	// 	exit_and_free_matrix(matrix, "Error: malloc" ,rt);
	// if (matrix_row(split_2_line) != 3)
	// 	exit_and_free(matrix, "Error: bad arguments for ambient", rt, split_2_line);
	// rt->color.red = ft_atoi(split_2_line[0]);
	// rt->color.green = ft_atoi(split_2_line[1]);
	// rt->color.blue = ft_atoi(split_2_line[2]);
	// if (!(rt->color.red >= 0 && rt->color.red <= 255)
	// 	|| !(rt->color.green >= 0 && rt->color.green <= 255)
	// 	|| !(rt->color.blue >= 0 && rt->color.blue <= 255))
	// 	exit_and_free(matrix, "Error: bad value", rt, split_2_line);
	// free_matrix(split_2_line);//erevi
}

