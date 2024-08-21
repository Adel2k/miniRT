/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goxcac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:26:29 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/21 19:17:05 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	compute_light(float dot, t_scene *scene, t_vector ray, t_sphere *sphere)
{
	t_vector	prod;
	t_vector	p;
	t_vector	norm;
	t_vector	light;
	t_vector	v;
	t_vector	r;
	// t_sphere	*sph;
	float	n_dot_l;
	float	r_dot_v;
	float	i;

	prod = num_product_vect(ray, dot);//ray-i x,y,z-@ *um enq dot-i chapov
	p = sum_vect(scene->camera->center, prod);//sranov stanum enq gndi ev ray-i hatman kety makeresi vra
	norm = vec_subtract(p, sphere->center);//gndi kentronic minchev et hatman(p)kety vektor enq stanumx//հաշվել վեկտորը ոլորտի կենտրոնից մինչև p կետը,
	vec_normalize(norm);
	light = vec_subtract(scene->light->coords, p);//հաշվարկել վեկտորը p կետից մինչև լույսի աղբյուր:
	i = scene->ambient->ratio_lighting;//սահմանում ենք լուսավորության սկզբնական ինտենսիվությունը՝ հիմնվելով շրջակա միջավայրի լույսի վրա (շրջակա լուսավորություն, որը միշտ առկա է):
	//Ցրված լուսավորության հաշվարկ
	n_dot_l = vec_dot_product(norm, light);//մենք հաշվում ենք նորմալի և լուսային վեկտորի սկալյար արտադրյալը՝ նրանց միջև եղած անկյունը գտնելու համար։
	// sph = NULL;
	// if (closest_inter(p, light, scene->sphere, &sph) != INFINITY)
	// 		return (i);
	if (n_dot_l > 0)//ապա լույսի աղբյուրը լուսավորում է այդ կետը
		i += scene->light->brightness * n_dot_l / (vec_length(norm) * vec_length(light));
	if (sphere->specular > 0)
	{
		v = num_product_vect(ray, -1);//փոխում ենք ճառագայթի ուղղությունը՝ p կետից դեպի դիտող վեկտոր ստանալու համար։
		r = num_product_vect(num_product_vect(norm, 2), n_dot_l);//արտացոլված վեկտորը՝
		r = vec_subtract(r, light);//մենք այն ուղղում ենք լույսի վեկտորի համեմատ:
		r_dot_v = vec_dot_product(r, v);//մենք գտնում ենք արտացոլված վեկտորի և դիտորդի վեկտորի սկալյար արտադրյալը:
		if (r_dot_v > 0)//ապա վերջնական լուսավորությանը ավելացնում ենք սպեկուլյար բաղադրիչ.
			i += scene->light->brightness * pow(r_dot_v/(vec_length(r) * vec_length(v)), sphere->specular);
	}
	return(i);
}
// Compute_light ֆունկցիան հաշվարկում է ստացված լուսավորությունը գնդի մակերևույթի tvyal կետում(dot)՝ հաշվի առնելով մի քանի գործոններ.

// Ցրված լույս (ցրված լուսավորություն):
// Տեսակետային արտացոլում (տեսակային լուսավորություն):
// Լույսի հիմնական պարամետրերը (նրա պայծառությունը, ինտենսիվությունը, դիրքը և անկման անկյունը):

// Վերջնական արդյունքը (i) տվյալ կետում լուսավորության ինտենսիվությունն է

