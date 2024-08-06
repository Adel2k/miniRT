/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:53:05 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/06 19:18:12 by vbarsegh         ###   ########.fr       */
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
}

void	found_what_scene_is_it(char **matrix, t_minirt *rt)
{
	if (!ft_strcmp(matrix[0], "A"))
	{
		parse_ambient(matrix, rt);
		printf("ambient=%f\n", rt->ambient.ratio_lighting);
		printf("ambient=%d\n", rt->color.red);
		printf("ambient=%d\n", rt->color.green);
		printf("ambient=%d\n", rt->color.blue);
	}
	else if (!ft_strcmp(matrix[0], "C"))
	{
		parse_camera(matrix, rt);
		printf("camera=%f\n", rt->camera.coords.x);
		printf("camera=%f\n", rt->camera.coords.y);
		printf("camera=%f\n", rt->camera.coords.z);
		printf("camera=%f\n", rt->camera.orient.x);
		printf("camera=%f\n", rt->camera.orient.y);
		printf("camera=%f\n", rt->camera.orient.z);
		printf("camera=%d\n", rt->camera.fov);
	}
	else if (!ft_strcmp(matrix[0], "L"))
	{
		parse_light(matrix, rt);
		printf("light=%f\n", rt->light.coords.x);
		printf("light=%f\n", rt->light.coords.y);
		printf("light=%f\n", rt->light.coords.z);
		printf("light=%f\n", rt->light.brightness);
		printf("light=%d\n", rt->light.color.red);
		printf("light=%d\n", rt->light.color.green);
		printf("light=%d\n", rt->light.color.blue);
	}
	else if (!ft_strcmp(matrix[0], "sp"))
	{
		parse_sphere(matrix, rt);
		printf("sphere=%f\n", rt->objects.sphere.coords.x);
		printf("sphere=%f\n", rt->objects.sphere.coords.x);
		printf("sphere=%f\n", rt->objects.sphere.coords.x);
		printf("sphere=%f\n", rt->objects.sphere.diameter);
		printf("sphere=%d\n", rt->objects.sphere.color.red);
		printf("sphere=%d\n", rt->objects.sphere.color.green);
		printf("sphere=%d\n", rt->objects.sphere.color.blue);	
	}
	if (!ft_strcmp(matrix[0], "pl"))
	{
		parse_plane(matrix, rt);
	}
	if (!ft_strcmp(matrix[0], "cy"))
	{
		parse_cylinder(matrix, rt);
	}
}


void	parse_cylinder(char **matrix, t_minirt *rt)
{
	if (matrix_row(matrix) != 6)
		exit_and_free_matrix(matrix, "Error: bad arguments for cylinder", rt);
	init_coords(&rt->objects.cylinder.coords, matrix, rt, 1);

	init_orient(&rt->objects.cylinder.orient, matrix, rt, 2);

	if (if_line_contain_only_digit_and_char(matrix[3], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for cylinder", rt);
	rt->objects.cylinder.diameter = ft_atof(matrix[3]);

	if (if_line_contain_only_digit_and_char(matrix[4], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for cylinder", rt);
	rt->objects.cylinder.height = ft_atof(matrix[4]);

	init_color(&rt->objects.cylinder.color, matrix, rt, 5);
}


void	parse_plane(char **matrix, t_minirt *rt)
{
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for plane", rt);
	init_coords(&rt->objects.plane.coords, matrix, rt, 1);

	init_orient(&rt->objects.plane.orient, matrix, rt, 2);
	
	init_color(&rt->objects.plane.color, matrix, rt, 3);
}

void	parse_sphere(char **matrix, t_minirt *rt)
{
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for sphere", rt);
	init_coords(&rt->objects.sphere.coords, matrix, rt, 1);

	if (if_line_contain_only_digit_and_char(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for sphere", rt);
	rt->objects.sphere.diameter = ft_atof(matrix[2]);

	init_color(&rt->objects.sphere.color, matrix, rt, 3);
}

void	parse_light(char **matrix, t_minirt *rt)
{
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for light coordinates", rt);
	init_coords(&rt->light.coords, matrix, rt, 1);

	if (if_line_contain_only_digit_and_char(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for light brightness", rt);
	if (ft_atof(matrix[2]) >= 0.0 && ft_atof(matrix[2]) <= 1.0)
		rt->light.brightness = ft_atof(matrix[2]);

	init_color(&rt->light.color, matrix, rt, 3);
}


void	parse_camera(char **matrix, t_minirt *rt)
{
	char	**split_2_line = NULL;

	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for camera", rt);
//
	init_coords(&rt->camera.coords ,matrix, rt, 1);
	// if (if_line_contain_only_digit_and_str(matrix[1], ".,") == -1)
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
	// if (if_line_contain_only_digit_and_str(matrix[2], ".,") == -1)
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
	printf(":=%d\n",rt->camera.fov);
//
}


void	parse_ambient(char **matrix, t_minirt *rt)
{
	// char	**split_2_line=NULL;

	if (matrix_row(matrix) != 3)
		exit_and_free_matrix(matrix, "Error: bad arguments for ambient", rt);
	if (if_line_contain_only_digit_and_char(matrix[1], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for ambient", rt);
	if (ft_atof(matrix[1]) >= 0.0 && ft_atof(matrix[1]) <= 1.0)
		rt->ambient.ratio_lighting = ft_atof(matrix[1]);

	init_color(&rt->color, matrix, rt, 2);	
	// if (if_line_contain_only_digit_and_char(matrix[2], ',') == -1)
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
