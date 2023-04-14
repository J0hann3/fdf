/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:58:53 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 20:03:52 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trigo	fill_trigo(double angle)
{
	t_trigo	alpha;

	alpha.cos = cos(angle);
	alpha.sin = sin(angle);
	return (alpha);
}
