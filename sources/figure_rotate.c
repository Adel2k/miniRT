/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:05:06 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/06 22:58:09 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	rotate_sphere(t_sphere *sph, t_matrix matrix)
{
	sph->center = multi_mat_vect(matrix, sph->center);
}

void	rotate_plane(t_plane *plane, t_matrix matrix)
{
	plane->coords = multi_mat_vect(matrix, plane->coords);
	plane->orient = multi_mat_vect(matrix, plane->orient);
}

void	rotate_light(t_light *light, t_matrix matrix)
{
	(light)->coords = multi_mat_vect(matrix, (light)->coords);
}

void	rotate_cylinder(t_cylinder *cylinder, t_matrix matrix)
{
	cylinder->center = multi_mat_vect(matrix, cylinder->center);
	cylinder->orient = multi_mat_vect(matrix, cylinder->orient);
}
