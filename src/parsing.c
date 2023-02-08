/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:11:52 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 19:13:36 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

static unsigned int	ft_len(char **split, char *str, unsigned int *len, int fd)
{
	unsigned int	len_split;

	len_split = 0;
	while (split[len_split] != NULL)
		len_split++;
	free_split(split);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		*len = (*len) + 1;
	}
	return (len_split);
}

unsigned int	ft_fdflen(char *arg, t_game *game)
{
	int				fd;
	char			*str;
	char			**split;
	unsigned int	len;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error(game, 1);
	len = 0;
	str = get_next_line(fd);
	if (str == NULL)
		error(game, close(fd));
	split = ft_split(str, ' ');
	if (split == NULL)
	{
		free(str);
		error(game, close(fd));
	}
	game->len_split = ft_len(split, str, &len, fd);
	close(fd);
	return (len * game->len_split);
}

// static void	fill_line(char **split,t_game *game)
// {
	
// }

void	ft_fill_tab(char *arg, t_game *game)
{
	int				fd;
	char			*str;
	char			**split;
	unsigned int	y;
	unsigned int	x;
	x = 0;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error(game, 1);
	str = get_next_line(fd);
	y = 0;
	while (str != NULL)
	{
		split = ft_split(str, ' ');
		while (split != NULL && split[x] != NULL)
		{
			game->tab[y * game->len_split + x] = (t_coordonnee_3d){x, y,
				ft_atoi(split[x]), (t_color){0}};
			++x;
		}
		free(str);
		free_split(split);
		str = get_next_line(fd);
		++y;
	}
	close(fd);
}

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

int	parsing(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		write(2, "Error: Incorrect number of arguments\n", 37);
		error(game, 0);
	}
	test_error(argv[1], game);
	game->len = ft_fdflen(argv[1], game);
	game->tab = malloc(sizeof(t_coordonnee_3d) * game->len);
	if (game->tab == NULL)
		error(game, 1);
	ft_fill_tab(argv[1], game);
	return (1);
}
