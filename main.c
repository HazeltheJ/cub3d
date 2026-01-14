/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 06:43:32 by ajami             #+#    #+#             */
/*   Updated: 2026/01/14 13:51:43 by ajami            ###   ########.fr       */
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
	if (check_file(av[1], ".cub"))
		exit(1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n Map can't be read"), 1);
	init_struct(&data, &game, &assets);
	read_stockage(av, fd, &data);
	read_map(&data);
	return (0);
}
