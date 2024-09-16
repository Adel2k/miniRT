/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:22:05 by aeminian          #+#    #+#             */
/*   Updated: 2024/09/09 18:58:02 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define W 		13
# define A 		0
# define S 		1
# define D 		2
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define ESC	53
# define WIDTH 1920
# define HEIGHT 1080
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../include/mlx.h"
# include "../include/get_next_line.h"

typedef enum e_figure_type
{
	CYLINDER,
	SPHERE,
	PLANE,
}				t_type;

///////
typedef struct n_img
{
	void	*img_ptr;//pixelnerov stacvac yndhanur nkari hascena
	char	*img_pixels_ptr;//pixeli hascena
	int		bits_per_pixel;//mi piqselyb te qani bita zbaxecnum
	int		endian;
	int		line_len;//plangi erkarutyan vra qani pixela texavorvum
	float	height;//ha vor?
	float	width;//ha vor?
}	t_img;

typedef struct s_atof
{
	double	num;
	int		sign;
	int		is_float;
	double	fraction;
}	t_atof;

typedef struct s_mlx_vars
{
	void			*mlx;
	void			*win;
	// t_img			img;
}	t_mlx_vars;

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
	int		count;
	// struct s_ambient	*next;
}	t_ambient;
//////

/// ///
typedef struct s_vector
{
	float	x;
    float	y;
    float	z;
	float	w;//chgitem xi,karoxa vor matricy 4*4a dra ahamar?
}	t_vector;

typedef struct s_camera
{
	t_vector    center;
    float		fov;//size_t,կհաշվարկի տեսադաշտի լայնությունը
	t_vector	direction;//uxxutyun
	int		count;
	// struct s_camera	*next;
}	t_camera;
/// //////


typedef struct s_light
{
	// t_obj_id		id;
	t_vector		coords;
	float			brightness;
	t_color			color;
	// int				count;
	// struct s_light	*next;
}	t_light;


typedef struct s_sphere
{
	// t_obj_id	id;
	t_vector	center;
	// float		diameter;
	float		radius;;
	// float		r2;
	t_color		color;
	// int			count;
	// struct s_sphere	*next;
}	t_sphere;


typedef struct s_plane
{
	// t_obj_id	id;
	t_vector	coords;
	t_color		color;
	t_vector	orient;//uxxutyun
	// int			count;
	// struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	// t_obj_id	id;
	t_vector	ray_norm;//
	float		dist[2];
	t_vector	center;
	t_vector	orient;//n_coord
	float		radius;
	float		height;
	// float		r2;
	// t_vect		p1;
	// t_vect		p2;
	// t_vect		delta_p;
	t_color		color;
	// int			count;
	// struct s_cylinder	*next;
}	t_cylinder;


typedef struct s_math
{
	float	a;
	float	b;
	float	c;
	float	disc;
	float	x1;
	float	x2;
}				t_math;

typedef struct s_matrix
{
	float	m[4][4];
}	t_matrix;

typedef struct s_figure
{
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;
	t_type			type;
	t_color			*color;
	float			specular;
	t_vector		ray_norm;
	struct s_figure	*next;
}				t_figure;


typedef struct s_hatum
{
	float		dot;
	t_figure	*figure;
}	t_hatum;
typedef struct s_vplane//okna prasmotra
{
	t_vector	width;
	t_vector	hight;
	t_vector	pixel_00;
	t_vector	x_pixel;//piksel akna prasmotra
	t_vector	y_pixel;
}	t_vplane;
typedef struct s_scene
{
	t_color		color;
	t_camera	*camera;
	t_ambient	*ambient;
	t_light		*light;
	t_figure	*figure;
	t_vplane	*vplane;
	t_mlx_vars	*mlx;
	t_img		*img;//data
	t_vector	ray;
	t_vector	vector;
	float		width;
	float		height;
	t_hatum		hatum;
}	t_scene;





/////////////////exit_free////////////////////////
int		err(char *str);
void	exit_and_free_str(char *str_free, char *str_err, t_scene *scene);
void	exit_and_free_matrix(char **map, char *str_err, t_scene *scene);
void	exit_and_free(char **map, char *str_err, t_scene *scene, char **matrix);
void	free_matrix(char **matrix);
void	free_vars(t_mlx_vars *vars);

/////////////////parsing//////////////////////////////
void	parsing(char **map, t_scene *scene);
t_light	*parse_light(char **matrix, t_scene *scene);
t_sphere	*parse_sphere(char **matrix, t_scene *scene);
t_cylinder	*parse_cylinder(char **matrix, t_scene *scene);
t_plane	*parse_plane(char **matrix, t_scene *scene);

/////////////////parsing_utils////////////////////////
void	found_what_scene_is_it(char **matrix, t_scene *scene);
void	*parse_camera(char **matrix, t_scene *scene);
void	*parse_ambient(char **matrix, t_scene *scene);
int		count_shape(char **matrix, char *shape);

/////////////////init_mlx////////////////////////////
void	init_mlx(t_scene *scene);
void	init_scene(t_scene *scene);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
/////////////////utils///////////////////////////////
int		malloc_check(char *s);
int		check1(char c, char const *set);
int		is_white_space(char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strstr_alt(char *str, char *to_find);

/////////////////utils2/////////////////////////////
int		ft_atoi(const char *str);
int 	if_char_and_digit(char *line, char c);
int		matrix_row(char **matrix);
double	ft_atof(char *str);
int		if_only_digit(char *line);
int		if_str_and_digit(char *line, char *set);
int		have_this_char_in_set(char c, char *set);
char	*ft_strchr(const char *s, int c);
int	only_new_line_or_spaces(char *res);
/////////////////validation////////////////////////
int		validation(int ac, char **av, t_scene *scene);
int		is_rt(char *str);

/////////////////init_func////////////////////////////
void	init_coords(t_vector *coords, char **matrix, t_scene *scene, int i);
void	init_color(t_color *color, char **matrix, t_scene *scene, int i);
void	init_orient(t_vector *orient, char **matrix, t_scene *scene, int i);

/////////////////split_char////////////////////////////
int		foo_sum_tar_(char const *s, char c);
int		func_count_word_(const char *s, char c);
char	**split_char(char const *s, char c);
int		ft_strlen(const char *str);

/////////////////split////////////////////////////
int		check_00(char **arr, const char *s, int count);
char	**split(char const *s);

/////////////////trim////////////////////////////
char	*strtrim_end(char *str);
char	*ft_strtrim(char *s1, char *set);

/////////////////gnl////////////////////////////
char	*ft_strdup(char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr_gnl(const char *str, int c);

/////////////////key_hooks////////////////////////////
int		handler(int keysym, t_scene *scene);
int		mouse_close(t_scene *scene);

/////////////////list_functions////////////////////////////
void	ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new);
t_cylinder	*ft_lstlast_cy(t_cylinder *lst);
void	ft_lstadd_back_pl(t_plane **lst, t_plane *new);
t_plane	*ft_lstlast_pl(t_plane *lst);
void	ft_lstadd_back_sp(t_sphere **lst, t_sphere *new);
t_sphere	*ft_lstlast_sp(t_sphere *lst);
void	ft_lstadd_back_l(t_light **lst, t_light *new);
t_light	*ft_lstlast_l(t_light *lst);
void	ft_lstadd_back_ca(t_camera **lst, t_camera *new);
t_camera	*ft_lstlast_ca(t_camera *lst);
void	ft_lstadd_back_amb(t_ambient **lst, t_ambient *new);
t_ambient	*ft_lstlast_amb(t_ambient *lst);

t_figure	*lst_create_figure(t_scene *scene, char **matrix, int type);
void	ft_lstadd_back_figure(t_figure **figure, t_figure *new);
t_figure	*ft_lstlast_figure(t_figure *figure);

// t_scene	*new_scene(t_camera *camera, t_objects *object, int width, int hight);

/////////////////vector.c////////////////////////////
t_vector	new_vector(float x, float y, float z);
t_vector	vec_subtract(t_vector vec1, t_vector vec2);
float	vec_length(t_vector vec);
float	vec_dot_product(t_vector vec1, t_vector vec2);
t_vector	vec_normalize(t_vector vec);
float	vec_dot_product(t_vector vec1, t_vector vec2);
t_vector	num_product_vect(t_vector vec, float num);
t_vector	sum_vect(t_vector v1, t_vector v2);
float	dist_vect(t_vector v1, t_vector v2);

/////////////////ray_tracing.c////////////////////////////
void	ray_tracing(t_scene *scene);
t_vplane	*get_view_plane(float width, float hight, float fov);
// float		sphere_intersect(t_camera *cam, t_vector ray, t_sphere *sphere);
float	sphere_intersect(t_vector center, t_vector ray, t_sphere *sphere);
// void	closest_inter(t_figure *figure, t_scene *scene, t_hatum *hatum, t_vector ray, t_figure *tmp);
// void	closest_inter(t_vector pos, t_vector ray, t_figure *tmp, t_scene *scene);
float	plane_inter(t_vector pos, t_vector ray, t_vector orient, t_vector coord);
float	cylinder_intersect(t_vector pos, t_vector ray, t_cylinder *cyl);
float	closest_inter(t_vector pos, t_vector ray, t_figure *figure, t_figure **tmp);
int	get_color(int red, int green, int blue, float bright);
int	color_in_current_pixdel(t_scene *scene);
//////qqqq////
float	calcul_dist(t_cylinder *cyl, float t, t_vector ray, t_vector pos);
float	vect_proj(t_vector pos, t_vector ray, t_cylinder *cyl, t_math *math);
float	side_inter(t_vector pos, t_vector ray, t_cylinder *cyl);
float	caps_inter(t_vector pos, t_vector ray, t_cylinder *cyl);
// float	cyl_inter(t_vector pos, t_vector ray, t_cylinder *cyl);
t_vector	cylray_norm(t_math *math, t_vector ray, t_vector pos, t_cylinder *cyl);
float	closest_dist(t_cylinder *cyl, t_math *m);
float	plane_inter(t_vector pos, t_vector ray, t_vector orient, t_vector coord);



void	count_check(t_scene *scene, char **matrix);
void	check_cam_count(t_camera *cam, char **matrix, t_scene *scene);
void	check_ambient_count(t_ambient *ambient, char **map, t_scene *scene);


void	free_scene(t_scene *scene);
void	init_scene(t_scene *scene);
//////goxcac.c/////
// float	compute_light(float dot, t_scene *scene, t_vector ray, t_figure *figure);
float	compute_light(float dot, t_scene *scene, t_figure *tmp);
void	ray_norm(t_figure *fig, t_vector p);
float	compute_spec(t_scene *scene, t_vector light, float n_dot_l, t_figure *fig);

#endif
