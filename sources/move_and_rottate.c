/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_rottate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:11:32 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/06 22:58:09 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	_rotate_(int keypress, t_scene *scene)
{
	if (keypress == W)
	{
		rotate_scene_up(scene);
	}
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

	matrix = get_rotation_x(scene->vplane->pixel_x);
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
	matrix = get_rotation_x(-scene->vplane->pixel_x);
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
	matrix = get_rotation_y(scene->vplane->y_angle);
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
	matrix = get_rotation_y(-scene->vplane->y_angle);
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
