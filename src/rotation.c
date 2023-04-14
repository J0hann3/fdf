/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:12:17 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 20:02:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_plan_isometrique(t_coordonnee_3d *tab_3d,
			t_coordonnee_3d *tab_const, unsigned int len)
{
	unsigned int	i;
	t_coordonnee_3d	*tmp;
	t_coordonnee_3d	pt;
	t_trigo			alpha;
	t_trigo			beta;

	i = 0;
	alpha = fill_trigo(-asin(tan(M_PI / 6.0)));
	beta = fill_trigo(-M_PI_4);
	if (tab_const != NULL)
		tmp = tab_const;
	else
		tmp = tab_3d;
	while (i < len)
	{
		pt.x = tmp[i].x;
		pt.y = tmp[i].y;
		pt.z = tmp[i].z;
		tab_3d[i].x = pt.x * beta.cos - pt.z * beta.sin;
		tab_3d[i].y = pt.x * alpha.sin * beta.sin + pt.y * alpha.cos + pt.z
			* alpha.sin * beta.cos;
		tab_3d[i].z = pt.x * alpha.cos * beta.sin - pt.y * alpha.sin + pt.z
			* alpha.cos * beta.cos;
		++i;
	}
}

void	rotate_plan_cabinet(t_coordonnee_3d *tab_3d, t_coordonnee_3d *tab_const,
			unsigned int len)
{
	unsigned int	i;
	t_coordonnee_3d	*tmp;
	t_coordonnee_3d	pt;
	double			alpha_sin;
	double			alpha_cos;

	i = 0;
	alpha_cos = cos(-atan(2.0));
	alpha_sin = sin(-atan(2.0));
	if (tab_const != NULL)
		tmp = tab_const;
	else
		tmp = tab_3d;
	while (i < len)
	{
		pt.x = tmp[i].x;
		pt.y = tmp[i].y;
		pt.z = tmp[i].z;
		tab_3d[i].x = pt.x + (1. / 2.) * alpha_cos * pt.z;
		tab_3d[i].y = pt.y + (1. / 2.) * alpha_sin * pt.z;
		tab_3d[i].z = pt.z;
		i++;
	}
}

void	rotate_plan_x(t_coordonnee_3d *tab_3d, unsigned int len,
			double rotation)
{
	unsigned int	i;
	t_coordonnee_3d	pt;
	double			v_sin;
	double			v_cos;

	i = 0;
	v_cos = cos(rotation);
	v_sin = sin(rotation);
	while (i < len)
	{
		pt.y = tab_3d[i].y;
		pt.z = tab_3d[i].z;
		tab_3d[i].y = pt.y * v_cos + pt.z * v_sin;
		tab_3d[i].z = -pt.y * v_sin + pt.z * v_cos;
		i++;
	}
}

void	rotate_plan_y(t_coordonnee_3d *tab_3d, unsigned int len,
			double rotation)
{
	unsigned int	i;
	t_coordonnee_3d	pt;
	double			v_sin;
	double			v_cos;

	i = 0;
	v_cos = cos(rotation);
	v_sin = sin(rotation);
	while (i < len)
	{
		pt.x = tab_3d[i].x;
		pt.z = tab_3d[i].z;
		tab_3d[i].x = pt.x * v_cos + pt.z * v_sin;
		tab_3d[i].z = -pt.x * v_sin + pt.z * v_cos;
		i++;
	}
}

void	rotate_plan_z(t_coordonnee_3d *tab_3d, unsigned int len,
			double rotation)
{
	unsigned int	i;
	t_coordonnee_3d	pt;
	double			v_sin;
	double			v_cos;

	i = 0;
	v_cos = cos(rotation);
	v_sin = sin(rotation);
	while (i < len)
	{
		pt.x = tab_3d[i].x;
		pt.y = tab_3d[i].y;
		tab_3d[i].x = pt.x * v_cos - pt.y * v_sin;
		tab_3d[i].y = pt.x * v_sin + pt.y * v_cos;
		i++;
	}
}
