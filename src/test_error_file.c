/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:50:20 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/21 14:50:23 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	format_file(char *str)
{
	int		len;
	int		len_cmp;
	char	cmp[5];
	int		boolean;

	boolean = 0;
	len_cmp = 4;
	ft_strlcpy(cmp, ".fdf", len_cmp + 1);
	len = ft_strlen(str);
	len = len - 1;
	len_cmp = len_cmp - 1;
	while (len >= 0 && len_cmp >= 0)
	{
		if (str[len] != cmp[len_cmp])
			break ;
		if (len_cmp == 0)
			boolean = 1;
		len--;
		len_cmp--;
	}
	return (boolean);
}

void	test_error(char *path, t_game *game)
{
	int		fd;
	char	str[1];

	if (format_file(path) == 0)
	{
		write(2, "Error: Try to open a file with the wrong format\n", 48);
		error(game, 0);
	}
	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		write(2, "Error: Try to open a directory not a file\n", 42);
		close(fd);
		error(game, 0);
	}
	fd = open(path, O_RDONLY);
	if (fd != -1 && read(fd, str, 1) == 0)
	{
		close(fd);
		ft_close(game);
	}
	close(fd);
}
