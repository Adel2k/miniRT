/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:15:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/11/27 23:41:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*get_line(char *av)
{
	int		fd;
	char	*gnl;
	char	*res;
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
	if (!res || *res == '\0' || ft_strchr(res, '\t') != NULL || only_new_line_or_spaces(res) == 1)
	{
		free(temp);
		return (NULL);
	}
	return (res);
}

char **get_end_trim_map(char **map, t_scene *scene)
{
	int		i;
	int		row;
	char	**trim_map;
	int j = 0;

	row = 0;
	while (map[row])
		row++;
	printf("row = %d\n", row);
	trim_map = malloc(sizeof(char *) * (row + 1));
	if (!trim_map)
		exit_and_free_matrix(map, "cannot do split", scene);
	i = 0;
	while (map[i])
	{
	printf("hasnum enq ste\n");
		if (!(only_trim_simbols(map[i]) == 1) && !(cur_line_is_com(map[i]) == 1))
			trim_map[j] =  ft_strtrim(map[i], " \n\v\f\r\t");
		else
		{
			i++;
			continue;
		}
		if(!trim_map[j])
			exit_and_free_matrix(map, "cannot do split", scene);
		i++;
		j++;
	}
	printf("i= ===============================%d\n",i);
	trim_map[j] = NULL;
	free_matrix(map);////////////////
	return(trim_map);
}

char **spliting(char *read_line, t_scene *scene)
{
	char	**map;
	char	*trim_line;

	trim_line = ft_strtrim(read_line, " \n\v\f\r\t");
	if (!trim_line)
		exit_and_free_str(read_line, "cannot do trim", scene);
	free(read_line);
	map = split_char(trim_line, '\n');//esi vaaaapshe lav chi
	if (!map)
		exit_and_free_str(trim_line, "malloc error", scene);
	free(trim_line);
	printf("axxxxxxx\n");
	return (get_end_trim_map(map, scene));
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
			return(err("Error: Wrong argument: Try this way: ./rt filename.rt"));
		read_line = get_line(av[1]);
		printf("read_line=%s\n",read_line);
		if (!read_line)
			return (1);//minchev ste leak chka
		map = spliting(read_line, scene);//minchev ste leak chka
		printf("asenq te\n");
		parsing(map, scene);
		// printf("badaxrichneri qanaky sxala\n");
		// int i = 0;
		// while (**map && map[i])
		// {
		// 	printf("boo:%s\n", map[i]);
		// 	i++;
		// }
		free_matrix(map);//////
	// system("leaks miniRT");
	// 	exit(1);
	}
		// system("leaks miniRT");
	return (0);
}

int	is_rt(char *str)
{
	size_t	len;

	if (!str || !*str)
		return (1);
	len = ft_strlen(str) - 1;
	if (len > 3)
	{
		if (str[len--] != 't')
			return (1);
		if (str[len--] != 'r')
			return (1);
		if (str[len--] != '.')
			return (1);
		return (0);
	}
	return (1);
}