/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:50:08 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/30 16:40:29 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line_vertical(t_coordonnee_3d pt1, t_coordonnee_3d pt2, t_data *data,
			int color)
{
	int	dy;
	int	y;

	y = pt2.y;
	if (pt1.y < pt2.y)
		y = pt1.y;
	dy = ft_abs(pt2.y - pt1.y) + y;
	while (y < dy && pt1.x >= 0 && pt1.x < WIDTH)
	{
		if (y >= 0 && y < HEIGHT)
			my_mlx_pixel_put(data, pt1.x, y, color);
		y = y + 1;
	}
}

static void	line_horizontal(t_coordonnee_3d pt1, t_coordonnee_3d pt2, t_data *data,
			int color)
{
	int	dx;
	int	x;

	x = pt2.x;
	if (pt1.x < pt2.x)
		x = pt1.x;
	dx = ft_abs(pt2.x - pt1.x) + x;
	while (x < dx && pt1.y >= 0 && pt1.y < HEIGHT)
	{
		if (x >= 0 && x < WIDTH)
			my_mlx_pixel_put(data, x, pt1.y, color);
		x = x + 1;
	}
}

static void	line_diagonale_bas(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
			t_data *data, int color)
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		add;
	double	a;
	double	error;

	x = pt1.x;
	y = pt1.y;
	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	add = 1;
	if (dy < 0)
	{
		add = -1;
		dy = ft_abs(dy);
	}
	a = (float)dy / (float)dx;
	dx = dx + x;
	error = 0;
	while (x <= dx)
	{
		if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
			my_mlx_pixel_put(data, x, y, color);
		error = error + a;
		if (error >= 0.5)
		{
			y = y + add;
			error = error -1;
		}
		x = x + 1;
	}
}

static void	line_diagonale_haut(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
			t_data *data, int color)
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		add;
	double	a;
	double	error;

	x = pt1.x;
	y = pt1.y;
	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	add = 1;
	if (dx < 0)
	{
		add = -1;
		dx = ft_abs(dx);
	}
	a = (float)dx / (float)dy;
	dy = dy + y;
	error = 0;
	while (y <= dy)
	{
		if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
			my_mlx_pixel_put(data, x, y, color);
		error = error + a;
		if (error >= 0.5)
		{
			x = x + add;
			error = error - 1.0;
		}
		y = y + 1;
	}
}

void	draw_line(t_coordonnee_3d pt1, t_coordonnee_3d pt2, t_data *data,
			int color)
{
	int	dx;
	int	dy;

	dx = ft_abs(pt2.x - pt1.x);
	dy = ft_abs(pt2.y - pt1.y);
	if (dy == 0)
		line_horizontal(pt1, pt2, data, color);
	else if (dx == 0)
		line_vertical(pt1, pt2, data, color);
	else if (dy < dx)
	{
		if (pt1.x > pt2.x)
			line_diagonale_bas(pt2, pt1, data, color);
		else
			line_diagonale_bas(pt1, pt2, data, color);
	}
	else
	{
		if (pt1.y > pt2.y)
			line_diagonale_haut(pt2, pt1, data, color);
		else
			line_diagonale_haut(pt1, pt2, data, color);
	}
}

// void	draw_line(t_coordonnee_2d pt1, t_coordonnee_2d pt2, t_data *data,
// 			int color)
// {
// 	int		dy;
// 	int		dx;
// 	int		x;
// 	int		y;
// 	float	a;

// 	dx = ft_abs(pt2.x - pt1.x);
// 	dy = ft_abs(pt2.y - pt1.y);
// 	y = pt1.y;
// 	x = pt1.x;
// 	if (dx == 0)
// 	{
// 		while (y < dy)
// 		{
// 			my_mlx_pixel_put(data, x, y, color);
// 			y = y + 1;
// 		}
// 		return ;
// 	}
// 	else if (dy == 0)
// 	{
// 		while (x < dx)
// 		{
// 			my_mlx_pixel_put(data, x, y, color);
// 			x = x + 1;
// 		}
// 		return ;
// 	}
// 	a = dy / dx;
// 	if (dx >= dy)
// 	{
// 		while (x < dx)
// 		{
// 			y = lroundf(a * (x - pt1.x) + pt1.y);
// 			my_mlx_pixel_put(data, x, y, color);
// 			x = x + 1;
// 		}
// 	}
// 	else
// 	{
// 	}
// }
