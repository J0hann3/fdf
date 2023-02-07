/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:07:43 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/07 15:27:08 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_z(t_coordonnee_3d *tab, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		tab[i].x = tab[i].x - tab[i].z;
		tab[i].y = tab[i].y - tab[i].z;
		tab[i].z = 0;
		// printf("x: %d, y: %d\n", tab[i].x, tab[i].y);
		i++;
	}
}
