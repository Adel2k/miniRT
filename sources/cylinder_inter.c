/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:25:01 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/30 20:11:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


//t^2(D . D - (D . A)^2) + 2t((D . OC) - (D . A)(OC . A)) + (OC . OC - (OC . A)^2 - r^2) = 0
// Центр основания цилиндра C,
// Направление оси цилиндра A (нормализованный вектор),//cyl->orient
//OC eto vec!!!!(OC=O−C — вектор от центра основания цилиндра до начала луча,)
// vec — это векторное представление начального смещения между лучом и цилиндром.
// Он определяет, насколько далеко камера (или начальная точка луча) находится от центра цилиндра, что критически важно для правильного вычисления точек пересечения.


// double	solve_cylinder(t_vector pos, t_vector ray, t_figure **obj, 
// 	t_math *dot)
// {
// 	t_vector	v;
// 	t_vector	u;
// 	t_vector	vec;

// 	// (*obj)->point.dist = 0;
// 	vec = vec_subtract(pos, (*obj)->cylinder->center);
// 	v = vec_subtract(ray, num_product_vect((*obj)->cylinder->orient, 
// 		vec_dot_product((*obj)->cylinder->orient, ray)));
// 	u = vec_subtract(vec, num_product_vect((*obj)->cylinder->orient, 
// 		vec_dot_product((*obj)->cylinder->orient, vec)));
// 	dot->a = vec_dot_product(v, v);
// 	dot->b = 2 * vec_dot_product(v, u);
// 	dot->c = vec_dot_product(u, u) - pow((*obj)->cyl->radius, 2);
// 	dot->discr = pow(dot->b, 2) - 4 * dot->a * dot->c;
// 	if (dot->discr < 0)
// 		return ;
// 	dot->x1 = ((dot->b * (-1)) - sqrt(dot->discr)) / (2 * dot->a);
// 	dot->x2 = ((dot->b * (-1)) + sqrt(dot->discr)) / (2 * dot->a);
// 	fmin(dot.x1, dot.x2);
// }

// double	check_caps(t_vector pos, t_vector ray, t_figure **obj, 
// 	t_math *dot)
// {
// 	double	dist;
// 	t_vector	p;

// 	dist = 0;
	
// 	p = sum_vect(scene->camera->center, num_product_vect(scene->ray, closest_dot));
// 	dot->m1 = vec_dot_product((*obj)->cylinder->orient, 
// 		vec_subtract(p, (*obj)->cylinder->center));
// 	dot->m2 = vec_dot_product((*obj)->cylinder->orient, 
// 		vec_subtract(p, (*obj)->cyl->center1));//center1=@ chshtel incha vor sarqenq mer mot
// 	if (dot->m1 > 0 && dot->m2 < 0)//es ify anhaskanalia,kisat chi?urish depq petq chi stugel?
// 		dist = (*obj)->point.dist;//esi en mer closest_dotna?
// 	return (dist);
// }

// int	solve_caps(t_vector pos, t_vector ray, t_figure **obj)
// {
// 	t_vector	surf;
// 	t_equation	p;

// 	p.x1 = caps_intersection(pos, ray, (*obj)->cylinder->orient, (*obj)->cyl->center);
// 	p.x2 = caps_intersection(pos, ray, (*obj)->cylinder->orient, (*obj)->cyl->center1);
// 	if (p.x1 == INFINITY && p.x2 == INFINITY)
// 		return (0);
// 	(*obj)->point.dist = p.x1;
// 	if (p.x1 > p.x2)
// 	{
// 		(*obj)->cylinder->flag = 1;//ete 1 a uremn taki krujoki heta hatumy,ete 0 uremn vervini heta hatumy
// 		(*obj)->point.dist = p.x2;
// 	}
// 	(*obj)->point.hit_pos = vector_sum(pos, num_product_vect(ray, 
// 		(*obj)->point.dist));
// 	if ((*obj)->cylinder->flag)
// 		surf = vec_subtract((*obj)->point.hit_pos, (*obj)->cyl->center1);
// 	else
// 		surf = vec_subtract((*obj)->point.hit_pos, (*obj)->cyl->center);
		
// 	if (vec_dot_product(surf, surf) < pow((*obj)->cyl->radius, 2))
// 	{
// 		(*obj)->cylinder->cap = 1;//ete 1 a uremn verevi kam nerqevi krujok hatela,ete 0a uremn chi hate
// 		return (1);
// 	}
// 	return (0);
// }

// double	cylinder_intersection(t_vector pos, t_vector ray, t_figure **obj)
// {
// 	double	dist;
// 	t_math	dot;
// 	//pos=> camera center
// 	(*obj)->cylinder->cap = 0;
// 	(*obj)->cylinder->flag = 0;
// 	solve_cylinder(pos, ray, obj, &dot);
// 	dist = check_caps(pos, ray, obj, &dot);
// 	if (solve_caps(pos, ray, obj))
// 	{
// 		if (dist && dist < (*obj)->point.dist && dot.m1 > 0 && dot.m2 < 0)
// 		{
// 			(*obj)->point.dist = dist;
// 			(*obj)->cylinder->cap = 0;
// 		}
// 		return ((*obj)->point.dist);
// 	}
// 	if (dot.m1 > 0 && dot.m2 < 0)
// 	{
// 		(*obj)->point.dist = dist;
// 		(*obj)->point.hit_pos = sum_vect(pos, num_product_vect(ray, 
// 			(*obj)->point.dist));
// 		return ((*obj)->point.dist);
// 	}
// 	return (INFINITY);
// }


// double	caps_intersection(t_vector pos, t_vector ray, t_vector norm, 
// 	t_vector center)
// {
// 	double		dist;
// 	double		dot;
// 	t_vector	vec;

// 	dist = 0;
// 	dot = vec_dot_product(norm, ray);
// 	if (fabs(dot) < __FLT_EPSILON__)
// 		return (INFINITY);
// 	vec = vec_subtract(center, pos);
// 	dist = vec_dot_product(norm, vec) / dot;
// 	if (dist < __FLT_EPSILON__)
// 		return (INFINITY);
// 	return (dist);
// }
