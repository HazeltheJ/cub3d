/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajami <ajami@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 06:40:26 by ajami             #+#    #+#             */
/*   Updated: 2026/01/12 17:32:58 by ajami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

typedef struct s_sprites
{
	char		*floor;
	char		*path_n;
	char		*path_s;
	char		*path_e;
	char		*path_w;
	char		*ceiling;
}				t_sprites;

typedef struct s_assets
{
	int			*player;
	int			no;
	int			SO;
	int			WE;
	int			EA;
	int			F;
	int			C;
}				t_assets;

typedef struct s_game
{
	char		**map;
	char		**check_map;
	int			player_x;
	int			player_y;
	int			height;
	char		*floor_color;
	char		*ceiling_color;
	void		*mlx;
	void		*win;
	t_sprites	sprites;
}				t_game;

typedef struct s_data
{
	t_game		game;
	t_sprites	sprites;
	t_assets	assets;

}				t_data;

/*INIT MAP*/
int		check_file(char *str, char *ext);
void	allocate_map(t_data *data);
void	init_struct(t_data *data, t_game *game, t_assets *assets);
void	count_lines(int fd, t_data *data);
void	fill_map(int fd, t_data *data);
void	read_stockage(int fd, t_data *data);

/*CHECK MAP*/


/*FREE MAP*/
int		close_window(t_data *data);
int		bad_close(t_data *data);

#endif
