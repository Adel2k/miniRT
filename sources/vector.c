/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:35:32 by aeminian          #+#    #+#             */
/*   Updated: 2024/11/24 21:51:50 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	new_vector(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = 1;
	return (vec);
}

t_vector	vec_subtract(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result = new_vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	return (result);
}

double	vec_length(t_vector vec)
{
	double	res;
	
	res = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return (res);
}

void	vec_normalize(t_vector *vec)
{
	double	length;
	
	length = vec_length(*vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
}

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

t_vector vec_cross_product(t_vector vec1, t_vector vec2)
{
    return new_vector(
        vec1.y * vec2.z - vec1.z * vec2.y,
        vec1.z * vec2.x - vec1.x * vec2.z,
        vec1.x * vec2.y - vec1.y * vec2.x
    );

	// return new_vector(
    //     -(vec1.y * vec2.z - vec1.z * vec2.y),
    //     -(vec1.z * vec2.x - vec1.x * vec2.z),
    //     -(vec1.x * vec2.y - vec1.y * vec2.x)
    // );
}