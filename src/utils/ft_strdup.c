/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:04:11 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/07 16:29:25 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordonnee_3d	*ft_strdup(const t_coordonnee_3d *s, unsigned int len,
		t_game *game)
{
	t_coordonnee_3d	*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(t_coordonnee_3d) * len);
	if (res == NULL)
		error(game, 1);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
