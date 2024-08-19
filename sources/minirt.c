/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:07:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/18 18:25:18 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int main(int ac, char **av)
{
	t_minirt 	*rt;
	t_mlx_vars	*vars;

	rt = malloc(sizeof(t_minirt));
	vars = malloc(sizeof(t_mlx_vars));
	if (!rt || !vars)
		return (1);
	init_rt(rt);
	if (!(validation(ac, av, rt)))
	{
		init_mlx(vars, rt);
		// system("leaks miniRT");
		return 0;
	}
	// system("leaks miniRT");
	return 1;
}


void	init_rt(t_minirt *rt)
{
	rt->camera = NULL;
	rt->ambient = NULL;
	rt->light = NULL;
	rt->objects.cylinder = NULL;
	rt->objects.plane = NULL;
	rt->objects.sphere = NULL;
}