/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:51:17 by adel              #+#    #+#             */
/*   Updated: 2024/12/05 15:51:17 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	in_shadow(t_scene *scene, t_vector ray, t_light	*light, \
	t_figure **obj)
{
	double		closest_dot;
	double		dot;
	t_figure	*tmp;

	dot = INFINITY;
	closest_dot = INFINITY;
	tmp = scene->figure;
	while (tmp)
	{
		dot = closest_inter_dlya_shadow(light->coords, ray, tmp);
		if (dot > __FLT_EPSILON__ && dot < closest_dot)
		{
			closest_dot = dot;
			*obj = tmp;
		}
		tmp = tmp->next;
	}
	if (closest_dot != INFINITY)
		return (1);
	return (0);
}

int	compute_shadow(t_scene *scene, t_figure *obj, t_light *light)
{
	t_figure	*tmp;
	t_vector	light_ray;

	tmp = NULL;
	light_ray = vec_subtract(obj->point.inter_pos, light->coords);
	vec_normalize(&light_ray);
	if (in_shadow(scene, light_ray, light, &tmp) && tmp == obj)
		return (1);
	return (0);
}

void	get_pixel_color(int *color, t_figure *obj, t_scene *scene)
{
	t_color	specular;
	t_color	light_in_vec;
	t_color	texture_color;

	set_texture_color(obj, scene, &texture_color, 0);
	specular = create_color(0, 0, 0);
	light_in_vec = compute_light(scene, obj, &specular);
	*color = rgb_color_to_hex(add_rgb_light \
		(multiply_rgbs(light_in_vec, texture_color), specular));
}
