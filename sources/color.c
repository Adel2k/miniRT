/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:22:32 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/09 21:53:01 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	create_color(double r, double g, double b)
{
	t_color	color;

	color.red = r;
	color.green = g;
	color.blue = b;
	return (color);
}

int	rgb_color_to_hex(t_color rgb)
{
	return ((rgb.red << 16) | (rgb.green << 8) | rgb.blue);
}

t_color	multiply_rgbs(t_color a, t_color b)
{
	t_color	color;

	color.red = a.red * b.red / 255;
	color.green = a.green * b.green / 255;
	color.blue = a.blue * b.blue / 255;
	return (color);
}

t_vector	color_to_vector(t_color bump_color)
{
	double	scale;

	scale = 2.0 / 255.0;
	return ((t_vector){
		.x = (bump_color.red * scale - 1.0),
		.y = (bump_color.green * scale - 1.0),
		.z = (bump_color.blue * scale - 1.0)
	});
}

void	perturb_normal(t_vector *normal, t_vector bump)
{
	*normal = vec_normalize2(sum_vect(*normal, bump));
}
