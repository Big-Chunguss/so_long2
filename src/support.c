/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:04:45 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 12:04:50 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_visited(int **visited, t_map *data)
{
	int	i;

	i = 0;
	while (i < data->row)
		free(visited[i++]);
	free(visited);
}

int	valid_position(char **map, int x, int y)
{
	if (map[x][y] != '1')
		return (1);
	return (0);
}

void	initialize_directions(int *dx, int *dy)
{
	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**copy_tab(char **tab)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	while (tab[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		j = ft_strlen(tab[i]);
		copy[i] = malloc(sizeof(char) * (j + 1));
		if (!copy[i])
		{
			free_tab_on_error(copy, 1);
			return (NULL);
		}
		ft_strlcpy(copy[i], tab[i], j + 1);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
