/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:11:52 by leyeghia          #+#    #+#             */
/*   Updated: 2022/09/02 11:14:18 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_so_long *val)
{
	int	x;
	int	y;

	x = val->p_x;
	y = val->p_y;
	if (val->map[y - 1][x] == 'E' && ft_coins_score(val))
	{
		mlx_destroy_window(val->mlx, val->mlx_window);
		exit(0);
	}
	else if (val->map[y - 1][x] != 'E' && val->map[y - 1][x] != '1')
	{
		ft_putnbr(++val->move_count);
		write(1, "\n", 1);
		val->map[y - 1][x] = 'P';
		val->map[y][x] = '0';
		mlx_clear_window(val->mlx, val->mlx_window);
		ft_image_to_window(val);
	}
}

static int	move_down(t_so_long *val)
{
	int	x;
	int	y;

	x = val->p_x;
	y = val->p_y;
	if (val->map[y + 1][x] == 'E' && ft_coins_score(val))
	{
		mlx_destroy_window(val->mlx, val->mlx_window);
		exit(0);
	}
	else if (val->map[y + 1][x] != 'E' && val->map[y + 1][x] != '1')
	{
		ft_putnbr(++val->move_count);
		write(1, "\n", 1);
		val->map[y + 1][x] = 'P';
		val->map[y][x] = '0';
		mlx_clear_window(val->mlx, val->mlx_window);
		ft_image_to_window(val);
	}
	return (1);
}

int	move_rigth(t_so_long *val)
{
	int	x;
	int	y;

	x = val->p_x;
	y = val->p_y;
	if (val->map[y][x + 1] == 'E' && ft_coins_score(val))
	{
		mlx_destroy_window(val->mlx, val->mlx_window);
		exit(0);
	}
	else if (val->map[y][x + 1] != 'E' && val->map[y][x + 1] != '1')
	{
		ft_putnbr(++val->move_count);
		write(1, "\n", 1);
		val->map[y][x + 1] = 'P';
		val->map[y][x] = '0';
		mlx_clear_window(val->mlx, val->mlx_window);
		ft_image_to_window(val);
	}
	return (1);
}

static int	move_left(t_so_long *val)
{
	int	x;
	int	y;

	x = val->p_x;
	y = val->p_y;
	if (val->map[y][x - 1] == 'E' && ft_coins_score(val))
	{
		mlx_destroy_window(val->mlx, val->mlx_window);
		exit(0);
	}
	else if (val->map[y][x - 1] != 'E' && val->map[y][x - 1] != '1')
	{
		ft_putnbr(++val->move_count);
		write(1, "\n", 1);
		val->map[y][x - 1] = 'P';
		val->map[y][x] = '0';
		mlx_clear_window(val->mlx, val->mlx_window);
		ft_image_to_window(val);
	}
	return (1);
}

int	key_func(int key_code, t_so_long *val)
{
	if (key_code == 53)
	{
		mlx_destroy_window(val->mlx, val->mlx_window);
		exit (0);
	}
	if (key_code == 126 || key_code == 13)
		move_up(val);
	else if (key_code == 125 || key_code == 1)
		move_down(val);
	else if (key_code == 124 || key_code == 2)
		move_rigth(val);
	else if (key_code == 123 || key_code == 0)
		move_left(val);
	return (0);
}
