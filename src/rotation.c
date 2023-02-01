/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:12:17 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/01 13:40:13 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*\*/
#include "fdf.h"

void	rotate_plan_isometrique(t_coordonnee_3d *tab_3d, size_t len)
{
	size_t	i;
	float	z;
	float	x;
	float	y;
	double	alpha_sin;
	double	alpha_cos;
	double	beta_sin;
	double	beta_cos;

	i = 0;
	alpha_cos = cos(- asin(tan(M_PI / 6)));
	alpha_sin = sin(- asin(tan(M_PI / 6)));
	beta_cos = cos(- M_PI_4);
	beta_sin = sin(- M_PI_4);
	while (i < len)
	{
		x = tab_3d[i].x;
		y = tab_3d[i].y;
		z = tab_3d[i].z;
		tab_3d[i].x = x * beta_cos - z * beta_sin;
		tab_3d[i].y = x * alpha_sin * beta_sin + y * alpha_cos + z * alpha_sin * beta_cos;
		tab_3d[i].z = x * alpha_cos * beta_sin - y * alpha_sin + z * alpha_cos * beta_cos;
		i++;
	}
}

void	rotate_plan_x(t_coordonnee_3d *tab_3d, size_t len, double rotation)
{
	size_t	i;
	float	z;
	float	y;
	double	v_sin;
	double	v_cos;

	i = 0;
	v_cos = cos(rotation);
	v_sin = sin(rotation);
	while (i < len)
	{
		y = tab_3d[i].y;
		z = tab_3d[i].z;
		tab_3d[i].y = y * v_cos + z * v_sin;
		tab_3d[i].z = -y * v_sin + z * v_cos;
		// printf("x: %d, y: %d		x: %d, y: %d\n", x, y , tab_3d[i].x, tab_3d[i].y);
		i++;
	}
}

void	rotate_plan_y(t_coordonnee_3d *tab_3d, size_t len, double rotation)
{
	size_t	i;
	float	z;
	float	x;
	double	v_sin;
	double	v_cos;

	i = 0;
	v_cos = cos(rotation);
	v_sin = sin(rotation);
	while (i < len)
	{
		x = tab_3d[i].x;
		z = tab_3d[i].z;
		tab_3d[i].x = x * v_cos + z * v_sin;
		tab_3d[i].z = - x * v_sin + z * v_cos;
		// printf("x: %d, y: %d		x: %d, y: %d\n", x, y , tab_3d[i].x, tab_3d[i].y);
		i++;
	}
}

void	rotate_plan_z(t_coordonnee_3d *tab_3d, size_t len, double rotation)
{
	size_t	i;
	float	x;
	float	y;
	double	v_sin;
	double	v_cos;

	i = 0;
	v_cos = cos(rotation);
	v_sin = sin(rotation);
	while (i < len)
	{
		x = tab_3d[i].x;
		y = tab_3d[i].y;
		tab_3d[i].x = x * v_cos - y * v_sin;
		tab_3d[i].y = x * v_sin + y * v_cos;
		// printf("x: %d, y: %d		x: %d, y: %d\n", x, y , tab_3d[i].x, tab_3d[i].y);
		i++;
	}
}
/**/