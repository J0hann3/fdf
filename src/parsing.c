/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:11:52 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/02 13:13:26 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_fdflen(char *arg, size_t *len_line)
{
	int		fd;
	char	*str;
	char	**split;
	size_t	len;
	size_t	len_split;

	fd = open(arg, O_RDONLY);
	len = 0;
	len_split = 0;
	str = get_next_line(fd);
	split = ft_split(str, ' ');
	if (split == NULL)
	{
		free(str);
		close(fd);
		return (0);
	}
	while (split[len_split] != NULL)
		len_split++;
	free_split(split);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		len++;
	}
	close(fd);
	*len_line = len_split;
	return (len * len_split);
}

void	ft_fill_tab(char *arg, t_coordonnee_3d	*tab, int len_line)
{
	int		fd;
	char	*str;
	char	**split;
	size_t	y;
	size_t	x;

	fd = open(arg, O_RDONLY);
	str = get_next_line(fd);
	y = 0;
	while (str != NULL)
	{
		split = ft_split(str, ' ');
		x = 0;
		while (split != NULL && split[x] != NULL)
		{
			tab[y * len_line + x] = (t_coordonnee_3d){x, y, ft_atoi(split[x]), 0};
			x++;
		}
		free(str);
		free_split(split);
		str = get_next_line(fd);
		y++;
	}
	close(fd);
}
