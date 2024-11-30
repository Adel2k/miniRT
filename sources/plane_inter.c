/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:09:09 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/30 20:11:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	plane_inter(t_vector pos, t_vector ray, t_figure *obj)
{
	//pos->camera->center
	//t = (N . (P - O) / N . D)
	//O->camera->center
	//P hatman ket
	//N normal vektor in(on) plane
	double		norm_dot_dir;
	t_vector	p_in_cam_center;

	obj->point.dist = 0;
	calculate_plane_norm(obj, ray);
	obj->plane->orient = obj->point.inter_normal_vec;
	norm_dot_dir = vec_dot_product(obj->plane->orient, ray);//N . D
	if (fabs(norm_dot_dir) < __FLT_EPSILON__)// значит, луч параллелен плоскости, и пересечения нет.
		return (INFINITY);
	p_in_cam_center = vec_subtract(obj->plane->coords, pos);//// P0 - O
	obj->point.dist = vec_dot_product(p_in_cam_center, obj->plane->orient) / norm_dot_dir;//(N . (P - O) / N . D)
    
    if (obj->point.dist < __FLT_EPSILON__) // Пересечение позади луча
	{
		obj->point.dist = 0;//asuma sra kariqy chka gpt-n
        return (INFINITY);
	}
	return (obj->point.dist);
}
