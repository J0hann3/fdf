/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:30:14 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/28 17:35:17 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translation(t_coordonnee_3d *tab, size_t len, t_coordonnee_3d origine)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		tab[i].x = tab[i].x + origine.x;
		tab[i].y = tab[i].y + origine.y;
		i++;
	}
}
