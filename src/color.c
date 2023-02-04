/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:38:28 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/03 17:01:21 by jvigny           ###   ########.fr       */
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
		e_color.alpha = 0;
		e_color.red = color2.red / (float)(y2 - y1);
		e_color.green = color2.green / (float)(y2 - y1);
		e_color.blue = color2.blue / (float)(y2 - y1);
	}
	else
		e_color = (t_color_f){0, 0, 0, 0};
	return (e_color);
}
