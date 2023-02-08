/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:11:52 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 11:12:02 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

unsigned int	ft_fdflen(char *arg, unsigned int *len_line, t_game *game)
{
	int				fd;
	char			*str;
	char			**split;
	unsigned int	len;
	unsigned int	len_split;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error(game, 1);
	len = 0;
	len_split = 0;
	str = get_next_line(fd);
	if (str == NULL)
	{
		close(fd);
		error(game, 0);		//exit failure if file empty
	}
	split = ft_split(str, ' ');
	if (split == NULL)
	{
		free(str);
		close(fd);
		error(game, 0);
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

void	ft_fill_tab(char *arg, t_coordonnee_3d	*tab, int len_line,
		t_game *game)
{
	int				fd;
	char			*str;
	char			**split;
	unsigned int	y;
	unsigned int	x;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error(game, 1);
	str = get_next_line(fd);
	y = 0;
	while (str != NULL)
	{
		split = ft_split(str, ' ');
		x = 0;
		while (split != NULL && split[x] != NULL)
		{
			tab[y * len_line + x] = (t_coordonnee_3d){x, y, ft_atoi(split[x]),
				(t_color){0}};
			x++;
		}
		free(str);
		free_split(split);
		str = get_next_line(fd);
		y++;
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
	game->len = ft_fdflen(argv[1], &game->len_split, game);
	game->tab = malloc(sizeof(t_coordonnee_3d) * game->len);
	if (game->tab == NULL)
		error(game, 1);
	ft_fill_tab(argv[1], game->tab, game->len_split, game);
	return (1);
}
