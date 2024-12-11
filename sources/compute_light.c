/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:25:01 by adel              #+#    #+#             */
/*   Updated: 2024/12/06 22:58:09 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	calculate_sph_norm(t_figure *obj)
{
	obj->point.inter_normal_vec = vec_subtract(obj->point.inter_pos,
			obj->sphere->center);
	vec_normalize(&obj->point.inter_normal_vec);
}

void	calculate_plane_norm(t_figure *obj, t_vector ray)
{
	if (vec_dot_product(obj->plane->orient, ray) < 0)
		obj->point.inter_normal_vec = obj->plane->orient;
	else
		obj->point.inter_normal_vec = num_product_vect(obj->plane->orient, -1);
	vec_normalize(&obj->point.inter_normal_vec);
}

void	calculate_cyl_norm(t_figure *obj)
{
	double		proj_len;
	t_vector	proj;
	t_vector	vec;

	vec = vec_subtract(obj->point.inter_pos, obj->cylinder->center);
	proj_len = vec_dot_product(vec, obj->cylinder->orient);
	proj = sum_vect(obj->cylinder->center,
			num_product_vect(obj->cylinder->orient, proj_len));
	obj->point.inter_normal_vec = vec_subtract(obj->point.inter_pos,
			proj);
	vec_normalize(&obj->point.inter_normal_vec);
}

void	set_inter_normal_vec(t_scene *scene, t_figure *obj)
{
	if (obj->type == SPHERE)
		calculate_sph_norm(obj);
	else if (obj->type == PLANE)
		calculate_plane_norm(obj, scene->ray);
	else if (obj->type == CYLINDER && obj->cylinder->cap == 0)
		calculate_cyl_norm(obj);
	else if (obj->type == CYLINDER && obj->cylinder->cap == 1)
	{
		if (vec_dot_product(obj->cylinder->orient, scene->ray) < 0)
			obj->point.inter_normal_vec = obj->cylinder->orient;
		else
			obj->point.inter_normal_vec
				= num_product_vect(obj->cylinder->orient, -1);
		vec_normalize(&obj->point.inter_normal_vec);
		obj->cylinder->cap = 0;
	}
}

t_color	compute_light(t_scene *scene, t_figure *obj, t_color *specular)
{
	t_color		light_in_vec;
	t_light		*light_tmp;

	light_in_vec = calc_rgb_light(scene->ambient->light,
			scene->ambient->ratio_lighting);
	light_tmp = scene->light;
	while (light_tmp)
	{
		if (compute_shadow(scene, obj, light_tmp))
		{
			light_in_vec = add_rgb_light(diffuse_light(obj,
						light_tmp), light_in_vec);
			*specular = specular_light(scene, light_tmp, obj);
		}
		light_tmp = light_tmp->next;
	}
	return (light_in_vec);
}
