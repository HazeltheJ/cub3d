/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 06:43:32 by ajami             #+#    #+#             */
/*   Updated: 2026/01/12 17:36:26 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int			fd;
	t_data		data;
	t_game		game;
	t_assets	assets;

	if (ac != 2)
		return (ft_printf("Error \n The program run only with 2 arguments"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n Map can't be read"), 1);
	init_struct(&data, &game, &assets);
	if (check_file(av[1], ".cub"))
		exit(1);
	read_stockage(fd, &data); //countline + allocate map + fill data->game.map
	return (0);
}
