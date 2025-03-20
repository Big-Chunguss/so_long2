/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ber_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:09:59 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/19 17:14:19 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../lib/get_next_line/get_next_line.h"
// Make sure get_next_line is declared in so_long.h or declare it here:
// char *get_next_line(int fd);

//check if rectangle
int rectangle_map(char **map)
{
    int i;
    int j;
    int length;
    
    i = 0;
    j = 0;
    length = ft_strlen(map[i]);
    while (map[i])
    {
            //printf("line: %s\nlength: %d\nlength2: %d\n", map[i], length, (int)ft_strlen(map[i]));
            //rectangular
            if (length != (int)ft_strlen(map[i]))
                return (printf("Not the same length\n"), 0);
            //walls at start and end of each line
            if (map[i][0] != '1' || map[i][length - 2] != '1')
                return (printf("Wall problem! %c %c", map[i][0], map[i][length - 2]),0);
            i++;
    }
    i--;
    //check end and start of map
    while (j < length - 2)
        {
            if (map[0][j] != '1' || map[i][j] != '1')
                return (printf("Wall problem2!"), 0); 
            j++;
        }
    return (1);
}

int duplicate_map(char **map)
{
    int p;
    int e;
    int c;
    int i;
    int j;
    
    p = 0;
    e = 0;
    c = 0;
    i = 0;
    while (map[i])
        {
            j = 0;
            while (map[i][j])
                {
                    if (map[i][j] == 'P')
                        p++;
                    if (map[i][j] == 'E')
                        e++;
                    if (map[i][j] == 'C')
                        c++;
                    j++;
                }
                i++;
        }
    if (p != 1 || e != 1 || !c)
        return (0);
    return (1);
}

t_xy    position_item(char **map, char c)
{
    t_xy res;
    int  i;
    int  j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                {
                    res.x = i;
                    res.y = j;
                    return (res);
                }
            j++;
        }
        i++;
    }
    res.x = 0;
    res.y = 0;
    return (res);
}


int validate_map(char **map)
{
    if (!rectangle_map(map))
        return (0);
    if (!duplicate_map(map))
        return (0);
    if (!int_valid_path(map))
        return (0);
    return (1);
}
int read_ber_file(const char *filename, t_map *map)
{
    int     fd;
    char    *line;
    char    **tab;
    int     count;
    char    **tmp;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return(printf("Error with the map!\n"), 0);
    tab = NULL;
    count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        tmp = realloc(tab, sizeof(char *) * (count + 2));
        if (!tmp)
        {
            while (count--)
                free(tab[count]);
            free(tab);
            return (0);
        }
        tab = tmp;
        tab[count] = line;
        count++;
    }
    if (tab)
        tab[count] = NULL;
    close(fd);
    if (!validate_map(tab))
        return (0);
    return (map->map = tab, 1);
}
