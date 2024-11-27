/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:07:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/11/27 23:26:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int main(int ac, char **av)
{
	t_scene 	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (1);
	init_scene(scene);
	// printf("hasav\n");
	if (validation(ac, av, scene) == 0)
	{
		printf("chjoka\n");
		init_mlx(scene);
		free_scene_members(scene);
		system("leaks miniRT");
		return 0;
	}
	printf("steeeeeeeeeee???\n");
	// err("Error: Incorrect file");
	free_scene_members(scene);
	// system("leaks miniRT");
	return 1;
}

void	free_scene_members(t_scene *scene)
{
	if (scene->camera)
	{
		free(scene->camera);
		printf("hasnumenqqq\n");
		scene->camera = NULL;
	}
	if (scene->ambient)
	{
		printf("hasnumenqqq\n");
		free(scene->ambient);
		scene->ambient = NULL;
	}
	if (scene->light)
	{
		printf("hasnumenqqq\n");
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
		printf("hasnumenqqq\n");

		free(scene->vplane);
		scene->vplane = NULL;
	}
	free(scene->mlx);
	free(scene->img);
	free(scene);
	scene = NULL;
		printf("vyyyyyyyyyyyyyyyy\n");

}

void	init_scene(t_scene *scene)
{
	scene->camera = NULL;
	scene->ambient = NULL;
	scene->light = NULL;
	scene->figure = NULL;
	scene->vplane = NULL;
	scene->i = 0;//
	scene->j = 0;//
	scene->ray = new_vector(0, 0, 0);
	scene->mlx = NULL;
	scene->img = NULL;
	scene->width = WIDTH;
	scene->height = HEIGHT;
	scene->count.count_ambient = 0;
	scene->count.count_camera = 0;
	
}
