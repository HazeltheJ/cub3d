/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:01:25 by ajami             #+#    #+#             */
/*   Updated: 2026/01/12 17:53:51 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	check_line(char *line, t_data *data)

void	read_stockage(int fd, t_data *data)
{
	count_lines(fd, data);
	allocate_map(data);
	fill_map(fd, data);
	close(fd);
}
