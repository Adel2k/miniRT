/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:35:32 by aeminian          #+#    #+#             */
/*   Updated: 2024/12/10 00:33:23 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	num_product_vect(t_vector vec, double num)
{
	t_vector	new;

	new = new_vector(vec.x * num, vec.y * num, vec.z * num);
	return (new);
}

double	vec_dot_product(t_vector vec1, t_vector vec2)
{
	double	result;

	result = ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
	return (result);
}

t_vector	sum_vect(t_vector v1, t_vector v2)
{
	t_vector	new;

	new = new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (new);
}

double	dist_vect(t_vector v1, t_vector v2)
{
	double	dist;

	dist = sqrt(powf(v1.x - v2.x, 2) + powf(v1.y - v2.y, 2) \
			+ powf(v1.z - v2.z, 2));
	return (dist);
}

t_vector	vec_cross_product(t_vector vec1, t_vector vec2)
{
	return (new_vector(
			vec1.y * vec2.z - vec1.z * vec2.y,
			vec1.z * vec2.x - vec1.x * vec2.z,
			vec1.x * vec2.y - vec1.y * vec2.x
		));
}
