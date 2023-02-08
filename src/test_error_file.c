/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:50:20 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 19:51:05 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	test_error(char *path, t_game *game)
{
	int		fd;
	char	str[1];

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
