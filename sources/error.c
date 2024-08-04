/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:56:26 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/04 17:01:31 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	exit_and_free_str(char *str_free, char *str_err)
{
	err(str_err);
	free (str_free);
	exit (1);
}

void	exit_and_free_matrix(char **map, char *str_err)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	err(str_err);
	exit(1);
}

// void	exit_and_free()
// {
	
// }