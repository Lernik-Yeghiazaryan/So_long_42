/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:11:01 by leyeghia          #+#    #+#             */
/*   Updated: 2022/07/16 14:11:05 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	word_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] != ' '
		&& str[len] != '\t' && str[len] != '\n')
		len++;
	return (len);
}

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	while (*str)
	{
		++count;
		while (*str != ' ' && *str != '\t' && *str != '\n')
			str++;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
	}
	return (count);
}

static char	*word_dupe(char *str)
{
	int		i;
	char	*word;
	int		len;

	len = word_len(str);
	i = 0;
	word = malloc(len + 1);
	word[len] = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

static void	fill_words(char **line, char *str)
{
	int	index;

	index = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	while (*str)
	{
		line[index] = word_dupe(str);
		++index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			str++;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
	}
}

char	**ft_split(char *str)
{
	char	**line;
	int		len;

	len = count_words(str);
	line = malloc(sizeof(char *) * (len + 1));
	line[len] = NULL;
	fill_words(line, str);
	return (line);
}
