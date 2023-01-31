/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:32:31 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/30 12:00:13 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_printf_point_of_tab(t_coordonnee_3d *tab_3d, size_t len, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
			my_mlx_pixel_put(data, tab_3d[i].x, tab_3d[i].y, 0xFF);
		i++;
	}
}
