/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:53:05 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/05 15:43:52 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parsing(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		found_what_scene_is_it(map[i]);
		i++;
	}
}

void	found_what_scene_is_it(char *line)
{
	int	i;

	i = 0;
	if (str[0] == 'A')
		parse_ambient(line);
	if (str[0] == 'C' )
		
	if (str[0] == 'L')
	
	if (str[0] == 's' && str[1] == 'p')
	
	if (str[0] == 'c' && str[1] == 'y')
		
	if (str[0] == 'p' && str[1] == 'l'))
		
}

void	parse_ambient(char *line)
{
	int	i;
	int	start;

	i = 1;
	if (check_is_white_space(line[i]) == 1)
	{
		while (check_is_white_space(line[i]) == 1)
			i++;
		if (is_digit(line[i]) == 1 && line[++i] == '.')
		{
			start = i++;//start-@ klni xosqi 7,i-nel 8?
			while (is_digit(line[i]) == 1)
				i++;
			end = i - 1;
			num_str = ft_substr(line, start, end);
			
		}
	}
}


int	check_is_white_space(char c)
{
	if ((c >= 9 && c <= 12) || c == 32)
		return (1);
	return (-1);
}