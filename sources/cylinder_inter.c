/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:25:01 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/26 23:57:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	calcul_dist(t_cylinder *cyl, double t, t_vector ray, t_vector pos)
{
	double	dist;

	dist = vec_dot_product(cyl->orient, vec_subtract(num_product_vect(ray, t), \
			vec_subtract(cyl->center, pos)));
	return (dist);
}

double	vect_proj(t_vector pos, t_vector ray, t_cylinder *cyl, t_math *math)
{
	t_vector	ray_p;
	t_vector	oc_p;

	ray_p = num_product_vect(cyl->orient, vec_dot_product(ray, cyl->orient));
	ray_p = vec_subtract(ray, ray_p);
	oc_p = num_product_vect(cyl->orient, \
			vec_dot_product(vec_subtract(pos, cyl->center), cyl->orient));
	oc_p = vec_subtract(vec_subtract(pos, cyl->center), oc_p);
	math->a = vec_dot_product(ray_p, ray_p);
	math->b = 2 * vec_dot_product(ray_p, oc_p);
	math->c = vec_dot_product(oc_p, oc_p) - powf(cyl->radius, 2);
	math->disc = math->b * math->b - (4 * math->a * math->c);
	if (math->disc > 0)
	{
		math->x1 = (-math->b - sqrt(math->disc)) / (2 * math->a);
		math->x2 = (-math->b + sqrt(math->disc)) / (2 * math->a);
		if (math->x1 < 0.001 && math->x2 < 0.001)
			return (INFINITY);
		return (1);
	}
	return (INFINITY);
}

double	side_inter(t_vector pos, t_vector ray, t_cylinder *cyl)
{
	t_math	math;

	if (vect_proj(pos, ray, cyl, &math) == INFINITY)
		return (INFINITY);
	cyl->dist[0] = calcul_dist(cyl, math.x1, ray, pos);
	cyl->dist[1] = calcul_dist(cyl, math.x2, ray, pos);
	if (!((cyl->dist[0] >= 0 && cyl->dist[0] <= cyl->height && math.x1 > 0.001) \
		|| (cyl->dist[1] >= 0 && cyl->dist[1] <= cyl->height \
			&& math.x2 > 0.001)))
		return (INFINITY);
	cyl->ray_norm = cylray_norm(&math, ray, pos, cyl);
	return (math.x1);
}

double	caps_inter(t_vector pos, t_vector ray, t_cylinder *cyl)
{
	double	inter[2];
	t_vector	v[2];
	t_vector	centerer;

	centerer = sum_vect(cyl->center, num_product_vect(cyl->orient, cyl->height));
	inter[0] = plane_inter(pos, ray, cyl->orient, centerer);
	inter[1] = plane_inter(pos, ray, cyl->orient, cyl->center);
	if (inter[0] < INFINITY || inter[1] < INFINITY)
	{
		v[0] = sum_vect(pos, num_product_vect(ray, inter[0]));
		v[1] = sum_vect(pos, num_product_vect(ray, inter[1]));
		if ((inter[0] < INFINITY && dist_vect(v[0], cyl->center) <= cyl->radius) && \
			(inter[1] < INFINITY && dist_vect(v[1], cyl->center) <= cyl->radius))
		{
			if (inter[0] > inter[1])
				return (inter[1]);
			return (inter[0]);
		}
		if (inter[0] < INFINITY && dist_vect(v[0], cyl->center) <= cyl->radius)
			return (inter[0]);
		if (inter[1] < INFINITY && dist_vect(v[1], cyl->center) <= cyl->radius)
			return (inter[1]);
	}
	return (INFINITY);
}

double	cylinder_intersect(t_vector pos, t_vector ray, t_cylinder *cyl)
{
	double	side_point;
	double	caps_point;

	side_point = side_inter(pos, ray, cyl);
	caps_point = caps_inter(pos, ray, cyl);
	if (side_point != INFINITY || caps_point != INFINITY)
	{
		if (side_point < caps_point)
			return (side_point);
		if (caps_point < INFINITY && caps_point > 0.001)
		{
			cyl->ray_norm = cyl->orient;
			if (cyl->orient.z <= 0)
				cyl->ray_norm = num_product_vect(cyl->orient, -1);
			return (caps_point);
		}
	}
	return (INFINITY);
}

t_vector	cylray_norm(t_math *math, t_vector ray, t_vector pos, t_cylinder *cyl)
{
	double	dist;

	dist = closest_dist(cyl, math);
	t_vector foo;

	foo = vec_subtract(vec_subtract(num_product_vect(ray, math->x1), \
			num_product_vect(cyl->orient, dist)), \
			vec_subtract(cyl->center, pos));
	vec_normalize(&foo);
	return (foo);
}

double	closest_dist(t_cylinder *cyl, t_math *m)
{
	double	dist;

	if (cyl->dist[0] >= 0 && cyl->dist[0] <= cyl->height && m->x1 > 0.001 && \
		cyl->dist[1] >= 0 && cyl->dist[1] <= cyl->height && m->x2 > 0.001)
	{
		if (m->x1 < m->x2)
		{
			dist = cyl->dist[0];
			return (dist);
		}
		dist = cyl->dist[1];
		m->x1 = m->x2;
		return (dist);
	}
	else if (cyl->dist[0] >= 0 && cyl->dist[0] <= cyl->height && m->x1 > 0.001)
	{
		dist = cyl->dist[0];
		return (dist);
	}
	else
	{
		dist = cyl->dist[1];
		m->x1 = m->x2;
		return (dist);
	}
}

double	plane_inter(t_vector pos, t_vector ray, t_vector pl_orient, t_vector pl_coord)
{
	double	t;
	double	norm_dot_dir;

	pl_orient = calculate_plane_norm(, ray);
	norm_dot_dir = vec_dot_product()
	
}
