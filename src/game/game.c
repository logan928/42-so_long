/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:15:57 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/12 14:16:01 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_playability(char **map, t_map_size mz, t_map_details md)
{
	char			**temp_matrix;
	t_map_details	t_md;

	init_map_details(&t_md);
	temp_matrix = copy_matrix(map, mz);
	if (!temp_matrix)
	{
		free(map);
		print_error("Error in memory allocation");
	}
	flood_fill(temp_matrix, mz, md);
	parse_map(temp_matrix, mz, &t_md);
	if (t_md.collects != 0 || !check_exit(temp_matrix, t_md.e_y, t_md.e_x, mz))
	{
		free_map(temp_matrix, (mz.rows - 1));
		free_map(map, mz.rows);
		print_error("Invalid map: No path exists to collect and exit");
	}
	free_map(temp_matrix, mz.rows - 1);
}

void	init_game(t_game *tg, char ***map, t_map_details *md, t_map_size mz)
{
	initialize_game(tg, map, mz, md);
	tg->mlx = mlx_init();
	if (!(tg->mlx))
	{
		end_game(tg, tg->game_state);
		print_error("Error creating game handle");
	}
	tg->height = mz.rows;
	tg->width = mz.cols;
	tg->game_state = initiated_mlx;
	tg->win = mlx_new_window(tg->mlx, (tg->width) * TILE_SIZE, \
		(tg->height) * TILE_SIZE, "Pac 42");
	if (!(tg->win))
	{
		end_game(tg, tg->game_state);
		print_error("Error creating game window");
	}
	tg->game_state = initiated_window;
}
