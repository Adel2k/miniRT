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

// float	compute_light(float dot, t_scene *scene, t_vector ray, t_figure *figure)
// {
// 	t_vector	prod;
// 	t_vector	p;
// 	t_vector	norm;
// 	t_vector	light;
// 	t_vector	v;
// 	t_vector	r;
// 	// t_sphere	*sph;
// 	float	n_dot_l;
// 	float	r_dot_v;
// 	float	i;

// 	prod = num_product_vect(ray, dot);//ray-i x,y,z-@ *um enq dot-i chapov
// 	p = sum_vect(scene->camera->center, prod);//sranov stanum enq gndi ev ray-i hatman kety makeresi vra
// 	norm = vec_subtract(p, figure->center);//gndi kentronic minchev et hatman(p)kety vektor enq stanumx//հաշվել վեկտորը ոլորտի կենտրոնից մինչև p կետը,
// 	vec_normalize(norm);
// 	light = vec_subtract(scene->light->coords, p);//հաշվարկել վեկտորը p կետից մինչև լույսի աղբյուր:
// 	i = scene->ambient->ratio_lighting;//սահմանում ենք լուսավորության սկզբնական ինտենսիվությունը՝ հիմնվելով շրջակա միջավայրի լույսի վրա (շրջակա լուսավորություն, որը միշտ առկա է):
// 	//Ցրված լուսավորության հաշվարկ
// 	n_dot_l = vec_dot_product(norm, light);//մենք հաշվում ենք նորմալի և լուսային վեկտորի սկալյար արտադրյալը՝ նրանց միջև եղած անկյունը գտնելու համար։
// 	// sph = NULL;
// 	// if (closest_inter(p, light, scene->sphere, &sph) != INFINITY)
// 	// 		return (i);
// 	if (n_dot_l > 0)//ապա լույսի աղբյուրը լուսավորում է այդ կետը
// 		i += scene->light->brightness * n_dot_l / (vec_length(norm) * vec_length(light));
// 	if (figure->specular > 0)
// 	{
// 		v = num_product_vect(ray, -1);//փոխում ենք ճառագայթի ուղղությունը՝ p կետից դեպի դիտող վեկտոր ստանալու համար։
// 		r = num_product_vect(num_product_vect(norm, 2), n_dot_l);//արտացոլված վեկտորը՝
// 		r = vec_subtract(r, light);//մենք այն ուղղում ենք լույսի վեկտորի համեմատ:
// 		r_dot_v = vec_dot_product(r, v);//մենք գտնում ենք արտացոլված վեկտորի և դիտորդի վեկտորի սկալյար արտադրյալը:
// 		if (r_dot_v > 0)//ապա վերջնական լուսավորությանը ավելացնում ենք սպեկուլյար բաղադրիչ.
// 			i += scene->light->brightness * pow(r_dot_v/(vec_length(r) * vec_length(v)), sphere->specular);
// 	}
// 	return(i);
// }
// // Compute_light ֆունկցիան հաշվարկում է ստացված լուսավորությունը գնդի մակերևույթի tvyal կետում(dot)՝ հաշվի առնելով մի քանի գործոններ.

// // Ցրված լույս (ցրված լուսավորություն):
// // Տեսակետային արտացոլում (տեսակային լուսավորություն):
// // Լույսի հիմնական պարամետրերը (նրա պայծառությունը, ինտենսիվությունը, դիրքը և անկման անկյունը):

// // Վերջնական արդյունքը (i) տվյալ կետում լուսավորության ինտենսիվությունն է

// float	compute_light(float dot, t_scene *scene, t_figure *tmp)
// {
// 	t_vector		p;
// 	t_vector		light;
// 	t_figure	*shadow;
// 	float		n_dot_l;
// 	float		i;

// 	i = scene->ambient->ratio_lighting;
// 	p = sum_vect(scene->camera->center, num_product_vect(scene->ray, dot));
// 	ray_norm(tmp, p);
// 	light = vec_subtract(scene->light->coords, p);
// 	n_dot_l = vec_dot_product(tmp->ray_norm, light);
// 	shadow = NULL;//Կոդի այս հատվածը պատասխանատու է ստուգելու համար, թե արդյոք օբյեկտի մակերևույթի կետը գտնվում է ստվերում:
// 	if (closest_inter(p, light, scene->figure, &shadow) != __FLT_MAX__)// проверяет, есть ли объекты между точкой p и источником света, которые могут создать тень.
// 	{
// 		// usleep(200);
// 		// printf("mmmmmmmmmmm\n");
// 		return (i);
// 	}
// 	if (n_dot_l > 0)
// 		i += scene->light->brightness * n_dot_l / \
// 			(vec_length(tmp->ray_norm) * vec_length(light));//scene->light->brightness * cos(ø),nuynn esa eli
// 	// if (tmp->specular > 0)
// 	// {
// 	// 	i += compute_spec(scene, light, n_dot_l, tmp);
// 	// 	printf("puf\n");
// 	// }
// 	return (i);
// }
	

void	ray_norm(t_figure *fig, t_vector p)
{
	if (fig->type == SPHERE)
	{
		printf("haaaaaa\n");
		fig->ray_norm = vec_subtract(p, fig->sphere->center);
		vec_normalize(&fig->ray_norm);
	}
	else if (fig->type == PLANE)
		fig->ray_norm = fig->plane->orient;
	else if (fig->type == CYLINDER)
		fig->ray_norm = fig->cylinder->ray_norm;
}

// float	compute_spec(t_scene *scene, t_vector light, float n_dot_l, t_figure *fig)
// {
// 	t_vector	v;
// 	t_vector	r;
// 	float	i;
// 	float	r_dot_v;

// 	i = 0.0;
// 	v = num_product_vect(scene->ray, -1);
// 	r = num_product_vect(num_product_vect(fig->ray_norm, 2), n_dot_l);
// 	r = vec_subtract(r, light);
// 	r_dot_v = vec_dot_product(r, v);
// 	if (r_dot_v > 0)
// 		i += scene->light->brightness * \
// 			pow(r_dot_v / (vec_length(r) * vec_length(v)), fig->specular);
// 	return (i);
// }


t_color	compute_light(t_scene *scene, t_figure *obj, t_color *specular, float closest_dot)
{
	t_color		light_in_vec;
	t_light		*light_tmp;

	light_in_vec = calc_rgb_light(scene->ambient->light, scene->ambient->ratio_lighting);
	// if (obj->point.is_inside)
		// return (col);
	light_tmp = scene->light;
	while (light_tmp)
	{
		// if (compute_shadow(scene, &obj, light_tmp))
		// {
			light_in_vec = add_rgb_light(diffuse_light(scene, obj, light_tmp, closest_dot), light_in_vec);
			*specular = specular_light(scene, light_tmp, obj, closest_dot);
		// }
		light_tmp = light_tmp->next;
	}
	return (light_in_vec);
}



t_color	diffuse_light(t_scene *scene, t_figure *obj, t_light *light_fig, float closest_dot)
{
	double		intens;
	double		n_dot_l;
	t_vector	light;
	t_vector	p;

	intens = 0;
	p = sum_vect(scene->camera->center, num_product_vect(scene->ray, closest_dot));
	ray_norm(obj, p);//p-n spherayi ketna,aveli konkret charagayti u spherayi hatman ketna
	light = vec_subtract(light_fig->coords, p);
	vec_normalize(&light);
	n_dot_l = vec_dot_product(obj->ray_norm, light);
	if (n_dot_l > 0)
		intens = light_fig->brightness * n_dot_l;
	return (calc_rgb_light(light_fig->color, intens));
}

t_color	specular_light(t_scene *scene, t_light *light_fig, t_figure *obj, float closest_dot)
{
	double		spec;
	t_vector	light;
	t_vector	vec_V;
	t_vector	reflected;
	t_vector	p;

	spec = 0;
	p = sum_vect(scene->camera->center, num_product_vect(scene->ray, closest_dot));
	light = vec_subtract(light_fig->coords, p);
	vec_normalize(&light);
	vec_V = vec_subtract(scene->camera->center, p);
	vec_normalize(&vec_V);
	ray_norm(obj, p);
	reflected = reflect_ray(light, p);//chunenq tmp-n
	vec_normalize(&reflected);
	if (vec_dot_product(reflected, vec_V) > 0)
		spec = light_fig->brightness * pow(vec_dot_product(reflected, vec_V), \
			obj->specular);
	return (calc_rgb_light(light_fig->color, spec));
}


t_vector	reflect_ray(t_vector ray, t_vector p_normal)
{
	t_vector	reflected;

	reflected = num_product_vect(p_normal, 2 * vec_dot_product(ray, p_normal));
	reflected = vec_subtract(reflected, ray);
	return (reflected);
}
// void	set_hit_normal(t_figure **obj, t_vector ray)
// {
// 	if ((*obj)->type == SPHERE)
// 		(*obj)->point.hit_norm = calculate_sph_norm(*obj);
// 	else if ((*obj)->type == PLANE)
// 		(*obj)->point.hit_norm = calculate_pln_norm(*obj, ray);
// 	else if ((*obj)->type == CYLINDER && (*obj)->cyl->cap == 0)
// 		(*obj)->point.hit_norm = calculate_cyl_norm(*obj);
// 	else if ((*obj)->type == CYLINDER && (*obj)->cyl->cap == 1)
// 	{
// 		if (vec_dot_product((*obj)->cyl->axis, ray) < 0)
// 			(*obj)->point.hit_norm = (*obj)->cyl->axis;
// 		else
// 			(*obj)->point.hit_norm = vector_prod((*obj)->cyl->axis, -1);
// 		(*obj)->cyl->cap = 0;
// 	}
// 	else if ((*obj)->type == CONE && (*obj)->cone->cap == 1)
// 	{
// 		if (vec_dot_product((*obj)->cone->axis, ray) < 0)
// 			(*obj)->point.hit_norm = (*obj)->cone->axis;
// 		else
// 			(*obj)->point.hit_norm = vector_prod((*obj)->cone->axis, -1);
// 		(*obj)->cone->cap = 0;
// 	}
// 	else if ((*obj)->type == CONE && (*obj)->cone->cap == 0)
// 		(*obj)->point.hit_norm = calculate_cone_norm(*obj);
// 	vec_normalize(&(*obj)->point.hit_norm);
// }        PETQ KGA!!!!
