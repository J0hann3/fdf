/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:32:31 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 11:47:35 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_printf_point_of_tab(t_coordonnee_3d *tab_3d, unsigned int len,
			t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		my_mlx_pixel_put(data, tab_3d[i].x, tab_3d[i].y, 0xFF);
		i++;
	}
}

void	draw_grille(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(img, j, i, 0xFFFFFF);
			j++;
		}
		i = i + 50;
	}
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0xFFFFFF);
			j++;
		}
		i = i + 50;
	}
}
