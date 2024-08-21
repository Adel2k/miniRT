/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:27:57 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/21 21:21:43 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
t_figure	*lst_create_figure(t_scene *scene, char **matrix, int type)
{
	t_figure	*figure;

	figure = malloc(sizeof(t_figure));
	if (!figure)
		exit(EXIT_FAILURE);
	figure->sphere = NULL;
	figure->plane = NULL;
	figure->cylinder = NULL;
	if (type == SPHERE)
		figure->sphere = parse_sphere(matrix, scene);
	else if (type == PLANE)
		figure->plane = parse_plane(matrix, scene);
	else if (type == CYLINDER)
		figure->cylinder = parse_cylinder(matrix, scene); 
	figure->next = NULL;
	return (figure);
}

void	ft_lstadd_back_figure(t_figure **figure, t_figure *new)
{
	t_figure	*ptr;

	if (!*figure)
	{
		*figure = new;
		return ;
	}
	ptr = ft_lstlast_figure(*figure);
	ptr -> next = new;
}

t_figure	*ft_lstlast_figure(t_figure *figure)
{
	if (figure == NULL)
		return (NULL);
	while
	 (figure && figure->next)
		figure = figure->next;
	return (figure);
}
// ///////cylinder//////////  
// void	ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new)
// {
// 	t_cylinder	*ptr;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	ptr = ft_lstlast_cy(*lst);
// 	ptr -> next = new;
// 	// new->prev = ptr;
// }
// t_cylinder	*ft_lstlast_cy(t_cylinder *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while
// 	 (lst && lst->next)
// 		lst = lst->next;
// 	return (lst);
// }
// ///////////////plane///////////

// void	ft_lstadd_back_pl(t_plane **lst, t_plane *new)
// {
// 	t_plane	*ptr;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	ptr = ft_lstlast_pl(*lst);
// 	ptr -> next = new;
// 	// new->prev = ptr;
// }

// t_plane	*ft_lstlast_pl(t_plane *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst && lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// //////////sphere/////////

// void	ft_lstadd_back_sp(t_sphere **lst, t_sphere *new)
// {
// 	t_sphere	*ptr;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	ptr = ft_lstlast_sp(*lst);
// 	ptr -> next = new;
// 	// new->prev = ptr;
// }

// t_sphere	*ft_lstlast_sp(t_sphere *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst && lst->next)
// 		lst = lst->next;
// 	return (lst);
// }
// ////////light//////

// void	ft_lstadd_back_l(t_light **lst, t_light *new)
// {
// 	t_light	*ptr;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	ptr = ft_lstlast_l(*lst);
// 	ptr -> next = new;
// 	// new->prev = ptr;
// }

// t_light	*ft_lstlast_l(t_light *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst && lst->next)
// 		lst = lst->next;
// 	return (lst);
// }
// //////camera///
// void	ft_lstadd_back_ca(t_camera **lst, t_camera *new)
// {
// 	t_camera	*ptr;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	ptr = ft_lstlast_ca(*lst);
// 	ptr -> next = new;
// 	// new->prev = ptr;
// }
// t_camera	*ft_lstlast_ca(t_camera *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while
// 	 (lst && lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// ////ambient////
// void	ft_lstadd_back_amb(t_ambient **lst, t_ambient *new)
// {
// 	t_ambient	*ptr;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	ptr = ft_lstlast_amb(*lst);
// 	ptr -> next = new;
// 	// new->prev = ptr;
// }
// t_ambient	*ft_lstlast_amb(t_ambient *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while
// 	 (lst && lst->next)
// 		lst = lst->next;
// 	return (lst);
// }
