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


t_vector	calculate_sph_norm(t_vector p, t_figure *obj)
{
	t_vector vvvv = vec_subtract(p, obj->sphere->center);
	vec_normalize(&vvvv);
	// printf("Normal length: %f\n", sqrt(vec_dot_product(vvvv, vvvv)));
	// return (vec_subtract(p, obj->sphere->center));
	return (vvvv);
}
// double	compute_light(double dot, t_scene *scene, t_vector ray, t_figure *figure)
// {
// 	t_vector	prod;
// 	t_vector	p;
// 	t_vector	norm;
// 	t_vector	light;
// 	t_vector	v;
// 	t_vector	r;
// 	// t_sphere	*sph;
// 	double	n_dot_l;
// 	double	r_dot_v;
// 	double	i;

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

// double	compute_light(double dot, t_scene *scene, t_figure *tmp)
// {
// 	t_vector		p;
// 	t_vector		light;
// 	t_figure	*shadow;
// 	double		n_dot_l;
// 	double		i;

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
// 		i += scene->light->brightness * n_dot_l / 
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
		// printf("haaaaaa\n");
		fig->ray_norm = vec_subtract(p, fig->sphere->center);
		vec_normalize(&fig->ray_norm);
	}
	else if (fig->type == PLANE)
		fig->ray_norm = fig->plane->orient;
	else if (fig->type == CYLINDER)
		fig->ray_norm = fig->cylinder->ray_norm;
}


t_color	compute_light(t_scene *scene, t_figure *obj, t_color *specular, double closest_dot)
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
			// printf("specular->x->%d\n", specular->red);
			// printf("specular->y->%d\n", specular->green);
			// printf("specular->z->%d\n", specular->blue);
		// }
		light_tmp = light_tmp->next;
	}
	return (light_in_vec);
}



t_color	diffuse_light(t_scene *scene, t_figure *obj, t_light *light_fig, double closest_dot)
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

t_color	specular_light(t_scene *scene, t_light *light_fig, t_figure *obj, double closest_dot)
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
	// printf("Normal length: %f\n", sqrt(vec_dot_product(light, light)));

	vec_V = vec_subtract(scene->camera->center, p);
	vec_normalize(&vec_V);
	// printf("Normal length: %f\n", sqrt(vec_dot_product(vec_V, vec_V)));

	// ray_norm(obj, p);
	// vec_normalize(&p);
	if (obj->type == SPHERE)
		reflected = reflect_ray(light, calculate_sph_norm(p, obj));//teria es masy menak spheri hamara arac,avelacnel myus figurneri hamar(cylinder, plane)
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
		printf("dasdsddddddddddddddddddddddddddddddddddddddddddd %.f\n",vec_dot_product(reflected, vec_V));

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
// 	if ((*obj)->type == SPHERE)
// 		 = calculate_sph_norm(*obj);
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
	// vec_normalize(&(*obj)->point.hit_norm);
// }  /     PETQ KGA!!!!
