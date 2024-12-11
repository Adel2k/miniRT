/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:39:19 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/09 02:08:08 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_matrix	new_zero_matrix(void)
{
	t_matrix	out_m;
	int			i;

	i = 0;
	while (i < 4)
	{
		out_m.m[i][0] = 0;
		out_m.m[i][1] = 0;
		out_m.m[i][2] = 0;
		out_m.m[i][3] = 0;
		i++;
	}
	return (out_m);
}

t_vector	multi_mat_vect(t_matrix m, t_vector v)
{
	t_vector	res;

	res.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + \
													m.m[0][3] * v.w;
	res.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + \
													m.m[1][3] * v.w;
	res.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + \
													m.m[2][3] * v.w;
	res.w = m.m[3][0] * v.x + m.m[3][1] * v.y + m.m[3][2] * v.z + \
													m.m[3][3] * v.w;
	return (res);
}
