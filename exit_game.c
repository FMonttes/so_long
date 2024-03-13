/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:20:45 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/13 13:50:35 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_map(char **map)
{
    int     i;

    i = 0;
    while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int     exit_game(t_game *data)
{
    mlx_destroy_image(data->mlx, data->floor);
    mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player->img_player);
    mlx_destroy_image(data->mlx, data->colect);
    mlx_destroy_image(data->mlx, data->exit);
    mlx_destroy_image(data->mlx, data->enemy);
    mlx_destroy_window(data->mlx, data->mlx_win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    free(data->player);
    free_map(data->map);
    exit(0);
    return (0);
}
