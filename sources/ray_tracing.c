/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:40:50 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/10 01:12:49 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vplane	*get_view_plane(t_scene *scene)
{
	t_vplane	*vplane;
	double		aspect_ratio;

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		exit (1);
	aspect_ratio = WIDTH / scene->height;
	vplane->mlx_x = 0;
	vplane->mlx_y = 0;
	vplane->width = 2 * tan(scene->camera->fov / 2 * (M_PI / 180));
	vplane->height = vplane->width / aspect_ratio;
	vplane->pixel_x = vplane->width / WIDTH;
	vplane->pixel_y = vplane->height / scene->height;
	return (vplane);
}

t_vector	look_at(t_scene	*scene, double ray_x, double ray_y)
{
	t_vector	up;
	t_vector	new;
	t_vector	right;
	t_vector	ray_dir;

	up = new_vector(0, 1, 0);
	if (fabs(vec_dot_product(scene->camera->direction, up)) > 0.999)
		up = new_vector(0, 0, 1);
	right = vec_cross_product(scene->camera->direction, up);
	vec_normalize(&right);
	new = vec_cross_product(right, scene->camera->direction);
	vec_normalize(&new);
	ray_dir = sum_vect(sum_vect(num_product_vect(right, ray_x), \
		num_product_vect(new, ray_y)), scene->camera->direction);
	vec_normalize(&ray_dir);
	return (ray_dir);
}

void	ray_tracing(t_scene *scene)
{
	double		ray_x;
	double		ray_y;

	scene->vplane = get_view_plane(scene);
	scene->vplane->y_angle = scene->height / 2;
	while (scene->vplane->y_angle >= (scene->height / 2) * (-1))
	{
		scene->vplane->mlx_x = 0;
		ray_y = scene->vplane->pixel_y * scene->vplane->y_angle;
		scene->vplane->x_angle = (scene->width / 2) * (-1);
		while (scene->vplane->x_angle <= scene->width / 2)
		{
			ray_x = scene->vplane->pixel_x * scene->vplane->x_angle;
			scene->ray = look_at(scene, ray_x, ray_y);
			my_mlx_pixel_put(scene->img, scene->vplane->mlx_x, \
				scene->vplane->mlx_y, color_in_current_pixel(scene));
			scene->vplane->mlx_x++;
			scene->vplane->x_angle++;
		}
		scene->vplane->mlx_y++;
		scene->vplane->y_angle--;
	}
}

double	closest_inter(t_vector pos, t_vector ray, \
	t_figure *figure, t_figure **obj)
{
	double		dot;
	double		closest_dot;

	dot = INFINITY;
	closest_dot = INFINITY;
	while (figure)
	{
		if (figure->type == SPHERE)
			dot = sphere_intersect(pos, ray, figure);
		else if (figure->type == PLANE)
			dot = plane_inter(pos, ray, figure);
		else if (figure->type == CYLINDER)
			dot = cylinder_intersection(pos, ray, figure);
		if (dot > __FLT_EPSILON__ && dot < closest_dot)
		{
			closest_dot = dot;
			*obj = figure;
		}
		figure = figure->next;
	}
	return (closest_dot);
}

double	closest_inter_dlya_shadow(t_vector pos, t_vector ray, t_figure *figure)
{
	double		dot;

	dot = INFINITY;
	if (figure->type == SPHERE)
		dot = sphere_intersect(pos, ray, figure);
	else if (figure->type == PLANE)
		dot = plane_inter(pos, ray, figure);
	else if (figure->type == CYLINDER)
		dot = cylinder_intersection(pos, ray, figure);
	return (dot);
}
