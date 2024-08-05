/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:22:05 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/05 21:11:27 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../include/mlx.h"
# include "../include/get_next_line.h"

///////
typedef struct s_color
{
	int red;
    int green;
    int blue;
}	t_color;

typedef struct s_ambient
{
	float   ratio_lighting;
    t_color color;
}	t_ambient;
//////

/// ///
typedef struct s_vector
{
	float	x;
    float	y;
    float	z;
}	t_vector;

typedef struct s_camera
{
	t_vector    coordinates;
    int			fov;//size_t
	t_vector	orient;//3d normalized orientation vector. In range [-1,1] for each x,y,z axis:0.0,0.0,1.0
}	t_camera;
/// //////


typedef struct s_light
{
	// t_obj_id		id;
	t_vector		coords;
	float			brightness;
	t_color			color;
	// struct s_light	*next;
}	t_light;


typedef struct s_sphere
{
	// t_obj_id	id;
	t_vector	coords;
	float		diameter;
	// float		r2;
	t_color		color;
}	t_sphere;


typedef struct s_plane
{
	// t_obj_id	id;
	t_vector	coords;
	t_color		color;
	t_vector	orient;
}	t_plane;

typedef struct s_cylinder
{
	// t_obj_id	id;
	t_vector	coords;
	t_vector	orient;
	float		diameter;
	float		height;
	// float		r2;
	// t_vect		p1;
	// t_vect		p2;
	// t_vect		delta_p;
	t_color		color;
}	t_cylinder;

typedef struct s_objects
{
	t_plane		plane;
	t_sphere 	sphere;
	t_cylinder	cylinder;	
}	t_objects;

typedef struct s_minirt
{
	t_color		color;
	t_ambient	ambient;
	t_objects	objects;
	t_vector	vector;
	t_camera	camera;
	t_light		light;
}	t_minirt;


// size_t	ft_strlen(const char *str);
int		validation(int ac, char **av, t_minirt *rt);
int		malloc_check(char *s);
int		err(char *str);
char	*ft_strdup(char *s);
int		check1(char c, char const *set);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(const char *str, int c);
void	exit_and_free_str(char *str_free, char *str_err, t_minirt *rt);
char	**split_char(char const *s, char c);
void	exit_and_free_matrix(char **map, char *str_err, t_minirt *rt);
void	exit_and_free(char **map, char *str_err, t_minirt *rt, char **matrix);
int		is_rt(char *str);
char	*strtrim_end(char *str);
void	parsing(char **map, t_minirt *rt);
int	is_white_space(char c);
int	check_00(char **arr, const char *s, int count);
int	ft_strcmp(const char *s1, const char *s2);
//es spliti hamafr
char	**split(char const *s);
int	foo_sum_tar_(char const *s, char c);
int	func_count_word_(const char *s, char c);
void	found_what_scene_is_it(char **matrix, t_minirt *rt);
void	free_matrix(char **matrix);
void	parse_ambient(char **matrix, t_minirt *rt);
int if_line_contain_only_digit_and_char(char *line, char c);
int	ft_atoi(const char *str);
int	matrix_row(char **matrix);

double	ft_atof(const char *str);

int	ft_strlen(const char *str);

int if_only_digit(char *line);
void	parse_camera(char **matrix, t_minirt *rt);

#endif
