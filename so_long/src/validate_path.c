/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:41:35 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 12:06:01 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	int_valid_path(char **map, t_data *data)
{
	int	**visited;
	int	**visited2;

	data->player = position_item(map, 'P');
	visited = map_visited(map);
	visited2 = map_visited(map);
	if (!data->player.x || !data->player.y || !visited || !visited2)
		return (0);
	if (!valid_path(map, data->player.y, data->player.x, visited))
	{
		free_visited(visited, data->map);
		free_visited(visited2, data->map);
		return (printf("Path exit not valid!\n"), 0);
	}
	if (flood_fill(map, data, data->player))
	{
		free_visited(visited, data->map);
		free_visited(visited2, data->map);
		return (printf("Path collectibles not valid!\n"), 0);
	}
	return (free_visited(visited, data->map), free_visited(visited2, data->map),
		1);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("[%d] %s", i, map[i]);
		i++;
	}
	printf("\n");
}

int	valid_path(char **map, int pX, int pY, int **visited)
{
	int	next_x;
	int	next_y;
	int	dx[4];
	int	dy[4];
	int	i;

	initialize_directions(dx, dy);
	printf("Player exit = x: %d y: %d\n", pX, pY);
	if (map[pX][pY] == 'E')
		return (printf("Valid path player!\n"), 1);
	if (!valid_position(map, pX, pY) || visited[pX][pY])
		return (0);
	visited[pX][pY] = 1;
	i = 0;
	while (i < 4)
	{
		next_x = pX + dx[i];
		next_y = pY + dy[i];
		if (valid_path(map, next_x, next_y, visited))
			return (1);
		i++;
	}
	return (printf("No path exit!\n"), 0);
}
