/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:10:03 by leyeghia          #+#    #+#             */
/*   Updated: 2022/07/16 14:10:05 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	itw(t_so_long *val, void *image, int x, int y)
{
	if (val->map[y][x] == 'P')
	{
		val->p_x = x;
		val->p_y = y;
	}
	mlx_put_image_to_window(val->mlx, val->mlx_window, image,
		x * val->image_length, y * val->image_height);
}

void	ft_xpm_to_image(t_so_long *val)
{
	val->image_length = 50;
	val->image_height = 50;
	val->grass = mlx_xpm_file_to_image(val->mlx, "pictures/grass.xpm",
			&val->image_length, &val->image_height);
	val->wall = mlx_xpm_file_to_image(val->mlx, "pictures/wall.xpm",
			&val->image_length, &val->image_height);
	val->player = mlx_xpm_file_to_image(val->mlx, "pictures/player.xpm",
			&val->image_length, &val->image_height);
	val->exit_game = mlx_xpm_file_to_image(val->mlx, "pictures/door.xpm",
			&val->image_length, &val->image_height);
	val->coins = mlx_xpm_file_to_image(val->mlx, "pictures/coin.xpm",
			&val->image_length, &val->image_height);
}

void	ft_image_to_window(t_so_long *val)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	ft_xpm_to_image(val);
	while (++y < val->map_height)
	{
		while (val->map[y][++x])
		{
			if (val->map[y][x] == '1')
				itw(val, val->wall, x, y);
			else if (val->map[y][x] == '0')
				itw(val, val->grass, x, y);
			else if (val->map[y][x] == 'C')
				itw(val, val->coins, x, y);
			else if (val->map[y][x] == 'P')
				itw(val, val->player, x, y);
			else if (val->map[y][x] == 'E')
				itw(val, val->exit_game, x, y);
		}
		x = -1;
	}
	mlx_hook(val->mlx_window, 2, 1L << 0, key_func, val);
}
