/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:04:11 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/07 12:57:37 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordonnee_3d	*ft_strdup(const t_coordonnee_3d *s, unsigned int len)
{
	t_coordonnee_3d	*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(t_coordonnee_3d) * len);
	if (res == NULL)
		return (0);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
