/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:20:45 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/11 14:39:34 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **map)
{
    int i;

    i = 0;
    while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int exit_game(t_game *data)
{
    free_map(data->map);
    mlx_destroy_image(data->mlx, data->floor);
    mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->player->img_player);
    mlx_destroy_image(data->mlx, data->colect);
    //mlx_destroy_image(data->mlx, data->img_exit);
    mlx_destroy_window(data->mlx, data->mlx_win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}
