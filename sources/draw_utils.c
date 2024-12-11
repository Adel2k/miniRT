/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 01:04:47 by adel              #+#    #+#             */
/*   Updated: 2024/12/10 19:38:38 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	draw(t_scene *scene)
{
	scene->img->img_ptr = mlx_new_image(scene->mlx->mlx, WIDTH, HEIGHT);
	scene->img->img_pixels_ptr = mlx_get_data_addr(scene->img->img_ptr, \
	&scene->img->bits_per_pixel, &scene->img->line_len, &scene->img->endian);
	ray_tracing(scene);
	mlx_put_image_to_window(scene->mlx->mlx,
		scene->mlx->win, scene->img->img_ptr, 0, 0);
	// system("miniRT leaks");
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	char	*addr_end;

	addr_end = img->img_pixels_ptr + (HEIGHT * img->line_len);
	dst = img->img_pixels_ptr
		+(y * img->line_len + x * (img->bits_per_pixel / 8));
	if (dst >= img->img_pixels_ptr && dst < addr_end)
		*(unsigned int *)dst = color;
}

t_color	get_texture_color(t_img *texture, double u, double v)
{
	int		x;
	int		y;
	char	*pixel;
	t_color	color;

	if (!texture || !texture->img_pixels_ptr)
	{
		color.red = 0;
		color.green = 0;
		color.blue = 0;
		return (color);
	}
	x = (int)(u * texture->width) % texture->width;
	y = (int)(v * texture->height) % texture->height;
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
	{
		color_black(&color);
		return (color);
	}
	pixel = texture->img_pixels_ptr + (y * texture->line_len \
		+ x * (texture->bits_per_pixel / 8));
	color.red = *(unsigned char *)(pixel + 2);
	color.green = *(unsigned char *)(pixel + 1);
	color.blue = *(unsigned char *)(pixel);
	return (color);
}

void	set_texture_color(t_figure *obj, t_scene *scene, \
	t_color *texture_color, double u)
{
	t_vector	inter_p;
	t_color		bump_sample;
	t_vector	bump_vector;
	double		v;

	if (!obj)
		return ;
	*texture_color = obj->color;
	obj->point.inter_pos = sum_vect(scene->camera->center, \
		num_product_vect(scene->ray, obj->point.dist));
	set_inter_normal_vec(scene, obj);
	if (obj->type == SPHERE && (obj->sphere->has_texture \
		|| obj->sphere->has_bump || obj->sphere->has_check))
	{
		inter_p = sum_vect(scene->camera->center, \
			vec_scale(scene->ray, obj->point.dist));
		get_sphere_uv(obj->sphere, inter_p, &u, &v);
		*texture_color = drawing_texture(obj, u, v, texture_color);
		if (obj->sphere->has_bump)
		{
			bump_sample = get_texture_color(&obj->sphere->bump, u, v);
			bump_vector = color_to_vector(bump_sample);
			perturb_normal(&obj->point.inter_normal_vec, bump_vector);
		}
	}
}

int	color_in_current_pixel(t_scene *scene)
{
	int			color;
	t_figure	*obj;
	double		closest_dot;

	closest_dot = INFINITY;
	obj = NULL;
	closest_dot = closest_inter(scene->camera->center, scene->ray, \
		scene->figure, &obj);
	if (closest_dot == INFINITY)
		color = 0;
	else
		get_pixel_color(&color, obj, scene);
	return (color);
}
