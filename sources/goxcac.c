/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goxcac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:26:29 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/19 21:28:01 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	compute_light(float dot, t_scene *scene, t_vector *ray)
{
	// t_vector	*d;
	t_vector	*prod;
	t_vector	*p;
	t_vector	*norm;
	t_vector	*light;
	float	n_dot_l;
	float	i;
	printf("xi\n");
	// d = vec_subtract(cam->pos, sph->coord);
	prod = num_product_vect(ray, dot);
	p = sum_vect(&scene->camera.center, prod);
	norm = vec_subtract(p, &scene->objects.sphere->center);
	vec_normalize(norm);
	light = vec_subtract(&scene->light.coords, p);
	i = scene->ambient.ratio_lighting;
	n_dot_l = vec_dot_product(norm, light);
	if (n_dot_l > 0)
		i += scene->light.brightness * n_dot_l / (vec_length(norm) * vec_length(light));

	return(i);
}
