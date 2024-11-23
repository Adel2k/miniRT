/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:22:32 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/23 21:24:55 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	new_color(int r, int g, int b)
{
	t_color	col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

int	rgb_color_to_hex(t_color *rgb)
{
	return ((rgb->red << 16) | (rgb->green << 8) | rgb->blue);
}

t_color	calc_rgb_light(t_color col, double ratio)
{
	t_color	rgb;

	rgb.r = col.r * ratio;
	rgb.g = col.g * ratio;
	rgb.b = col.b * ratio;
	if (rgb.r > 255)
		rgb.r = 255;
	if (rgb.g > 255)
		rgb.g = 255;
	if (rgb.b > 255)
		rgb.b = 255;
	return (rgb);
}

t_color	add_rgb_light(t_color a, t_color b)
{
	t_color	color;

	color.r = a.r + b.r;
	color.g = a.g + b.g;
	color.b = a.b + b.b;
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	return (color);
}