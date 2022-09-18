/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:42:05 by leyeghia          #+#    #+#             */
/*   Updated: 2022/09/02 11:14:26 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_so_long
{
	void			*wall;
	void			*grass;
	void			*player;
	void			*exit_game;
	void			*coins;
	void			*mlx;
	void			*mlx_window;

	char			**map;

	int				image_height;
	int				image_length;
	int				map_height;
	int				map_length;
	int				coins_score;
	int				exit_score;
	int				player_score;
	int				move_count;
	int				p_x;
	int				p_y;
}					t_so_long;

char	**ft_split(char *str);
int		check_map(t_so_long *val);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_image_to_window(t_so_long *val);
int		key_func(int key_code, t_so_long *val);
int		ft_coins_score(t_so_long *val);
void	ft_print_map(t_so_long *val);
void	player_position(t_so_long *val);
void	ft_putnbr(int c);

#endif
