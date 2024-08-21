/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:35:32 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/21 16:07:06 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	new_vector(float x, float y, float z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vector	vec_subtract(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result = new_vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	return (result);
}

float	vec_length(t_vector vec)
{
	float	res;
	
	res = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return (res);
}

t_vector	vec_normalize(t_vector vec)
{
	float	length;
	
	length = vec_length(vec);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	return (vec);
}

t_vector	num_product_vect(t_vector vec, float num)
{
	t_vector	new;

	new = new_vector(vec.x * num, vec.y * num, vec.z * num);
	return (new);
}

float	vec_dot_product(t_vector vec1, t_vector vec2)
{
	float	result;

	result = ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
	return (result);
}

t_vector	sum_vect(t_vector v1, t_vector v2)
{
	t_vector	new;
	
	new = new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (new);
}

