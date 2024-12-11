/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:07:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/12/10 19:15:16 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main_a(int ac, char **av)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (1);
	init_scene(scene);
	if (validation(ac, av, scene) == 0)
	{
		init_mlx(scene);
		free_scene_members(scene);
		//system("leaks miniRT");
		return (0);
	}
	free_scene_members(scene);
	//system("leaks miniRT");
	return (1);
}

int	main(int ac, char **av)
{
	main_a(ac, av);
	//system("leaks miniRT");
}
