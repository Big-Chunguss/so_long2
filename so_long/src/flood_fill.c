/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:52 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 12:13:14 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill(t_data *data, char target, int col, int row)
{
	if (col < 0 || row < 0 || col >= data->map->coordinates.x
		|| row >= data->map->coordinates.y)
		return ;
	if (data->map_flood->map[row][col] == 'F'
		|| data->map_flood->map[row][col] == 'E'
		|| data->map_flood->map[row][col] == '1')
		return ;
	data->map_flood->map[row][col] = 'F';
	fill(data, target, col + 1, row);
	fill(data, target, col - 1, row);
	fill(data, target, col, row + 1);
	fill(data, target, col, row - 1);
}

int	check_c(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_xy	limit_tab(char **tab)
{
	int		i;
	int		j;
	t_xy	limits;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	limits.x = j;
	limits.y = i;
	return (limits);
}

int	flood_fill(char **tab, t_data *data, t_xy begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	data->map_flood = malloc(sizeof(t_map));
	data->map_flood->map = copy_tab(tab);
	print_map(data->map_flood->map);
	printf("%c y: %d x: %d\n", target, begin.y, begin.x);
	printf("size y: %d x: %d\n", data->map->coordinates.y,
		data->map->coordinates.x);
	fill(data, target, begin.y, begin.x);
	if (check_c(data->map_flood->map))
	{
		free_tab(data->map_flood->map);
		free(data->map_flood);
		return (1);
	}
	free_tab(data->map_flood->map);
	free(data->map_flood);
	return (0);
}
