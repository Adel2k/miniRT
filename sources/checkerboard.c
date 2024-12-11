/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:34:16 by adel              #+#    #+#             */
/*   Updated: 2024/12/10 14:11:39 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_color	apply_checkerboard(t_figure *obj)
{
	t_check		checker;
	double		u;
	double		v;
	int			check_x;
	int			check_y;

	if (obj->type != SPHERE || !obj->sphere->has_check)
		return (obj->color);
	get_sphere_uv(obj->sphere, obj->point.inter_pos, &u, &v);
	checker.width = 5;
	checker.height = 10;
	check_x = (int)(u * checker.width) % 2;
	check_y = (int)(v * checker.height) % 2;
	if ((check_x + check_y) % 2 == 0)
		checker.color = obj->color;
	else
	{
		checker.color.red = 0;
		checker.color.green = 0;
		checker.color.blue = 0;
	}
	return (checker.color);
}
