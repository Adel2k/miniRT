#include "../include/minirt.h"

int	in_shadow(t_scene *scene, t_vector ray, t_light	*light, \
	t_figure **obj)
{
	double		closest_dot;
	double		dot;
	t_figure	*tmp;

	dot = INFINITY;
	closest_dot = INFINITY;
	tmp = scene->figure;
	// printf("skizbna?->%d\n", tmp->type);
	while (tmp)
	{
		// if (tmp->type == LIGHT)
		// {
		// 	tmp = tmp->next;
		// 	continue ;
		// }
		dot = closest_inter(light->coords, ray, tmp, obj);
		if (dot > __FLT_EPSILON__ && dot < closest_dot)//dot > __FLT_EPSILON__ nayi tg um grvacy
		{
			closest_dot = dot;
			*obj = tmp;
		}
		tmp = tmp->next;
	}
	if (closest_dot != INFINITY)
	{
		// printf("0 ov\n");
		return (0);
	}
	return (1);
}

int	compute_shadow(t_scene *scene, t_figure **obj, t_light *light, double closest_dot)
{
	t_figure	*tmp;
	t_vector	light_ray;
	t_vector	p;

	tmp = NULL;
	// light_ray = vector_sub((*obj)->point.hit_pos, light->coordinate);
	// normalize_vector(&light_ray);
	
    p = sum_vect(scene->camera->center, num_product_vect(scene->ray, closest_dot));
	ray_norm(*obj, p);//p-n spherayi ketna,aveli konkret charagayti u spherayi hatman ketna
	light_ray = vec_subtract(p, light->coords);//ketic depi luysi axbyur
	vec_normalize(&light_ray);
    
    if (!in_shadow(scene, light_ray, light, &tmp) && tmp == *obj)
	{
		// printf("stexic pti helni\n");
		return (1);
	}
	// printf("senc depq unenq vapshe???????????\n");
	return (0);
}

// int compute_shadow(t_scene *scene, t_figure **obj, t_light *light, double closest_dot) {
//     t_figure *tmp = NULL;
//     t_vector p = sum_vect(scene->camera->center, num_product_vect(scene->ray, closest_dot));

//     // Вычисляем нормаль в точке пересечения
//     t_vector normal;
//     if ((*obj)->type == SPHERE)
//         normal = calculate_sph_norm(p, *obj);
//     // else if ((*obj)->type == PLANE)
//     //     normal = (*obj)->plane.normal;
//     // else if ((*obj)->type == CYLINDER)
//     //     normal = calculate_cylinder_norm(p, *obj); // Создайте эту функцию
//     vec_normalize(&normal);

//     // Смещаем точку
//     // p = sum_vect(p, num_product_vect(normal, 0.001));

//     // Рассчитываем направление луча света
//     t_vector light_ray = vec_subtract(p, light->coords);
//     vec_normalize(&light_ray);

//     // Проверяем тени
//     if (in_shadow(scene, light_ray, light, &tmp)) {
//         return 0; // В тени
//     }
//     return 1; // Свет доступен
// }
