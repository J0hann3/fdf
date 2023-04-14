/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:50:08 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/09 12:37:21 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_vertical(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
		t_data *data)
{
	int			dy;
	int			y;
	t_color_f	e_color;

	y = pt2.y;
	if (pt1.y < pt2.y)
		y = pt1.y;
	dy = ft_abs(pt2.y - pt1.y) + y;
	e_color = gradient(pt1.color, pt2.color, pt1.y, pt2.y);
	while (y < dy && pt1.x >= 0 && pt1.x < WIDTH)
	{
		if (y >= 0 && y < HEIGHT)
			my_mlx_pixel_put(data, pt1.x, y, c_color(pt1.color, e_color, y,
					pt1.y));
		y = y + 1;
	}
}

void	line_horizontal(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
		t_data *data)
{
	int			dx;
	int			x;
	t_color_f	e_color;

	x = pt2.x;
	if (pt1.x < pt2.x)
		x = pt1.x;
	dx = ft_abs(pt2.x - pt1.x) + x;
	e_color = gradient(pt1.color, pt2.color, pt1.x, pt2.x);
	while (x < dx && pt1.y >= 0 && pt1.y < HEIGHT)
	{
		if (x >= 0 && x < WIDTH)
			my_mlx_pixel_put(data, x, pt1.y, c_color(pt1.color, e_color, x,
					pt1.x));
		x = x + 1;
	}
}

void	draw_line(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
		t_data *data)
{
	int	dx;
	int	dy;

	dx = ft_abs(pt2.x - pt1.x);
	dy = ft_abs(pt2.y - pt1.y);
	if (dy == 0)
		line_horizontal(pt1, pt2, data);
	else if (dx == 0)
		line_vertical(pt1, pt2, data);
	else if (dy < dx)
	{
		if (pt1.x > pt2.x)
			line_diagonale_bas(pt2, pt1, data);
		else
			line_diagonale_bas(pt1, pt2, data);
	}
	else
	{
		if (pt1.y > pt2.y)
			line_diagonale_haut(pt2, pt1, data);
		else
			line_diagonale_haut(pt1, pt2, data);
	}
}
