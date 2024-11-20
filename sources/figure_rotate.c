/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:05:06 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/09/18 16:17:49 by vbarsegh         ###   ########.fr       */
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
	// t_light	*tmp;

	// tmp = (*light);
	// while (tmp)
	// {
	(light)->coords = multi_mat_vect(matrix, (light)->coords);
	// 	tmp = tmp->next;
	// }
}

void	rotate_cylinder(t_cylinder *cylinder, t_matrix matrix)
{
	cylinder->center = multi_mat_vect(matrix, cylinder->center);
	cylinder->orient = multi_mat_vect(matrix, cylinder->orient);
}