/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:15:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/12/10 19:15:16 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*get_line(char *av, int fd, char *gnl, char *res)
{
	char	*temp;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(err("Error: cannot open the file"));
	res = NULL;
	temp = ft_strdup("");
	gnl = get_next_line(fd);
	while (gnl)
	{
		res = ft_strjoin(temp, gnl);
		free(temp);
		temp = res;
		free(gnl);
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
	}
	if (!res || *res == '\0' || ft_strchr(res, '\t') != NULL \
		|| only_new_line_or_spaces(res) == 1)
	{
		free(temp);
		return (NULL);
	}
	return (res);
}

char	**get_end_trim_map(char **map, t_scene *scene, int row, int j)
{
	char	**trim_map;

	trim_map = malloc(sizeof(char *) * (row + 1));
	if (!trim_map)
		exit_and_free_matrix(map, "cannot split", scene);
	row = 0;
	while (map[row])
	{
		if (!(only_trim_symbols(map[row]) == 1) \
			&& !(comment_line(map[row]) == 1))
			trim_map[j] = ft_strtrim(map[row], " \n\v\f\r    ");
		else
		{
			row++;
			continue ;
		}
		if (!trim_map[j])
			exit_and_free_matrix(map, "cannot split", scene);
		j++;
		row++;
	}
	trim_map[j] = NULL;
	free_matrix(map);
	return (trim_map);
}

char	**spliting(char *read_line, t_scene *scene)
{
	char	**map;
	char	*trim_line;
	int		row;

	trim_line = ft_strtrim(read_line, " \n\v\f\r    ");
	if (!trim_line)
		exit_and_free_str(read_line, "cannot trim", scene);
	free(read_line);
	map = split_char(trim_line, '\n');
	if (!map)
		exit_and_free_str(trim_line, "malloc error", scene);
	free(trim_line);
	row = 0;
	while (map[row])
		row++;
	return (get_end_trim_map(map, scene, row, 0));
}

int	validation(int ac, char **av, t_scene *scene)
{
	char	*read_line;
	char	**map;

	if (ac > 2)
		return (err("Error: Too much arguments!"));
	if (ac <= 1)
		return (err("Error: Few arguments! Enter the '.rt' file name"));
	if (ac == 2)
	{
		if (is_rt(av[1]))
			return (err("Error: Wrong argument: \
				Try this way: ./rt filename.rt"));
		read_line = get_line(av[1], 0, NULL, NULL);
		if (!read_line)
			return (1);
		map = spliting(read_line, scene);
		parsing(map, scene);
		free_matrix(map);
	//system("leaks miniRT");
	}
	return (0);
}
