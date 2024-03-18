/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:18:59 by felipe            #+#    #+#             */
/*   Updated: 2024/03/18 10:41:27 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		gameplay(av[1], &game);
	}
	else
	{
		ft_printf("Error\nInvalid Sytax\n");
		exit(1);
	}
	return (0);
}
