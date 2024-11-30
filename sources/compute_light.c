//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goxcac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:26:29 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/31 15:38:40 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


void	calculate_sph_norm(t_figure *obj)
{
	obj->point.inter_normal_vec = vec_subtract(obj->point.inter_pos, obj->sphere->center);
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
	proj = sum_vect(obj->cylinder->center, num_product_vect(obj->cylinder->orient, proj_len));
	obj->point.inter_normal_vec = vec_subtract(obj->point.inter_pos, proj);
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
			obj->point.inter_normal_vec = num_product_vect(obj->cylinder->orient, -1);
		vec_normalize(&obj->point.inter_normal_vec);
		obj->cylinder->cap = 0;
	}
	// printf("Normal length: %f\n", sqrt(vec_dot_product(obj->point.inter_normal_vec, obj->point.inter_normal_vec)));

}


t_color	compute_light(t_scene *scene, t_figure *obj, t_color *specular)
{
	t_color		light_in_vec;
	t_light		*light_tmp;

	light_in_vec = calc_rgb_light(scene->ambient->light, scene->ambient->ratio_lighting);
	// if (obj->point.is_inside)
		// return (col);
	light_tmp = scene->light;
	while (light_tmp)
	{
		if (compute_shadow(scene, obj, light_tmp))
		{
			light_in_vec = add_rgb_light(diffuse_light(obj, light_tmp), light_in_vec);
			*specular = specular_light(scene, light_tmp, obj);
			// printf("specular->x->%d\n", specular->red);
			// printf("specular->y->%d\n", specular->green);
			// printf("specular->z->%d\n", specular->blue);
		}
		light_tmp = light_tmp->next;
	}
	return (light_in_vec);
}



t_color	diffuse_light(t_figure *obj, t_light *light_fig)
{
	double		intens;
	double		n_dot_l;
	t_vector	light;
	// t_vector	p;

	intens = 0;
	// p = sum_vect(scene->camera->center, num_product_vect(scene->ray, closest_dot));
	light = vec_subtract(light_fig->coords, obj->point.inter_pos);
	vec_normalize(&light);
	// ray_norm(scene, obj, p);//p-n spherayi ketna,aveli konkret charagayti u spherayi hatman ketna
	// n_dot_l = vec_dot_product(obj->ray_norm, light);
	n_dot_l = vec_dot_product(obj->point.inter_normal_vec, light);
	if (n_dot_l > 0)
		intens = light_fig->brightness * n_dot_l;
	return (calc_rgb_light(light_fig->color, intens));
}

t_color	specular_light(t_scene *scene, t_light *light_fig, t_figure *obj)
{
	double		spec;
	t_vector	light;
	t_vector	vec_V;
	t_vector	reflected;
	// t_vector	p;

	spec = 0;
	// p = sum_vect(scene->camera->center, num_product_vect(scene->ray, closest_dot));
	light = vec_subtract(light_fig->coords,  obj->point.inter_pos);
	vec_normalize(&light);
	// printf("Normal length: %f\n", sqrt(vec_dot_product(light, light)));

	vec_V = vec_subtract(scene->camera->center,  obj->point.inter_pos);
	vec_normalize(&vec_V);
	// printf("Normal length: %f\n", sqrt(vec_dot_product(vec_V, vec_V)));

	// ray_norm(scene, obj, p);
	// reflected = reflect_ray(light, obj->ray_norm);
	reflected = reflect_ray(light, obj->point.inter_normal_vec);
	vec_normalize(&reflected);
	// printf("Normal length: %f\n", sqrt(vec_dot_product(reflected, reflected)));
	// printf("reflected->x%f reflected->y%f reflected->z%f\n", reflected.x , reflected.y, reflected.z);
	// printf("vec_V->x%f vec_V->y%f vec_V->z%f\n", vec_V.x , vec_V.y, vec_V.z);
		// printf("brightness = %f\n", light_fig->brightness);
		// printf("obji specular = %f\n", obj->specular);
	
	if (vec_dot_product(reflected, vec_V) > 0)
	{
		// printf("chmtaaaaaaaaaaaaar\n");
		spec = light_fig->brightness * pow(vec_dot_product(reflected, vec_V), \
			obj->specular);
		// printf("dasdsd %.200f\n",pow(vec_dot_product(reflected, vec_V), obj->specular));
		// printf("dasdsddddddddddddddddddddddddddddddddddddddddddd %.f\n",vec_dot_product(reflected, vec_V));

		// printf("spcualr = %.200f\n", spec);
	}
	// printf("obji type = %f\n", spec);
	return (calc_rgb_light(light_fig->color, spec));

}

t_vector	reflect_ray(t_vector light, t_vector p_normal)
{
	t_vector	reflected;

	reflected = num_product_vect(p_normal, 2 * vec_dot_product(light, p_normal));
	reflected = vec_subtract(reflected, light);
	return (reflected);
}
// void	set_hit_normal(t_figure **obj, t_vector ray)
// {
// 	if (obj->type == SPHERE)
// 		 = calculate_sph_normobj;
	// else if ((*obj)->type == PLANE)
	// 	(*obj)->point.hit_norm = calculate_pln_norm(*obj, ray);
	// else if ((*obj)->type == CYLINDER && (*obj)->cyl->cap == 0)
	// 	(*obj)->point.hit_norm = calculate_cyl_norm(*obj);
	// else if ((*obj)->type == CYLINDER && (*obj)->cyl->cap == 1)
	// {
	// 	if (vec_dot_product((*obj)->cyl->axis, ray) < 0)
	// 		(*obj)->point.hit_norm = (*obj)->cyl->axis;
	// 	else
	// 		(*obj)->point.hit_norm = vector_prod((*obj)->cyl->axis, -1);
	// 	(*obj)->cyl->cap = 0;
	// }
	// else if ((*obj)->type == CONE && (*obj)->cone->cap == 1)
	// {
	// 	if (vec_dot_product((*obj)->cone->axis, ray) < 0)
	// 		(*obj)->point.hit_norm = (*obj)->cone->axis;
	// 	else
	// 		(*obj)->point.hit_norm = vector_prod((*obj)->cone->axis, -1);
	// 	(*obj)->cone->cap = 0;
	// }
	// else if ((*obj)->type == CONE && (*obj)->cone->cap == 0)
	// (*obj)->point.hit_norm = calculate_cone_norm(*obj);
	// vec_normalize(&obj->point.hit_norm);
// }  /     PETQ KGA!!!!
