/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:46:50 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/24 21:51:50 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	sphere_intersect(t_vector cam_center, t_vector ray, t_sphere *sphere)
{
	//<D,D>x^2 + (2<OC,D>)x + <OC,OC> - r^2 = 0
	//O is camera center
	//C is spher center
	//D is a ray direction
 	t_vector	cam_sphere_vec;//cam_to_sphere(OC)
	t_math		math;

	math.a = vec_dot_product(ray, ray);/////ray=ray_direction (D)
	cam_sphere_vec = vec_subtract(sphere->center, cam_center);
	math.b = -2.0 * vec_dot_product(ray, cam_sphere_vec);
	math.c = vec_dot_product(cam_sphere_vec, cam_sphere_vec) - sphere->radius * sphere->radius;
	math.disc = math.b * math.b - 4 * math.c * math.a;
	if (math.disc < 0)
		return (-1.0);
	// else
	// 	return ((-(math.b) - sqrt(math.disc)) / (2.0 * math.a));
	math.x1 = ((-math.b) - sqrt(math.disc)) / (2 * math.a);
	// + sqrt-oby chem hashve vortev mez motik tochkena petq,vata?
	if (math.x1 > 0)
		return (math.x1);
	return (0);
}