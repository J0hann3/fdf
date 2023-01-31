/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:46:42 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/26 13:42:09 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	link_point(t_coordonnee_3d *tab, size_t len_split, size_t len,
			t_data *data, int color)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j * len_split < len)
	{
		i = 0;
		while (i < len_split - 1)
		{
			draw_line(tab[len_split * j + i], tab[len_split * j + i + 1], data, color);
			i++;
		}
		j++;
	}
	j = 0;
	while (j * len_split < len - len_split)
	{
		i = 0;
		while (i < len_split)
		{
			draw_line(tab[len_split * j + i], tab[len_split * (j + 1) + i], data, color);
			i++;
		}
		j++;
	}
}