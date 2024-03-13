/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:13:41 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/12 13:28:37 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int		main()
{
	t_game *data = malloc(sizeof(t_game));
	char **map;

	map = fill_map("./maps/map2.ber");
	data->map = map;
	start_game(data);
	start_moves(data);
	mlx_loop(data->mlx);
}
