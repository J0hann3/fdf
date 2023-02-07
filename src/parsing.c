/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:11:52 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/07 15:27:08 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

unsigned int	ft_fdflen(char *arg, unsigned int *len_line, t_game *game)
{
	int		fd;
	char	*str;
	char	**split;
	unsigned int	len;
	unsigned int	len_split;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error(game);
	len = 0;
	len_split = 0;
	str = get_next_line(fd);
	if (str == NULL)
	{
		close(fd);
		error(game);		//not of the error it will print
	}
	split = ft_split(str, ' ');
	if (split == NULL)
	{
		free(str);
		close(fd);
		error(game);		//not of the error it will print
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

void	ft_fill_tab(char *arg, t_coordonnee_3d	*tab, int len_line, t_game *game)
{
	int		fd;
	char	*str;
	char	**split;
	unsigned int	y;
	unsigned int	x;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error(game);
	str = get_next_line(fd);
	y = 0;
	while (str != NULL)
	{
		split = ft_split(str, ' ');
		x = 0;
		while (split != NULL && split[x] != NULL)
		{
			tab[y * len_line + x] = (t_coordonnee_3d){x, y, ft_atoi(split[x]), (t_color){0}};
			x++;
		}
		free(str);
		free_split(split);
		str = get_next_line(fd);
		y++;
	}
	close(fd);
}

int	parsing(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		write(1, "Nombre d'arguments incorrect\n", 29);
		return (-1);
	}
	game->len = ft_fdflen(argv[1], &game->len_split, game);	// return the error
	game->tab = malloc(sizeof(t_coordonnee_3d) * game->len);
	if (game->tab == NULL)
		error(game);
	ft_fill_tab(argv[1], game->tab, game->len_split, game);	// return the error
	return (1);
}
