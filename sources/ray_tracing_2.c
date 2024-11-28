/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:40:50 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/28 20:25:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vplane	*get_view_plane(t_scene *scene)
{
	t_vplane	*vplane;
	double      aspect_ratio;

    vplane = malloc(sizeof(t_vplane));
    if (!vplane)
    {
        printf("ha vor?");
        exit (77777);
    }
    aspect_ratio = WIDTH / scene->height;
	vplane->mlx_x = 0;
	vplane->mlx_y = 0;
	vplane->width = 2 * tan(scene->camera->fov / 2 * (M_PI / 180));
    // printf("xooii\n");
	vplane->height = vplane->width / aspect_ratio;
	vplane->pixel_x = vplane->width / WIDTH;
	vplane->pixel_y = vplane->height / scene->height;
    // printf("bafrev\n");
	return (vplane);
}


t_vector	 look_at(t_scene	*scene, double ray_x, double ray_y)
{
    // Այս ֆունկցիան ստեղծում է վեկտոր՝ ճառագայթը տեսախցիկից դեպի տեսադաշտի որոշակի կետ ուղղելու համար:
	t_vector	up;
	t_vector	new;
	t_vector	right;
	t_vector	ray_dir;

	up = new_vector(0, 1, 0);
	if (fabs(vec_dot_product(scene->camera->direction, up)) > 0.999)
		up = new_vector(0, 0, 1);
	right = vec_cross_product(scene->camera->direction, up);
	// printf("do up-> %f %f %f\n",  right.x, right.y,  right.z);

	vec_normalize(&right);


	// printf("posle up-> %f %f %f\n",  right.x, right.y,  right.z);

	new = vec_cross_product(right, scene->camera->direction);
	vec_normalize(&new);

	ray_dir = sum_vect(sum_vect(num_product_vect(right, ray_x), \
		num_product_vect(new, ray_y)), scene->camera->direction);
	vec_normalize(&ray_dir);//это направление луча из камеры через определенную точку на виртуальной видовой плоскости (vplane). Она вычисляется как сумма трёх компонентов:
	//ray_dir=right⋅ray_x+new⋅ray_y+camera direction
    // Оно говорит: сдвинь луч вправо на ray_x, вверх на ray_y, и направь его вперёд вдоль направления камеры.
    return (ray_dir);
}

void	ray_tracing(t_scene *scene)
{
	// int			color;
	double		ray_x;
	double		ray_y;
	// t_vector	ray;
    // printf("ee->%f\n", scene->height);
    scene->vplane = get_view_plane(scene);
	scene->vplane->y_angle = scene->height / 2;
	while (scene->vplane->y_angle >= (scene->height / 2) * (-1))
	{
		scene->vplane->mlx_x = 0;
            // printf("steeeeeeeeeeee\n");
		ray_y = scene->vplane->pixel_y * scene->vplane->y_angle;
		scene->vplane->x_angle = (scene->width / 2) * (-1);
		while (scene->vplane->x_angle <= scene->width / 2)
		{
			ray_x = scene->vplane->pixel_x * scene->vplane->x_angle;
			scene->ray = look_at(scene, ray_x, ray_y);
			// object_intersection(scene, ray, &color);
			// my_mlx_pixel_put(scene, scene->vplane->mlx_x, 
			// 	scene->vplane->mlx_y, color);
            my_mlx_pixel_put(scene->img, scene->vplane->mlx_x, scene->vplane->mlx_y, color_in_current_pixel(scene));
			scene->vplane->mlx_x++;
			scene->vplane->x_angle++;
		}
		scene->vplane->mlx_y++;
		scene->vplane->y_angle--;
	}
}






int	color_in_current_pixel(t_scene *scene)
{
	int			color;
	t_figure	*obj;
	double		closest_dot;

	closest_dot = INFINITY;
	obj = scene->figure;
	closest_dot = closest_inter(scene->camera->center, scene->ray, scene->figure, &obj);
	if (closest_dot == INFINITY)
	{
		color = 0;
	}
	else
	{
		// printf("ray->x=%f  ", scene->ray.x);
		// color = get_color(obj, scene, closest_dot);
	get_pixel_color(&color, obj, scene, closest_dot);

	}
	// color = 0;
	// get_pixel_color(&color, obj, scene, closest_dot);
	return (color);
}

void	get_pixel_color(int *color, t_figure *obj, t_scene *scene, double closest_dot)
{
	t_color specular;
	t_color	light_in_vec;
	// printf("exxx->%p\n", obj->color);
	*color = rgb_color_to_hex(obj->color);
	// printf("hres->%d\n", *color);
	specular = new_color(0, 0, 0);
	// if (obj && obj->type == LIGHT)
	// 	return ;
	// ray_norm(obj, p);
	light_in_vec = compute_light(scene, obj, &specular, closest_dot);
	// printf("col.x = %d col.y = %d col.z = %d\n", obj->color.red, obj->color.green, obj->color.blue);
	// printf ("specular.x = %d specular.y = %d specular.z = %d\n", specular.red, specular.green, specular.blue);
	*color = rgb_color_to_hex(add_rgb_light(multiply_rgbs(light_in_vec, \
		(obj->color)), specular));
}



double	closest_inter(t_vector pos, t_vector ray, t_figure *figure, t_figure **tmp)
{
	double		dot;
	double		closest_dot;

	dot = INFINITY;
	closest_dot = INFINITY;
	while (figure)
	{
		// printf("Vrdoi type=%d\n",tmp->type);
		// usleep(100);
		if (figure->type == SPHERE)
			dot = sphere_intersect(pos, ray, figure->sphere);
		else if (figure->type == PLANE)
			dot = plane_inter(pos, ray, figure);
		// else if (figure->type == CYLINDER)
		// 	dot = cylinder_intersect(pos, ray, figure->cylinder);
		if (dot > __FLT_EPSILON__ && dot < closest_dot)
		{
			closest_dot = dot;
			*tmp = figure;
		}
		figure = figure->next;
	}
	return (closest_dot);
}



// int	get_color(t_figure *figure, t_scene *scene, double closest_dot)
// {
// 	int	r;
// 	int	g;
// 	int	b;
// 	double	bright;

// 	c
// //  Если bright меньше 1, цвета будут затемнены, если больше 1 — осветлены.
// 	bright = compute_light(closest_dot, scene, figure);
// 	r = figure->color->red * bright;
// 	g = figure->color->green * bright;
// 	b = figure->color->blue * bright;
// 	if (r > 255)
// 		r = 255;
// 	if (g > 255)
// 		g = 255;
// 	if (b > 255)
// 		b = 255;
// 	return (r << 16 | g << 8 | b);//mekel es masy harcnel
// }


