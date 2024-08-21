/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:07:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/20 13:57:15 by vbarsegh         ###   ########.fr       */
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
	if (validation(ac, av, scene) == 0)
	{
		init_mlx(scene);
		printf("chjoka\n");
		// system("leaks miniRT");
		return 0;
	}
	err("Error: Incorrect file");
	// free_(rt, vars);
	free(scene);
	// system("leaks miniRT");
	return 1;
}

void	free_(t_scene *scene, t_mlx_vars *mlx)
{
	free(scene->ambient);
	free(scene->camera);
	free(scene->light);
	free(scene->plane);
	free(scene);
	free(mlx);
}

void	init_scene(t_scene *scene)
{
	scene->camera = NULL;
	scene->ambient = NULL;
	scene->light = NULL;
	scene->plane = NULL;
	scene->sphere = NULL;
	scene->cylinder = NULL;
	scene->mlx = NULL;
	scene->img = NULL;
	scene->width = WIDTH;
	scene->height = HEIGHT;
}
