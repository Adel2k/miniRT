/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:09:09 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/25 11:48:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// double	plane_intersect(t_vector pos, t_vector ray, t_plane *plane)
// {
// 	double	dot;
// 	double	t;

// 	dot = vec_dot_product(plane->orient, ray);
// 	if (dot)
// 	{
// 		t = vec_dot_product(plane->orient, 
// 			vec_subtract(plane->coords, pos)) / dot;
// 		if (t > 0.001)
// 			return (t);
// 	}
// 	return (0);
// }
