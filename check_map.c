/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:39:22 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/12 17:26:08 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int   check_map(t_game *data)
{
    int     i;
    int     x;

    start_stack(data);
    i = 0;
    while (data->map[i])
    {
        x = 0;
        while (data->map[i][x])
        {
            if (data->map[i][x] == 'E')
                data->n_exit++;
            else if (data->map[i][x] == 'C')
                data->n_colects++;
            else if (data->map[i][x] == 'P')
                data->n_player++;
            x++;
        }
        i++;
    }
    if (data->n_exit != 1 || data->n_player != 1 || data->n_colects < 1)
        return (1);
    else
        return (0);
}

int     is_retangular(t_game *data)
{
    int     i;
    int     x;

    x = 1;
    i = ft_strlen(data->map[0]);
    while (data->map[x])
    {
        if (ft_strlen(data->map[x++]) != i)
            return (1);
    }
    if (data->width != data->height)
        return (0);
    return (1);
}

void    get_size(t_game *data)
{
    int     i;

    i = 0;
    data->width = ft_strlen(data->map[0]) * 50;
    while (data->map[i])
        i++;
    data->height = i * 50;           
}

int     wall_check(t_game *data)
{
    int     i;
    int     x;

    i = 0;
    x = 0;
    while (data->map[0][x] == '1')
        x++;
    while (data->map[++i])
    {
        x = 0;
        while (data->map[i][++x])
        {
            if (data->map[i][0] != '1')
                return (1);
        }
        if (data->map[i][x - 1] != '1')
            return (1);
    }
    x = 0;
    while (data->map[i - 1][x] != '\0')
    {
        if (data->map[i - 1][x] != '1')
            return (1);
        x++;
    }
}

int     char_check(t_game *data)
{
    int     i;
    int     x;

    i = 0;
    while (data->map[i])
    {
        x = 0;
        while (data->map[i][x])
        {
            if (data->map[i][x] != 'P' && data->map[i][x] != 'E' && data->map[i][x] != '1'
            && data->map[i][x] != '0' && data->map[i][x] != 'C' && data->map[i][x] != 'K')
                return (1);
            x++;    
        }
        i++;
    }
}
