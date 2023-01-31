/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coordonnee_3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:01:58 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/25 17:16:05 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print(t_coordonnee_3d *tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		printf("x: %f	y: %f	z: %f\n", tab[i].x, tab[i].y, tab[i].z);
		i++;
	}
}
