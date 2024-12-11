/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:25:01 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/10 01:01:06 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	solve_cylinder(t_vector pos, t_vector ray, \
	t_figure *obj, t_math *dot)
{
	t_vector	v;
	t_vector	u;
	t_vector	vec;

	obj->point.dist = 0;
	vec = vec_subtract(pos, obj->cylinder->center);
	v = vec_subtract(ray, num_product_vect(obj->cylinder->orient,
				vec_dot_product(obj->cylinder->orient, ray)));
	u = vec_subtract(vec, num_product_vect(obj->cylinder->orient,
				vec_dot_product(obj->cylinder->orient, vec)));
	dot->a = vec_dot_product(v, v);
	dot->b = 2 * vec_dot_product(v, u);
	dot->c = vec_dot_product(u, u) - pow(obj->cylinder->radius, 2);
	dot->disc = pow(dot->b, 2) - 4 * dot->a * dot->c;
	if (dot->disc < 0)
		return ;
	dot->x1 = ((dot->b * (-1)) - sqrt(dot->disc)) / (2 * dot->a);
	dot->x2 = ((dot->b * (-1)) + sqrt(dot->disc)) / (2 * dot->a);
	find_hit_distance(&obj, *dot);
}

double	check_caps(t_vector pos, t_vector ray, t_figure *obj, t_math *dot)
{
	double	dist;

	dist = 0;
	obj->point.inter_pos = sum_vect(pos, num_product_vect(ray,
				obj->point.dist));
	dot->m1 = vec_dot_product(obj->cylinder->orient,
			vec_subtract(obj->point.inter_pos, obj->cylinder->center));
	dot->m2 = vec_dot_product(obj->cylinder->orient,
			vec_subtract(obj->point.inter_pos, obj->cylinder->center1));
	dist = obj->point.dist;
	return (dist);
}

int	solve_caps(t_vector pos, t_vector ray, t_figure *obj)
{
	t_vector	surf;
	t_math		p;

	p.x1 = caps_inter(pos, ray, obj->cylinder->orient, obj->cylinder->center);
	p.x2 = caps_inter(pos, ray, obj->cylinder->orient, obj->cylinder->center1);
	if (p.x1 == INFINITY && p.x2 == INFINITY)
		return (0);
	obj->point.dist = p.x1;
	if (p.x1 > p.x2)
	{
		obj->cylinder->flag = 1;
		obj->point.dist = p.x2;
	}
	obj->point.inter_pos = sum_vect(pos, num_product_vect(ray,
				obj->point.dist));
	if (obj->cylinder->flag)
		surf = vec_subtract(obj->point.inter_pos, obj->cylinder->center1);
	else
		surf = vec_subtract(obj->point.inter_pos, obj->cylinder->center);
	if (vec_dot_product(surf, surf) < pow(obj->cylinder->radius, 2))
	{
		obj->cylinder->cap = 1;
		return (1);
	}
	return (0);
}

double	cylinder_intersection(t_vector pos, t_vector ray, t_figure *obj)
{
	double	dist;
	t_math	dot;

	obj->cylinder->cap = 0;
	obj->cylinder->flag = 0;
	solve_cylinder(pos, ray, obj, &dot);
	dist = check_caps(pos, ray, obj, &dot);
	if (solve_caps(pos, ray, obj))
	{
		if (dist && dist < obj->point.dist && dot.m1 > 0 && dot.m2 < 0)
		{
			obj->point.dist = dist;
			obj->cylinder->cap = 0;
		}
		return (obj->point.dist);
	}
	if (dot.m1 > 0 && dot.m2 < 0)
	{
		obj->point.dist = dist;
		obj->point.inter_pos = sum_vect(pos, num_product_vect(ray,
					obj->point.dist));
		return (obj->point.dist);
	}
	return (INFINITY);
}

double	caps_inter(t_vector pos, t_vector ray, t_vector norm, t_vector center)
{
	double		dist;
	double		dot;
	t_vector	vec;

	dist = 0;
	dot = vec_dot_product(norm, ray);
	if (fabs(dot) < __FLT_EPSILON__)
		return (INFINITY);
	vec = vec_subtract(center, pos);
	dist = vec_dot_product(norm, vec) / dot;
	if (dist < __FLT_EPSILON__)
		return (INFINITY);
	return (dist);
}
