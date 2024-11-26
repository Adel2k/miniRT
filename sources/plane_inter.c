/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:09:09 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/26 23:07:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// double	plane_inter(t_vector pos, t_vector ray, t_vector orient, t_vector coord)
// {
// 	double	dot;
// 	double	t;

// 	dot = vec_dot_product(orient, ray);
// 	if (dot)
// 	{
// 		t = vec_dot_product(orient, 
// 			vec_subtract(coord, pos)) / dot;
// 		if (t >= 0.001)
// 			return (t);
// 	}
// 	return (INFINITY);
// }
