/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:22:32 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/25 17:46:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	new_color(int r, int g, int b)
{
	t_color	col;

	col.red = r;
	col.green = g;
	col.blue = b;
	return (col);
}

int	rgb_color_to_hex(t_color rgb)
{
	// printf("xii %p\n", rgb);
	return ((rgb.red << 16) | (rgb.green << 8) | rgb.blue);
}

t_color	calc_rgb_light(t_color col, double ratio)
{
	t_color	rgb;
	// printf("ratio->%f\n", ratio);
	rgb.red = col.red * ratio;
	rgb.green = col.green * ratio;
	rgb.blue = col.blue * ratio;
	if (rgb.red > 255)
		rgb.red = 255;
	if (rgb.green > 255)
		rgb.green = 255;
	if (rgb.blue > 255)
		rgb.blue = 255;
	// printf("red = %d blue = %d green = %d\n", rgb.red, rgb.green, rgb.blue);
	return (rgb);
}

t_color	add_rgb_light(t_color a, t_color b)
{
	t_color	color;

	color.red = a.red + b.red;
	color.green = a.green + b.green;
	color.blue = a.blue + b.blue;
	if (color.red > 255)
		color.red = 255;
	if (color.green > 255)
		color.green = 255;
	if (color.blue > 255)
		color.blue = 255;
	return (color);
}

t_color	multiply_rgbs(t_color a, t_color b)
{
	t_color	color;

	color.red = a.red * b.red / 255;
	color.green = a.green * b.green / 255;
	color.blue = a.blue * b.blue / 255;
	return (color);
}