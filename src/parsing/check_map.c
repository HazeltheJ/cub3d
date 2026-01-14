/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:37:35 by ajami             #+#    #+#             */
/*   Updated: 2026/01/14 15:07:45 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*static  int check_wall_path(char *path)
{
    char tab[3];

    tab[0] = "NO";
    tab[1] = "SO";
    tab[2] = "WO";
    tab[3] = "EA";

    if (path == tab[0])
    
}*/
void    read_map(t_data *data)
{
        int y;
        int i;
        char *path;

        y = -1;
        i = 0;
        if (!data || !data->game.map)
            bad_close(data);
        while (++y < 1)
        {
            ft_printf("%c", data->game.map[y][i]);
            ft_printf("%c", data->game.map[y][++i]);
        }
        return;
}
