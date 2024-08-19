/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:07:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/19 19:56:15 by vbarsegh         ###   ########.fr       */
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
	if (validation(ac, av, rt) == 0)
	{
		init_mlx(vars, rt);
		printf("chjoka\n");
		system("leaks miniRT");
		return 0;
	}
	err("Error: Incorrect file");
	// free_(rt, vars);
	free(rt);
	free(vars);
	system("leaks miniRT");
	return 1;
}

void	free_(t_minirt *rt, t_mlx_vars *vars)
{
	free(rt->ambient);
	free(rt->camera);
	free(rt->light);
	free(rt->objects.plane);
	free(rt);
	free(vars);
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
