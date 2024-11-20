/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_rottate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:11:32 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/09/18 16:23:52 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	_rotate_(int keypress, t_scene *scene)
{
	if (keypress == W)
		rotate_scene_up(scene);
	else if (keypress == S)
		rotate_scene_down(scene);
	else if (keypress == A)
		rotate_scene_left(scene);
	else if (keypress == D)
		rotate_scene_right(scene);
}

void	rotate_scene_up(t_scene *scene)
{
	t_figure	*figure;
	t_matrix	matrix;

	matrix = get_rotation_x(scene->j);
	figure = scene->figure;
	while (figure)
	{
		if (figure->type == SPHERE)
			rotate_sphere(figure->sphere, matrix);
		else if (figure->type == PLANE)
			rotate_plane(figure->plane, matrix);
		else if (figure->type == CYLINDER)
			rotate_cylinder(figure->cylinder, matrix);
		figure = figure->next;
	}
	rotate_light(scene->light, matrix);
}

void	rotate_scene_down(t_scene *scene)
{
	t_figure	*figure;
	t_matrix	matrix;

	figure = scene->figure;
	matrix = get_rotation_x(-scene->j);
	while (figure)
	{
		if (figure->type == SPHERE)
			rotate_sphere(figure->sphere, matrix);
		else if (figure->type == PLANE)
			rotate_plane(figure->plane, matrix);
		else if (figure->type == CYLINDER)
			rotate_cylinder(figure->cylinder, matrix);
		figure = figure->next;
	}
	rotate_light(scene->light, matrix);
}

void	rotate_scene_left(t_scene *scene)
{
	t_figure	*figure;
	t_matrix	matrix;

	figure = scene->figure;
	matrix = get_rotation_y(scene->i);
	while (figure)
	{
		if (figure->type == SPHERE)
			rotate_sphere(figure->sphere, matrix);
		else if (figure->type == PLANE)
			rotate_plane(figure->plane, matrix);
		else if (figure->type == CYLINDER)
			rotate_cylinder(figure->cylinder, matrix);
		figure = figure->next;
	}
	rotate_light(scene->light, matrix);
}

void	rotate_scene_right(t_scene *scene)
{
	t_figure	*figure;
	t_matrix	matrix;

	figure = scene->figure;
	matrix = get_rotation_y(-scene->i);
	while (figure)
	{
		if (figure->type == SPHERE)
			rotate_sphere(figure->sphere, matrix);
		else if (figure->type == PLANE)
			rotate_plane(figure->plane, matrix);
		else if (figure->type == CYLINDER)
			rotate_cylinder(figure->cylinder, matrix);
		figure = figure->next;
	}
	rotate_light(scene->light, matrix);
}


t_matrix	get_rotation_x(float angle)
{
	t_matrix	out_m;
	float		rad;

	rad = M_PI / 180 * angle;
	out_m = new_zero_matrix();
	out_m.m[0][0] = 1;
	out_m.m[1][1] = cos(rad);
	out_m.m[1][2] = -sin(rad);
	out_m.m[2][1] = sin(rad);
	out_m.m[2][2] = cos(rad);
	return (out_m);
}

t_matrix	get_rotation_y(float angle)
{
	t_matrix	out_m;
	float		rad;

	rad = M_PI / 180 * angle;
	out_m = new_zero_matrix();
	out_m.m[0][0] = cos(rad);
	out_m.m[0][2] = sin(rad);
	out_m.m[1][1] = 1;
	out_m.m[2][0] = -sin(rad);
	out_m.m[2][2] = cos(rad);
	out_m.m[3][3] = 1;
	return (out_m);
}

t_matrix	get_rotation_z(float angle)
{
	t_matrix	out_m;
	float		rad;

	rad = M_PI / 180 * angle;
	out_m = new_zero_matrix();
	out_m.m[0][0] = cos(rad);
	out_m.m[0][1] = -sin(rad);
	out_m.m[1][0] = sin(rad);
	out_m.m[1][1] = cos(rad);
	out_m.m[2][2] = 1;
	out_m.m[3][3] = 1;
	return (out_m);
}
