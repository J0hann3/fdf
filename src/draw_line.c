/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:50:08 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/06 13:11:09 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->octets_per_pixel);
	*(unsigned int*)dst = color;
}

static void	line_vertical(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
		t_data *data)
{
	int		dy;
	int		y;
	t_color	color;
	t_color_f	e_color;

	y = pt2.y;
	if (pt1.y < pt2.y)
		y = pt1.y;
	dy = ft_abs(pt2.y - pt1.y) + y;
	e_color = gradient(pt1.color, pt2.color, pt1.y, pt2.y);
	// printf("y: %d	dist: %d	res: %f\n", y, dy, (float)y / (float)dy);
	while (y < dy && pt1.x >= 0 && pt1.x < WIDTH)
	{
		color.red = pt1.color.red + (int)(e_color.red * (y - pt1.y)) & 0xFF;
		color.green = pt1.color.green + (int)(e_color.green * (y - pt1.y)) & 0xFF;
		color.blue = pt1.color.blue +(int)(e_color.blue * (y - pt1.y)) & 0xFF;
		if (y >= 0 && y < HEIGHT)
		{
			my_mlx_pixel_put(data, pt1.x, y, color.color);
		}
		y = y + 1;
	}
}

static void	line_horizontal(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
		t_data *data)
{
	int	dx;
	int	x;
	t_color_f	e_color;
	t_color	color;

	x = pt2.x;
	if (pt1.x < pt2.x)
		x = pt1.x;
	dx = ft_abs(pt2.x - pt1.x) + x;
	e_color = gradient(pt1.color, pt2.color, pt1.x, pt2.x);
	// printf("x: %d	dist: %d	res: %f\n", x, dx, (float)x / (float)dx);
	while (x < dx && pt1.y >= 0 && pt1.y < HEIGHT)
	{
		color.red = pt1.color.red + (int)(e_color.red * (x - pt1.x)) & 0xFF;
		color.green = pt1.color.green + (int)(e_color.green * (x - pt1.x)) & 0xFF;
		color.blue = pt1.color.blue + (int)(e_color.blue * (x - pt1.x)) & 0xFF;
		if (x >= 0 && x < WIDTH)
		{
			my_mlx_pixel_put(data, x, pt1.y, color.color);
		}
		x = x + 1;
	}
}

static void	line_diagonale_bas(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
			t_data *data)
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		add;
	double	a;
	double	error;
	t_color	color;
	t_color_f	e_color;

	x = pt1.x;
	y = pt1.y;
	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	e_color = gradient(pt1.color, pt2.color, pt1.x, pt2.x);
	color.color = pt1.color.color;
	add = 1;
	if (dy < 0)
	{
		add = -1;
		dy = ft_abs(dy);
	}
	a = (float)dy / (float)dx;
	dx = dx + x;
	error = 0;
	// printf("debut: %x  fin:%x\n",pt1.color.color, pt2.color.color);
	// printf("x: %d	dist: %d	res: %f\n", x, dx, (float)x / (float)dx);
	while (x <= dx)
	{
		color.alpha = 0;
		// degrade(pt1.color, pt2.color, x, dx);
		color.red = pt1.color.red + (int)(e_color.red * (x - pt1.x)) & 0xFF;
		color.green = pt1.color.green + (int)(e_color.green * (x - pt1.x)) & 0xFF;
		color.blue = pt1.color.blue + (int)(e_color.blue * (x - pt1.x)) & 0xFF;
		// printf("bas : r : %f	g : %f	b : %f\n", e_color.red, e_color.green, e_color.blue);
		if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
			my_mlx_pixel_put(data, x, y, color.color);
		error = error + a;
		if (error >= 0.5)
		{
			y = y + add;
			error = error -1;
		}
		x = x + 1;
	}
	// printf("debut: %x  fin:%x red: %d green:%d blue:%d\n",pt1.color.color, pt2.color.color, (int)(e_color.red * (y - pt1.y)), (int)(e_color.green * (y - pt1.y)), (int)(e_color.blue * (y - pt1.y)));
}

static void	line_diagonale_haut(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
			t_data *data)
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		add;
	double	a;
	double	error;
	// Color
	t_color		color;
	t_color_f	e_color;

	// Color
	e_color = gradient(pt1.color, pt2.color, pt1.y, pt2.y);
	// printf("Color.Color = [%x]\n", color.color);
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
	// printf("debut: %x  fin:%x\n",pt1.color.color, pt2.color.color);
	while (y <= dy)
	{
		// printf("index haut : %d\n", (int)(y - pt1.y));
		color.red = pt1.color.red + (int)(e_color.red * (y - pt1.y)) & 0xFF;
		color.green = pt1.color.green + (int)(e_color.green * (y - pt1.y)) & 0xFF;
		color.blue = pt1.color.blue + (int)(e_color.blue * (y - pt1.y)) & 0xFF;
		if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
			my_mlx_pixel_put(data, x, y, color.color);
		error = error + a;
		if (error >= 0.5)
		{
			x = x + add;
			error = error - 1.0;
		}
		y = y + 1;
	}
	// printf("debut: %x  fin:%x red: %d green:%d blue:%d\n",pt1.color.color, pt2.color.color, (int)(e_color.red * (y - pt1.y)), (int)(e_color.green * (y - pt1.y)), (int)(e_color.blue * (y - pt1.y)));
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
