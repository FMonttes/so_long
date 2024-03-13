/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:13:41 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/13 12:54:58 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_game data;

	if (data.map)
		free_map(data.map);
	if (ac == 2)
	{
		data.map = fill_map(av[1]);
		start_game(&data);
		start_moves(&data);
		mlx_loop(&data.mlx);
		return (0);
	}
}
