/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:38:28 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/06 13:01:34 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	degrade(int color1, int color2, int y, int d)
// {
// 	unsigned char	r;
// 	unsigned char	g;
// 	unsigned char	b;

// 	(void)y;
// 	(void)d;

// 	// printf("color1: %d		color2: %d\n", color1, color2);
	
// 	r = ((((color1 >> 16) & 0xff) - ((color2 >> 16) & 0xff)) * ((float)y / d));
// 	g = ((((color1 >> 8) & 0xff) - ((color2 >> 8) & 0xff)) * ((float)y / d));
// 	b = (((color1 & 0xff) - (color2 & 0xff)) * ((float)y / d));

// 	printf("r : %d		g: %d		b: %d		color: %d \n", r, g, b, r << 16 | g << 8 | b);
// 	return (r << 16 | g << 8 | b);
// }

t_color_f	gradient(t_color color1, t_color color2, float y1, float y2)
{
	t_color_f	e_color;

	if (color1.color != color2.color)
	{
		e_color.alpha = 0.0;
		e_color.red = (color2.red - color1.red) / (float)(y2 - y1);
		if (color1.red == color2.red)
			e_color.red = 0.0;
		e_color.green = (color2.green - color1.green)  / (float)(y2 - y1);
		if (color1.green == color2.green)
			e_color.green = 0.0;
		e_color.blue = (color2.blue - color1.blue)  / (float)(y2 - y1);
		if (color1.blue == color2.blue)
			e_color.blue = 0.0;
	}
	else
		e_color = (t_color_f){0.0, 0.0, 0.0, 0.0};
	return (e_color);
}
