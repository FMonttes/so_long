/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:57:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/06 14:08:36 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# include <unistd.h>

typedef struct	s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*floor;
	void	*enemy;
	void	*wall;
	void	*colect;
	void	*player;
	int		width;
	int		height;
	char	**map;
}				t_game;

int		map_size(t_game *data);
void	malloc_map(t_game *data);
char	**fill_map(t_game *data);
char	**ft_split(char const *s, char c);
void	creat_map(t_game *data);
void	start_map(t_game *data);

#endif
