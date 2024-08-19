/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:10:02 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/19 18:23:22 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_scene	*new_scene(t_camera *camera, t_objects *object, int width, int hight)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		exit(77777);///
	scene->camera = *camera;
	scene->objects = *object;
	scene->width = width;//irakan razmernery patuhani(okna)
	scene->hight = hight;
	return (scene);
}

