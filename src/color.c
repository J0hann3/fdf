/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:38:28 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 18:05:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color_f	gradient(t_color color1, t_color color2, float y1, float y2)
{
	t_color_f	e_color;

	if (color1.color != color2.color)
	{
		e_color.alpha = 0.0;
		e_color.red = (color2.red - color1.red) / (float)(y2 - y1);
		if (color1.red == color2.red)
			e_color.red = 0.0;
		e_color.green = (color2.green - color1.green) / (float)(y2 - y1);
		if (color1.green == color2.green)
			e_color.green = 0.0;
		e_color.blue = (color2.blue - color1.blue) / (float)(y2 - y1);
		if (color1.blue == color2.blue)
			e_color.blue = 0.0;
	}
	else
		e_color = (t_color_f){0.0, 0.0, 0.0, 0.0};
	return (e_color);
}

int	c_color(t_color color1, t_color_f gradient, int x, int x1)
{
	t_color	color;

	color.red = color1.red + (int)(gradient.red * (x - x1)) & 0xFF;
	color.green = color1.green + (int)(gradient.green * (x - x1))
		& 0xFF;
	color.blue = color1.blue + (int)(gradient.blue * (x - x1)) & 0xFF;
	return (color.color);
}
