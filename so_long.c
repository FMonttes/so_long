/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:13:41 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/06 13:28:25 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		main()
{
	t_game *data = malloc(sizeof(t_game));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 700, 400, "so_Long");
	//start_map(data);
	creat_map(data);
	mlx_loop(data->mlx);
}
