/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:37:49 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/09 11:41:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_loop_bas(t_coordonnee_3d pt1, t_data *data, t_line_draw *line)
{
	while (line->x <= line->dx)
	{
		if ((line->x >= 0 && line->x < WIDTH) && (line->y >= 0 && line->y
				< HEIGHT))
			my_mlx_pixel_put(data, line->x, line->y, c_color(pt1.color,
					line->e_color, line->x, pt1.x));
		line->error = line->error + line->a;
		if (line->error >= 0.5)
		{
			line->y = line->y + line->add;
			line->error = line->error -1;
		}
		line->x = line->x + 1;
	}
}

void	line_diagonale_bas(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
			t_data *data)
{
	t_line_draw	line;

	line.x = pt1.x;
	line.y = pt1.y;
	line.dx = pt2.x - pt1.x;
	line.dy = pt2.y - pt1.y;
	line.e_color = gradient(pt1.color, pt2.color, pt1.x, pt2.x);
	line.add = 1;
	if (line.dy < 0)
	{
		line.add = -1;
		line.dy = ft_abs(line.dy);
	}
	line.a = (float)line.dy / (float)line.dx;
	line.dx = line.dx + line.x;
	line.error = 0;
	ft_loop_bas(pt1, data, &line);
}

static void	ft_loop_haut(t_coordonnee_3d pt1, t_data *data, t_line_draw *line)
{
	while (line->y <= line->dy)
	{
		if ((line->x >= 0 && line->x < WIDTH) && (line->y >= 0 && line->y
				< HEIGHT))
			my_mlx_pixel_put(data, line->x, line->y, c_color(pt1.color,
					line->e_color, line->y, pt1.y));
		line->error = line->error + line->a;
		if (line->error >= 0.5)
		{
			line->x = line->x + line->add;
			line->error = line->error - 1.0;
		}
		line->y = line->y + 1;
	}
}

void	line_diagonale_haut(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
			t_data *data)
{
	t_line_draw	line;

	line.e_color = gradient(pt1.color, pt2.color, pt1.y, pt2.y);
	line.x = pt1.x;
	line.y = pt1.y;
	line.dx = pt2.x - pt1.x;
	line.dy = pt2.y - pt1.y;
	line.add = 1;
	if (line.dx < 0)
	{
		line.add = -1;
		line.dx = ft_abs(line.dx);
	}
	line.a = (float)line.dx / (float)line.dy;
	line.dy = line.dy + line.y;
	line.error = 0;
	ft_loop_haut(pt1, data, &line);
}
