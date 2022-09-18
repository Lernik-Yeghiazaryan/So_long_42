/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:33:56 by leyeghia          #+#    #+#             */
/*   Updated: 2022/07/08 12:47:45 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	check_characters(t_so_long *val)
{
	int	i;
	int	j;

	j = -1;
	while (++j < val->map_height)
	{
		i = -1;
		while (++i < val->map_length && val->map[j][i])
		{
			if (!(val->map[j][i] == '1' || val->map[j][i] == '0'
			|| val->map[j][i] == 'P' || val->map[j][i] == 'E'
			|| val->map[j][i] == 'C'))
				return (0);
			if (val->map[j][i] == 'E')
				++val->exit_score;
			if (val->map[j][i] == 'P')
				++val->player_score;
			if (val->map[j][i] == 'C')
				++val->coins_score;
		}
	}
	if (val->exit_score > 0 && val->player_score == 1 && val->coins_score > 0)
		return (1);
	return (0);
}

static int	check_walls(t_so_long *val)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (val->map[0][i] && i < val->map_length)
	{
		if (val->map[0][i] == '1' && val->map[val->map_height - 1][i] == '1')
			++i;
		else
			return (0);
	}
	while (j < val->map_height)
	{
		if (val->map[j][0] == '1' && val->map[j][val->map_length - 1] == '1')
			++i;
		else
			return (0);
		++j;
	}
	return (1);
}

int	check_map(t_so_long *val)
{
	int	i;

	i = -1;
	while (++i < val->map_height && val->map[i])
		if (val->map_length != ft_strlen(val->map[i]))
			return (0);
	if ((!(check_characters(val)) || (!check_walls(val))))
		return (0);
	return (1);
}
