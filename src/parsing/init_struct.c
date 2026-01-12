/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:06:27 by ajami             #+#    #+#             */
/*   Updated: 2026/01/12 17:56:28 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *str, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(ext);
	j = ft_strlen(str) - i;
	i = 0;
	while (ext[i] != '\0')
	{
		if (str[j] != ext[i])
			return (ft_printf("Bad extension for the map\n"), 1);
		j++;
		i++;
	}
	return (0);
}

void	init_struct(t_data *data, t_game *game, t_assets *assets)
{
	ft_memset(data, 0, sizeof(t_data));
	ft_memset(game, 0, sizeof(t_game));
	ft_memset(assets, 0, sizeof(t_assets));
}

void	count_lines(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
		data->game.height++;
	}
	if (!line)
		get_next_line(-1);
}

void	allocate_map(t_data *data)
{
	data->game.map = malloc(sizeof(char *) * (data->game.height + 1));
	if (!data->game.map)
	{
		perror("Error\n  Can't allocate memory for the map");
		bad_close(data);
	}
	data->game.map[data->game.height] = NULL;
}

void	fill_map(int fd, t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	ft_printf("ici");
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		data->game.map[i] = ft_strdup(line);
		if (!data->game.map[i])
		{
			perror("Error\n  Can't allocate memory");
			get_next_line(-1);
			close(fd);
			bad_close(data);
		}
		free(line);
		line = get_next_line(fd);
		i++;
		if (!line)
			get_next_line(-1);
	}
}
