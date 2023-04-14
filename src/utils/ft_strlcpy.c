/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:35:31 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/21 14:32:06 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	if (n == 0)
		return (len);
	while (i < (n - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}
