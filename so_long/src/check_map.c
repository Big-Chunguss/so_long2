/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:31:13 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 12:07:54 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	rectangle_map(char **map, t_data *data)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	length = ft_strlen(map[i]);
	data->map->coordinates.x = length;
	while (map[i] && map[i][0] != '\n')
	{
		if (length != (int)ft_strlen(map[i]))
			return (printf("Not the same length\n"), 0);
		if (map[i][0] != '1' || map[i][length - 2] != '1')
			return (printf("Wall problem!"), 0);
		i++;
	}
	data->map->coordinates.y = i;
	i--;
	while (j < length - 2)
	{
		if (map[0][j] != '1' || map[i][j] != '1')
			return (printf("Wall problem2!"), 0);
		j++;
	}
	return (1);
}

void	initalize(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = -1;
}

int	duplicate_map(char **map, t_map *data)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	j;

	initalize(&p, &e, &c, &i);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
		}
	}
	data->collect = c;
	if (p != 1 || e != 1 || !c)
		return (printf("Cases are wrong!\n"), 0);
	return (1);
}

int	valid_cases(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != '1' && map[i][j] != 'E'
				&& map[i][j] != '0' && map[i][j] != 'P' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(char **map, t_data *data)
{
	if (!valid_cases(map))
		return (0);
	if (!rectangle_map(map, data))
		return (0);
	if (!duplicate_map(map, data->map))
		return (0);
	if (!int_valid_path(map, data))
		return (0);
	return (1);
}
