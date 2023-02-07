/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coordonnee_3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:01:58 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/07 15:36:03 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print(t_coordonnee_3d *tab, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		printf("x: %f	y: %f	z: %f	color: %x\n", tab[i].x, tab[i].y,
			tab[i].z, tab[i].color.color);
		i++;
	}
}

t_coordonnee_3d	sub(t_coordonnee_3d a, t_coordonnee_3d b)
{
	t_coordonnee_3d	new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	new.color = a.color;
	return (new);
}
