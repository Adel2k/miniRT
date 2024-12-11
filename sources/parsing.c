/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:53:05 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/11 13:21:22 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parsing(char **map, t_scene *scene)
{
	int		i;
	char	**matrix;

	i = 0;
	while (map[i])
	{
		matrix = split(map[i]);
		found_what_scene_is_it(matrix, scene);
		free_matrix(matrix);
		matrix = NULL;
		i++;
	}
	//system("leaks miniRT");
	ft_check_minimum_requirements(scene, map);
}

t_cylinder	*parse_cylinder(char **matrix, t_scene *scene, \
	t_cylinder *cylinder, int i)
{
	if (matrix_row(matrix) != 6)
		exit_and_free_matrix(matrix, "Error:wrong argument cylinder", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix, "Error:wrong args cylinder", scene);
	}
	init_coords(&cylinder->center, matrix, scene, 1);
	init_orient(&cylinder->orient, matrix, scene, 2);
	if (if_char_and_digit(matrix[3], '.') == -1)
		exit_and_free_matrix(matrix, "Error:wrong argument cylinder", scene);
	if (fooo(matrix[2]) == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for cylinder radius",
			scene);
	cylinder->radius = ft_atof(matrix[3]) / 2;
	if (if_char_and_digit(matrix[4], '.') == -1)
		exit_and_free_matrix(matrix, "Error:wrong argument cylinder", scene);
	cylinder->height = ft_atof(matrix[4]);
	init_color(&cylinder->color, matrix, scene, 5);
	cylinder->center1 = sum_vect(cylinder->center, \
		num_product_vect(cylinder->orient, cylinder->height));
	return (cylinder);
}

t_plane	*parse_plane(char **matrix, t_scene *scene)
{
	int		i;
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix,
			"Error: wrong qanaki arguments for plane", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix, "Error: bad arguments pl", scene);
	}
	init_coords(&plane->coords, matrix, scene, 1);
	init_orient(&plane->orient, matrix, scene, 2);
	init_color(&plane->color, matrix, scene, 3);
	return (plane);
}

t_sphere	*parse_sphere(char **matrix, t_scene *scene, int i)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	init_sphere(sphere);
	if (!(matrix_row(matrix) > 3 && matrix_row(matrix) < 7))
		exit_and_free_matrix(matrix,
			"Error: wrong arguments for sphere", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix, "Error: bad arguments sp", scene);
	}
	init_coords(&sphere->center, matrix, scene, 1);
	if (if_char_and_digit(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for sphere", scene);
	if (fooo(matrix[2]) == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for sphere radius",
			scene);
	sphere->radius = ft_atof(matrix[2]) / 2;
	init_color(&sphere->color, matrix, scene, 3);
	if (matrix_row(matrix) == 5 || matrix_row(matrix) == 6 \
		|| matrix_row(matrix) == 7)
		set_texture(matrix, sphere, scene);
	return (sphere);
}

t_light	*parse_light(char **matrix, t_scene *scene)
{
	int		i;
	t_light	*light;

	light = malloc(sizeof(t_light));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix,
			"Error: wrong qanaki arguments for light coordinates", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix, "Error: bad arguments L", scene);
	}
	init_coords(&light->coords, matrix, scene, 1);
	if (if_char_and_digit(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simb for L brns", scene);
	if (fooo(matrix[2]) == -1)
		exit_and_free_matrix(matrix, "Error: bad arg for R", scene);
	light->brightness = ft_atof(matrix[2]);
	if (!(light->brightness >= 0.0 && light->brightness <= 1.0))
		exit_and_free_matrix(matrix,
			"Error: bad value for light brightness", scene);
	init_color(&light->color, matrix, scene, 3);
	return (light);
}
