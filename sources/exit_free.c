/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:56:26 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/19 18:54:33 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	err(char *str)
{
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	return (1);
}

void	exit_and_free_str(char *str_free, char *str_err ,t_minirt *rt)
{
	err(str_err);
	free (str_free);
	free(rt);
	system("leaks miniRT");
	exit (1);
}

void	exit_and_free_matrix(char **map, char *str_err, t_minirt *rt)
{
	free_matrix(map);
	err(str_err);
	// while (rt->light)
	// {
	// 	t_light *tmp = rt->light; 
	// 	rt->light = rt->light->next;
	// 	free(tmp);
	// }
	// free(rt->light);
	free(rt);
	system("leaks miniRT");
	exit(1);
}

void	exit_and_free(char **map, char *str_err, t_minirt *rt, char **matrix)
{
	free_matrix(matrix);
	// free(rt->vars);
	// free(&rt->scene->camera);
	exit_and_free_matrix(map, str_err, rt);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

// void	free_vars(t_mlx_vars *vars)
// {
// 	int	i;

// 	i = 0;
// 	while (i < vars->height_size)
// 	{
// 		free(vars->coordinates[i]);
// 		i++;
// 	}
// 	free(vars->coordinates);
// }