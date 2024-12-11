/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:08:21 by aeminian          #+#    #+#             */
/*   Updated: 2024/12/10 21:50:24 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	found_what_scene_is_it(char **matrix, t_scene *scene)
{
	if (!ft_strcmp(matrix[0], "A"))
	{
		scene->ambient = parse_ambient(matrix, scene);
		scene->count.count_ambient++;
	}
	else if (!ft_strcmp(matrix[0], "C"))
	{
		scene->camera = parse_camera(matrix, scene);
		scene->count.count_camera++;
	}
	else if (!ft_strcmp(matrix[0], "L"))
		ft_lstadd_back_light(&scene->light, lst_create_light(scene, matrix));
	else if (!ft_strcmp(matrix[0], "sp"))
		ft_lstadd_back_figure(&scene->figure,
			lst_create_figure(scene, matrix, SPHERE));
	else if (!ft_strcmp(matrix[0], "pl"))
	{
		ft_lstadd_back_figure(&scene->figure,
			lst_create_figure(scene, matrix, PLANE));
	}
	else if (!ft_strcmp(matrix[0], "cy"))
		ft_lstadd_back_figure(&scene->figure,
			lst_create_figure(scene, matrix, CYLINDER));
	else
		exit_and_free_matrix(matrix, "Error: wrong shape", scene);
}

void	*parse_camera(char **matrix, t_scene *scene)
{
	int			i;
	t_camera	*camera;

	if (scene->camera)
		free(scene->camera);
	camera = malloc(sizeof(t_camera));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix,
			"Error: wrong qanaki arguments for camera", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix, "Error: bad arguments", scene);
	}
	init_coords(&camera->center, matrix, scene, 1);
	init_orient(&camera->direction, matrix, scene, 2);
	if (if_only_digit(matrix[3]) == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for camera", scene);
	camera->fov = ft_atof(matrix[3]);
	if (!(camera->fov >= 0 && camera->fov <= 180))
		exit_and_free_matrix(matrix, "Error: bad value fov", scene);
	return (camera);
}

void	*parse_ambient(char **matrix, t_scene *scene)
{
	int			i;
	t_ambient	*ambient;

	i = 0;
	if (scene->ambient)
		free(scene->ambient);
	ambient = malloc(sizeof (t_ambient));
	if (matrix_row(matrix) != 3)
		exit_and_free_matrix(matrix, "Error: wrong qanaki args for amb", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix, "Error: bad arguments for amb", scene);
	}
	if (if_char_and_digit(matrix[1], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbs amb ratio_light", scene);
	if (fooo(matrix[1]) == -1)
		exit_and_free_matrix(matrix, "Error: bad arg for ratio_light", scene);
	ambient->ratio_lighting = ft_atof(matrix[1]);
	if (!(ambient->ratio_lighting >= 0.0 && ambient->ratio_lighting <= 1.0))
		exit_and_free_matrix(matrix,
			"Error: bad value ambient ratio_lighting", scene);
	init_color(&ambient->light, matrix, scene, 2);
	return (ambient);
}

void	ft_check_minimum_requirements(t_scene *scene, char **map)
{
	if (!scene->camera || scene->count.count_camera != 1)
	{
		free_matrix(map);
		free_scene_members(scene);
		write (1, "Requirement: non existing camera or count is not 1\n", 51);
		//system("leaks miniRT");
		exit(11);
	}
	if (!scene->ambient || scene->count.count_ambient != 1)
	{
		free_matrix(map);
		free_scene_members(scene);
		write (1,
			"Requirement: non existing ambient light or count is not 1\n", 58);
		//system("leaks miniRT");
		exit(11);
	}
	if (!scene->light)
	{
		free_matrix(map);
		free_scene_members(scene);
		write (1, "Requirement: non existing light\n", 32);
		//system("leaks miniRT");
		exit(11);
	}
}

int	if_only_digit(char *line)
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
