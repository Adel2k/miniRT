/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:42:20 by adel              #+#    #+#             */
/*   Updated: 2024/12/10 21:59:49 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	exit_and_free_str(char *str_free, char *str_err, t_scene *scene)
{
	err(str_err);
	free (str_free);
	free_scene_members(scene);
	//system("leaks miniRT");
	exit (1);
}

void	exit_and_free_matrix(char **map, char *str_err, t_scene *scene)
{
	free_matrix(map);
	err(str_err);
	free_scene_members(scene);
	system("leaks miniRT");
	exit(1);
}

void	exit_and_free(char **map, char *str_err, t_scene *scene, char **matrix)
{
	free_matrix(matrix);
	exit_and_free_matrix(map, str_err, scene);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
}

void	free_scene_members(t_scene *scene)
{
	if (scene->camera)
		free_cam(scene);
	if (scene->ambient)
		free_ambient(scene);
	if (scene->light)
	{
		free_list_of_light(scene->light);
		scene->light = NULL;
	}
	if (scene->figure)
	{
		free_list_of_figure(scene->figure);
		scene->figure = NULL;
	}
	if (scene->vplane)
	{
		free(scene->vplane);
		scene->vplane = NULL;
	}
	free(scene->mlx);
	free(scene->img);
	free(scene);
	scene = NULL;
}
