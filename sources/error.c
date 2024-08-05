/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:56:26 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/05 21:10:06 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	exit_and_free_str(char *str_free, char *str_err ,t_minirt *rt)
{
	err(str_err);
	free (str_free);
	free(rt);
	exit (1);
}

void	exit_and_free_matrix(char **map, char *str_err, t_minirt *rt)
{
	free_matrix(map);
	err(str_err);
	free(rt);
	exit(1);
}

void	exit_and_free(char **map, char *str_err, t_minirt *rt, char **matrix)
{
	exit_and_free_matrix(map, str_err, rt);
	free_matrix(matrix);
}
