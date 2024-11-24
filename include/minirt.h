/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:22:05 by aeminian          #+#    #+#             */
/*   Updated: 2024/11/24 21:51:50 by vbarsegh         ###   ########.fr       */
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
# define WIDTH 1000
# define HEIGHT 700
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
	double	height;//ha vor?
	double	width;//ha vor?
}	t_img;

typedef struct s_atof
{
	double	num;
	int		sign;
	int		is_double;
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
	double   ratio_lighting;
    t_color light;
	int		count;
	// struct s_ambient	*next;
}	t_ambient;
//////

/// ///
typedef struct s_vector
{
	double	x;
    double	y;
    double	z;
	double	w;//chgitem xi,karoxa vor matricy 4*4a dra ahamar?
}	t_vector;

typedef struct s_camera
{
	t_vector    center;
    double		fov;//size_t,կհաշվարկի տեսադաշտի լայնությունը
	t_vector	direction;//uxxutyun
	int		count;
	// struct s_camera	*next;
}	t_camera;
/// //////


typedef struct s_light
{
	// t_obj_id		id;
	t_vector		coords;
	double			brightness;
	t_color			color;
	// int				count;
	struct s_light	*next;
}	t_light;


typedef struct s_sphere
{
	// t_obj_id	id;
	t_vector	center;
	// double		diameter;
	double		radius;;
	// double		r2;
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
	double		dist[2];
	t_vector	center;
	t_vector	orient;//n_coord
	double		radius;
	double		height;
	// double		r2;
	// t_vect		p1;
	// t_vect		p2;
	// t_vect		delta_p;
	t_color		color;
	// int			count;
	// struct s_cylinder	*next;
}	t_cylinder;


typedef struct s_math
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	x1;
	double	x2;
}				t_math;

typedef struct s_matrix
{
	double	m[4][4];
}	t_matrix;

typedef struct s_figure
{
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;
	// t_light			*light;//norem avelacre
	t_type			type;
	t_color			color;
	double			specular;
	t_vector		ray_norm;
	struct s_figure	*next;
}				t_figure;


typedef struct s_hatum
{
	double		dot;
	t_figure	*figure;
}	t_hatum;

// typedef struct s_vplane//okna prasmotra
// {
// 	t_camera	camera;
// 	t_vector	width;
// 	t_vector	hight;
// 	t_vector	pixel_00;
// 	t_vector	x_pixel;//piksel akna prasmotra
// 	t_vector	y_pixel;
// 	double 		plane_half_width;
//     double 		plane_half_height;
// 	t_vector up;
//     t_vector right;
// 	t_vector plane_center;
// 	t_vector half_width;
//     t_vector half_height;
// }	t_vplane;

typedef struct s_vplane
{
	int	mlx_x;
	int	mlx_y;
	double	width;
	double	height;
	double	pixel_x;
	double	pixel_y;
	double	x_angle;
	double	y_angle;
}	t_vplane;


typedef struct s_scene
{
	t_color		color;
	t_camera	*camera;
	t_ambient	*ambient;
	t_light		*light;
	t_figure	*figure;
	t_vplane	*vplane;
	int	i;
	int j;
	t_mlx_vars	*mlx;
	t_img		*img;//data
	t_vector	ray;
	t_vector	vector;
	double		width;
	double		height;
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
// void	ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new);
// t_cylinder	*ft_lstlast_cy(t_cylinder *lst);
// void	ft_lstadd_back_pl(t_plane **lst, t_plane *new);
// t_plane	*ft_lstlast_pl(t_plane *lst);
// void	ft_lstadd_back_sp(t_sphere **lst, t_sphere *new);
// t_sphere	*ft_lstlast_sp(t_sphere *lst);
t_light	*lst_create_light(t_scene *scene, char **matrix);
void	ft_lstadd_back_light(t_light **lst, t_light *new);
t_light	*ft_lstlast_light(t_light *lst);
// void	ft_lstadd_back_ca(t_camera **lst, t_camera *new);
// t_camera	*ft_lstlast_ca(t_camera *lst);
// void	ft_lstadd_back_amb(t_ambient **lst, t_ambient *new);
// t_ambient	*ft_lstlast_amb(t_ambient *lst);

t_figure	*lst_create_figure(t_scene *scene, char **matrix, int type);
void	ft_lstadd_back_figure(t_figure **figure, t_figure *new);
t_figure	*ft_lstlast_figure(t_figure *figure);

// t_scene	*new_scene(t_camera *camera, t_objects *object, int width, int hight);

/////////////////vector.c////////////////////////////
t_vector	new_vector(double x, double y, double z);
t_vector	vec_subtract(t_vector vec1, t_vector vec2);
double	vec_length(t_vector vec);
double	vec_dot_product(t_vector vec1, t_vector vec2);
void	vec_normalize(t_vector *vec);
double	vec_dot_product(t_vector vec1, t_vector vec2);
t_vector	num_product_vect(t_vector vec, double num);
t_vector	sum_vect(t_vector v1, t_vector v2);
double	dist_vect(t_vector v1, t_vector v2);
t_vector vec_cross_product(t_vector vec1, t_vector vec2);

//////////////////color_functions.c/////////////////////
t_color	calc_rgb_light(t_color col, double ratio);
int	rgb_color_to_hex(t_color rgb);
t_color	add_rgb_light(t_color a, t_color b);
t_color	new_color(int r, int g, int b);
t_color	multiply_rgbs(t_color a, t_color b);
/////////////////ray_tracing.c////////////////////////////
void	ray_tracing(t_scene *scene);
void	get_pixel_color(int *color, t_figure *obj, t_scene *scene, double closest_dot);
// t_vplane	*get_view_plane(t_camera *camera, double width, double hight, double fov);//ray_tracing.c
t_vplane	*get_view_plane(t_scene *scene);////ray_tracing_2.c

// double		sphere_intersect(t_camera *cam, t_vector ray, t_sphere *sphere);
double	sphere_intersect(t_vector center, t_vector ray, t_sphere *sphere);
// void	closest_inter(t_figure *figure, t_scene *scene, t_hatum *hatum, t_vector ray, t_figure *tmp);
// void	closest_inter(t_vector pos, t_vector ray, t_figure *tmp, t_scene *scene);
double	plane_inter(t_vector pos, t_vector ray, t_vector orient, t_vector coord);
double	cylinder_intersect(t_vector pos, t_vector ray, t_cylinder *cyl);
double	closest_inter(t_vector pos, t_vector ray, t_figure *figure, t_figure **tmp);
int	color_in_current_pixel(t_scene *scene);
//////qqqq////
double	calcul_dist(t_cylinder *cyl, double t, t_vector ray, t_vector pos);
double	vect_proj(t_vector pos, t_vector ray, t_cylinder *cyl, t_math *math);
double	side_inter(t_vector pos, t_vector ray, t_cylinder *cyl);
double	caps_inter(t_vector pos, t_vector ray, t_cylinder *cyl);
// double	cyl_inter(t_vector pos, t_vector ray, t_cylinder *cyl);
t_vector	cylray_norm(t_math *math, t_vector ray, t_vector pos, t_cylinder *cyl);
double	closest_dist(t_cylinder *cyl, t_math *m);
double	plane_inter(t_vector pos, t_vector ray, t_vector orient, t_vector coord);

void	_rotate_(int keypress, t_scene *scene);
void		_move_(int keypress, t_scene *scene);
void		_rotate_(int keypress, t_scene *scene);
int	draw(t_scene *scene);
void		rotate_scene_up(t_scene *scene);
void		rotate_scene_left(t_scene *scene);
void		rotate_scene_right(t_scene *scene);
void		rotate_scene_down(t_scene *scene);

void		rotate_sphere(t_sphere *sph, t_matrix matrix);
void		rotate_plane(t_plane *plane, t_matrix matrix);
void		rotate_light(t_light *light, t_matrix matrix);
void		rotate_cylinder(t_cylinder *cylinder, t_matrix matrix);

t_matrix	get_rotation_z(double angle);
t_matrix	get_rotation_y(double angle);
t_matrix	get_rotation_x(double angle);

t_vector	multi_mat_vect(t_matrix m, t_vector v);
t_matrix	new_zero_matrix(void);
void	count_check(t_scene *scene, char **matrix);
void	check_cam_count(t_camera *cam, char **matrix, t_scene *scene);
void	check_ambient_count(t_ambient *ambient, char **map, t_scene *scene);


void	free_scene(t_scene *scene);
void	init_scene(t_scene *scene);
/////////////////compute_light.c/////////////////
t_color	compute_light(t_scene *scene, t_figure *obj, t_color *specular, double closest_dot);
double	compute_spec(t_scene *scene, t_vector light, double n_dot_l, t_figure *fig);
void	ray_norm(t_figure *fig, t_vector p);
t_vector	calculate_sph_norm(t_vector p, t_figure *obj);
// double	compute_spec(t_scene *scene, t_vector light, double n_dot_l, t_figure *fig);
t_color	diffuse_light(t_scene *scene, t_figure *obj, t_light *light, double closest_dot);
t_color	specular_light(t_scene *scene, t_light *light, t_figure *obj, double closest_dot);
t_vector	reflect_ray(t_vector ray, t_vector p_normal);

#endif
