/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:25:01 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/26 20:54:11 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	cylinder_intersect(t_vector pos, t_vector ray, t_cylinder *cyl)
{
	t_math	math;
	float	proj[2];
	t_vector	p1;
	t_vector	p2;
	t_vector	x;

	x = vec_subtract(pos, cyl->coords);
	math.a = vec_dot_product(ray, ray) - powf(vec_dot_product(ray, cyl->orient), 2);
	math.b = 2 * (vec_dot_product(ray, x) - (vec_dot_product(ray, cyl->orient) * vec_dot_product(x, cyl->orient)));
	math.c = vec_dot_product(x, x) - powf(vec_dot_product(x, cyl->orient), 2) - powf(cyl->radius, 2);
	math.disc = math.b * math.b - (4 * math.a * math.c);
	if (math.disc > 0)
	{
		math.x1 = (-math.b - sqrt(math.disc)) / (2 * math.a);
		math.x2 = (-math.b + sqrt(math.disc)) / (2 * math.a);
		return (math.x1);
	}
	else
		return (0.0);
	p1 = sum_vect(pos, num_product_vect(ray, math.x1));
	p2 = sum_vect(pos, num_product_vect(ray, math.x2));
	proj[0] = vec_dot_product(vec_subtract(p1, cyl->coords), cyl->orient);
	if (proj[0] > 0 || proj[0] > vec_dot_product(cyl->orient, cyl->orient))
		return (math.x1);
	proj[1] = vec_dot_product(vec_subtract(p2, cyl->coords), cyl->orient);
	if (proj[1] > 0 || proj[1] > vec_dot_product(cyl->orient, cyl->orient))
		return (math.x2);
	return (0.0);

}
