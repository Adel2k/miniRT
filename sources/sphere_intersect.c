/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:46:50 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/30 19:40:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	sphere_intersect(t_vector cam_center, t_vector ray, t_figure *obj)
{
	//<D,D>x^2 + (2<OC,D>)x + <OC,OC> - r^2 = 0
	//O is camera center
	//C is spher center
	//D is a ray direction
 	t_vector	cam_sphere_vec;//cam_to_sphere(OC)
	t_math		math;

	obj->point.dist = 0;
	math.a = vec_dot_product(ray, ray);/////ray=ray_direction (D)
	cam_sphere_vec = vec_subtract(obj->sphere->center, cam_center);
	math.b = -2.0 * vec_dot_product(ray, cam_sphere_vec);
	math.c = vec_dot_product(cam_sphere_vec, cam_sphere_vec) - obj->sphere->radius * obj->sphere->radius;
	math.disc = math.b * math.b - 4 * math.c * math.a;
	if (math.disc < 0)
		return (-1.0);
	// else
	// 	return ((-(math.b) - sqrt(math.disc)) / (2.0 * math.a));
	math.x1 = ((-math.b) - sqrt(math.disc)) / (2 * math.a);
	// + sqrt-oby chem hashve vortev mez motik tochkena petq,vata?
	if (math.x1 > 0)
		obj->point.dist = math.x1;
	return (obj->point.dist);
}