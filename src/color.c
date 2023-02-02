/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:38:28 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/02 17:52:02 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	degrade(int color1, int color2, int y, int d)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void)y;
	(void)d;

	// printf("color1: %d		color2: %d\n", color1, color2);
	r = ((((color1 >> 16) & 0xff) - ((color2 >> 16) & 0xff)) * ((float)y / d));
	g = ((((color1 >> 8) & 0xff) - ((color2 >> 8) & 0xff)) * ((float)y / d));
	b = (((color1 & 0xff) - (color2 & 0xff)) * ((float)y / d));
	// printf("r : %d		g: %d		b: %d		color: %d \n", r, g, b, r << 16 | g << 8 | b);
	return (r << 16 | g << 8 | b);
}
