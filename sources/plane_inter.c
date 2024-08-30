/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:09:09 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/26 18:23:14 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	plane_intersect(t_vector pos, t_vector ray, t_plane *plane)
{
	float	dot;
	float	t;

	dot = vec_dot_product(plane->orient, ray);
	if (dot)
	{
		t = vec_dot_product(plane->orient, \
			vec_subtract(plane->coords, pos)) / dot;
		if (t > 0.001)
			return (t);
	}
	return (0);
}
