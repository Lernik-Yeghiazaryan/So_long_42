/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:30:38 by leyeghia          #+#    #+#             */
/*   Updated: 2022/09/07 14:30:41 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_coins_score(t_so_long *val)
{
	int	i;
	int	j;

	j = 0;
	while (j < val->map_height && val->map[j])
	{
		i = 0;
		while (val->map[j][i])
		{
			if (val->map[j][i] == 'C')
				return (0);
			++i;
		}
		++j;
	}
	return (1);
}

void	ft_putnbr(int c)
{
	int	num;

	num = 0;
	if (c > 9)
	{
		ft_putnbr(c / 10);
		ft_putnbr(c % 10);
	}
	else
	{
		num = c + 48;
		write(1, &num, 1);
	}
}
