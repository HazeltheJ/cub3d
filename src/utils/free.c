/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:22:35 by ajami             #+#    #+#             */
/*   Updated: 2026/01/12 17:34:07 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	free_sprites(t_data *data)
{
	if (data->game.sprites.floor)
		mlx_destroy_image(data->game.mlx, data->sprites.floor);
	if (data->game.sprites.ceiling)
		mlx_destroy_image(data->game.mlx, data->sprites.ceiling);
	if (data->game.sprites.path_n)
		mlx_destroy_image(data->game.mlx, data->sprites.path_n);
	if (data->game.sprites.path_s)
		mlx_destroy_image(data->game.mlx, data->sprites.path_s);
	if (data->game.sprites.path_w)
		mlx_destroy_image(data->game.mlx, data->sprites.path_w);
	if (data->game.sprites.path_e)
		mlx_destroy_image(data->game.mlx, data->sprites.path_e);
}

static void	free_game(t_data *data)
{
	free_map(data->game.map);
	free_map(data->game.check_map);
	free_sprites(data);
	if (data->game.win)
		mlx_destroy_window(data->game.mlx, data->game.win);
	if (data->game.mlx)
	{
		mlx_destroy_display(data->game.mlx);
		free(data->game.mlx);
	}
}

int	close_window(t_data *data)
{
	free_game(data);
	ft_printf("See ya !\n");
	exit(0);
}

int	bad_close(t_data *data)
{
	free_game(data);
	ft_printf("Error\n Something went wrong !\n");
	exit(1);
}
