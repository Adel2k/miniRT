/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:27:57 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/18 18:47:54 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
///////cylinder//////////  
void	ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new)
{
	t_cylinder	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast_cy(*lst);
	ptr -> next = new;
	// new->prev = ptr;
}
t_cylinder	*ft_lstlast_cy(t_cylinder *lst)
{
	if (lst == NULL)
		return (NULL);
	while
	 (lst && lst->next)
		lst = lst->next;
	return (lst);
}
///////////////plane///////////

void	ft_lstadd_back_pl(t_plane **lst, t_plane *new)
{
	t_plane	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast_pl(*lst);
	ptr -> next = new;
	// new->prev = ptr;
}

t_plane	*ft_lstlast_pl(t_plane *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

//////////sphere/////////

void	ft_lstadd_back_sp(t_sphere **lst, t_sphere *new)
{
	t_sphere	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast_sp(*lst);
	ptr -> next = new;
	// new->prev = ptr;
}

t_sphere	*ft_lstlast_sp(t_sphere *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
////////light//////

void	ft_lstadd_back_l(t_light **lst, t_light *new)
{
	t_light	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast_l(*lst);
	ptr -> next = new;
	// new->prev = ptr;
}

t_light	*ft_lstlast_l(t_light *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
//////camera///
void	ft_lstadd_back_ca(t_camera **lst, t_camera *new)
{
	t_camera	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast_ca(*lst);
	ptr -> next = new;
	// new->prev = ptr;
}
t_camera	*ft_lstlast_ca(t_camera *lst)
{
	if (lst == NULL)
		return (NULL);
	while
	 (lst && lst->next)
		lst = lst->next;
	return (lst);
}

////ambient////
void	ft_lstadd_back_amb(t_ambient **lst, t_ambient *new)
{
	t_ambient	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast_amb(*lst);
	ptr -> next = new;
	// new->prev = ptr;
}
t_ambient	*ft_lstlast_amb(t_ambient *lst)
{
	if (lst == NULL)
		return (NULL);
	while
	 (lst && lst->next)
		lst = lst->next;
	return (lst);
}
