/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:46:50 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/10 01:14:00 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	sphere_intersect(t_vector cam_center, t_vector ray, t_figure *obj)
{
	t_vector	cam_sphere_vec;
	t_math		math;

	obj->point.dist = 0;
	math.a = vec_dot_product(ray, ray);
	cam_sphere_vec = vec_subtract(cam_center, obj->sphere->center);
	math.b = 2.0 * vec_dot_product(cam_sphere_vec, ray);
	math.c = vec_dot_product(cam_sphere_vec, cam_sphere_vec) \
		- obj->sphere->radius * obj->sphere->radius;
	math.disc = math.b * math.b - 4 * math.c * math.a;
	if (math.disc < 0)
		return (0);
	math.x1 = ((-math.b) - sqrt(math.disc)) / (2 * math.a);
	math.x2 = ((-math.b) + sqrt(math.disc)) / (2 * math.a);
	find_hit_distance(&obj, math);
	return (obj->point.dist);
}

void	find_hit_distance(t_figure **obj, t_math dot)
{
	if (dot.x1 > __FLT_EPSILON__ || dot.x2 > __FLT_EPSILON__)
	{
		if (dot.x1 > __FLT_EPSILON__ && dot.x2 > __FLT_EPSILON__)
			(*obj)->point.dist = fmin(dot.x1, dot.x2);
		else if (dot.x1 > __FLT_EPSILON__)
			(*obj)->point.dist = dot.x1;
		else
			(*obj)->point.dist = dot.x2;
	}
}
