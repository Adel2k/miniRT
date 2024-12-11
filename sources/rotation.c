/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:50:30 by adel              #+#    #+#             */
/*   Updated: 2024/12/06 22:58:09 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_matrix	get_rotation_x(double angle)
{
	t_matrix	out_m;
	double		rad;

	rad = M_PI / 180 * angle;
	out_m = new_zero_matrix();
	out_m.m[0][0] = 1;
	out_m.m[1][1] = cos(rad);
	out_m.m[1][2] = -sin(rad);
	out_m.m[2][1] = sin(rad);
	out_m.m[2][2] = cos(rad);
	return (out_m);
}

t_matrix	get_rotation_y(double angle)
{
	t_matrix	out_m;
	double		rad;

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

t_matrix	get_rotation_z(double angle)
{
	t_matrix	out_m;
	double		rad;

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
