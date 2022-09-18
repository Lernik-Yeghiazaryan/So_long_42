/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:20:55 by leyeghia          #+#    #+#             */
/*   Updated: 2022/09/07 20:50:43 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(t_so_long *val)
{
	int	i;

	i = 0;
	while (i < val->map_height)
		printf("%s\n", val->map[i++]);
}

t_so_long	*mapsize(int fd)
{
	int			i;
	char		*str;
	char		*atr;
	t_so_long	*node;

	node = NULL;
	node = (t_so_long *)malloc(sizeof(t_so_long) * 1);
	i = 0;
	str = 0;
	atr = 0;
	while (1)
	{
		atr = get_next_line(fd);
		if (!atr)
			break ;
		str = ft_strjoin(str, atr);
		free(atr);
		++i;
	}
	node->map = ft_split(str);
	node->map_height = i;
	free(str);
	return (node);
}

int	main(int ac, char **av)
{
	char		*str;
	t_so_long	*val;

	str = ".ber";
	if (ac != 2)
		return (0);
	if (open(av[1], O_RDONLY) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	val = mapsize(open(av[1], O_RDONLY));
	val->map_length = ft_strlen(val->map[0]);
	val->mlx = mlx_init();
	if (ft_strcmp(av[1] + (ft_strlen(av[1]) - 4), str) || !check_map(val))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	val->mlx_window = mlx_new_window(val->mlx, val->map_length * 50,
			val->map_height * 50, "So_Long");
	ft_image_to_window(val);
	mlx_loop(val->mlx);
}
