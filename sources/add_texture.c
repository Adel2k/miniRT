/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:49:19 by adel              #+#    #+#             */
/*   Updated: 2024/12/11 13:26:19 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	geting_texture(t_scene *scene)
{
	t_figure	*tmp;

	tmp = scene->figure;
	while (scene->figure)
	{
		if (scene->figure->type == SPHERE && scene->figure->sphere->has_texture)
			get_xpm(scene);
		if (scene->figure->type == SPHERE && scene->figure->sphere->has_bump)
			get_bmp(scene);
		scene->figure = scene->figure->next;
	}
	scene->figure = tmp;
}

void	get_xpm(t_scene *scene)
{
	t_figure	*tmp;

	tmp = scene->figure;
	if (tmp->type == SPHERE && tmp->sphere->has_texture == true)
	{
		tmp->sphere->texture.img_ptr = mlx_xpm_file_to_image(scene->mlx->mlx,
				tmp->sphere->path,
				&tmp->sphere->texture.width,
				&tmp->sphere->texture.height);
		if (!tmp->sphere->texture.img_ptr)
		{
			err("no xpm");
			exit(1);
		}
		tmp->sphere->texture.img_pixels_ptr = \
			mlx_get_data_addr(tmp->sphere->texture.img_ptr,
				&tmp->sphere->texture.bits_per_pixel,
				&tmp->sphere->texture.line_len,
				&tmp->sphere->texture.endian);
	}
}

void	get_bmp(t_scene *scene)
{
	t_figure	*tmp;

	tmp = scene->figure;
	if (tmp->type == SPHERE && tmp->sphere->has_bump == true)
	{
		tmp->sphere->bump.img_ptr = mlx_xpm_file_to_image(scene->mlx->mlx,
				tmp->sphere->bmp_map,
				&tmp->sphere->bump.width,
				&tmp->sphere->bump.height);
		if (!tmp->sphere->bump.img_ptr)
		{
			err("no bmp\n");
			exit(11);
		}
		tmp->sphere->bump.img_pixels_ptr = \
			mlx_get_data_addr(tmp->sphere->bump.img_ptr,
				&tmp->sphere->bump.bits_per_pixel,
				&tmp->sphere->bump.line_len,
				&tmp->sphere->bump.endian);
	}
}

void	color_black(t_color *color)
{
	color->red = 0;
	color->green = 0;
	color->blue = 0;
}

void	set_texture(char **matrix, t_sphere *sphere, t_scene *scene)
{
	if (matrix[4] && init_texture(matrix[4], sphere))
		exit_and_free_matrix(matrix, "Error: invalid xpm", scene);
	if (matrix[5] && init_bump(matrix[5], sphere))
		exit_and_free_matrix(matrix, "Error: invalid bmp", scene);
}
