/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visited.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:11:42 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/14 16:05:21 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	**allocate_visited_map(int row_count)
{
	int	**visited_map;
	int	x;

	visited_map = malloc(sizeof(int *) * row_count);
	if (!visited_map)
		return (NULL);
	x = 0;
	while (x < row_count)
	{
		visited_map[x] = NULL;
		x++;
	}
	return (visited_map);
}

int	allocate_visited_row(int **visited_map, char **map, int x)
{
	int	col_count;
	int	y;

	col_count = ft_strlen(map[x]);
	visited_map[x] = malloc(sizeof(int) * col_count);
	if (!visited_map[x])
		return (0);
	y = 0;
	while (y < col_count)
	{
		visited_map[x][y] = 0;
		y++;
	}
	return (1);
}

int	**map_visited(char **map)
{
	int	**visited_map;
	int	row_count;
	int	x;

	row_count = 0;
	while (map[row_count])
		row_count++;
	visited_map = allocate_visited_map(row_count);
	if (!visited_map)
		return (NULL);
	x = 0;
	while (x < row_count)
	{
		if (!allocate_visited_row(visited_map, map, x))
		{
			while (--x >= 0)
				free(visited_map[x]);
			free(visited_map);
			return (NULL);
		}
		x++;
	}
	return (visited_map);
}
