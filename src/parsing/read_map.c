/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:01:25 by ajami             #+#    #+#             */
/*   Updated: 2026/01/14 13:52:54 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	check_line(char *line, t_data *data)

int	read_stockage(char **av, int fd, t_data *data)
{
	count_lines(fd, data);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n Map can't be read"), 1);
	allocate_map(data);
	fill_map(fd, data);
	close(fd);
	return (0);
}
