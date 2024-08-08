/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:53:05 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/08 18:10:39 by aeminian         ###   ########.fr       */
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

void	parse_cylinder(char **matrix, t_minirt *rt)
{
	int	i;

	rt->objects.cylinder = malloc(sizeof(t_cylinder) * (count_shape(matrix, "cy")));
	i = 0;
	if (matrix_row(matrix) != 6)
		exit_and_free_matrix(matrix, "Error: bad arguments for cylinder", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", rt);
	}
	init_coords(&rt->objects.cylinder->coords, matrix, rt, 1);

	init_orient(&rt->objects.cylinder->orient, matrix, rt, 2);

	if (if_char_and_digit(matrix[3], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for cylinder", rt);
	rt->objects.cylinder->diameter = ft_atof(matrix[3]);

	if (if_char_and_digit(matrix[4], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for cylinder", rt);
	rt->objects.cylinder->height = ft_atof(matrix[4]);

	init_color(&rt->objects.cylinder->color, matrix, rt, 5);
}


void	parse_plane(char **matrix, t_minirt *rt)
{
	int	i;

	rt->objects.plane = malloc(sizeof(t_plane) * count_shape(matrix, "pl"));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for plane", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", rt);
	}
	init_coords(&rt->objects.plane->coords, matrix, rt, 1);

	init_orient(&rt->objects.plane->orient, matrix, rt, 2);
	
	init_color(&rt->objects.plane->color, matrix, rt, 3);
}

void	parse_sphere(char **matrix, t_minirt *rt)
{
	int	i;

	rt->objects.sphere = malloc(sizeof(t_sphere) * count_shape(matrix, "sp"));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for sphere", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", rt);
	}
		// if ()
		// 	exit_and_free_matrix(matrix,"Error: bad arguments", rt);
	init_coords(&rt->objects.sphere->coords, matrix, rt, 1);

	if (if_char_and_digit(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for sphere", rt);
	rt->objects.sphere->diameter = ft_atof(matrix[2]);

	init_color(&rt->objects.sphere->color, matrix, rt, 3);
}

void	parse_light(char **matrix, t_minirt *rt)
{
	int	i;

	rt->light = malloc(sizeof(t_light) * count_shape(matrix, "L"));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for light coordinates", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", rt);
	}
	init_coords(&rt->light->coords, matrix, rt, 1);

	if (if_char_and_digit(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for light brightness", rt);
	if (ft_atof(matrix[2]) >= 0.0 && ft_atof(matrix[2]) <= 1.0)
		rt->light->brightness = ft_atof(matrix[2]);

	init_color(&rt->light->color, matrix, rt, 3);
}
