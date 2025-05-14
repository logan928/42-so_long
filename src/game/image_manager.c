/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:18:39 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/12 14:18:43 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(void *mlx, t_game *tg, int img_no)
{
	if (img_no == 1)
	{
		mlx_destroy_image(mlx, tg->wall.img_ptr);
		return ;
	}
	else if (img_no == 2)
		mlx_destroy_image(mlx, tg->floor.img_ptr);
	else if (img_no == 3)
		mlx_destroy_image(mlx, tg->coin.img_ptr);
	else if (img_no == 4)
		mlx_destroy_image(mlx, tg->exit.img_ptr);
	else if (img_no == 5)
		mlx_destroy_image(mlx, tg->player_up.img_ptr);
	else if (img_no == 6)
		mlx_destroy_image(mlx, tg->player_down.img_ptr);
	else if (img_no == 7)
		mlx_destroy_image(mlx, tg->player_left.img_ptr);
	else if (img_no == 8)
		mlx_destroy_image(mlx, tg->player_right.img_ptr);
	free_images(mlx, tg, --img_no);
}

static t_image	get_tile(void *mlx, t_game *tg, char *path, int img_no)
{
	t_image	img;

	img.img_size = TILE_SIZE;
	img.img_ptr = mlx_xpm_file_to_image(mlx, path, &img.img_size, \
		&img.img_size);
	if (!img.img_ptr)
	{
		free_images(mlx, tg, img_no - 1);
		end_game(tg, tg->game_state);
	}
	return (img);
}

void	init_images(t_game	*tg)
{
	tg->wall = get_tile(tg->mlx, tg, WALL_PATH, 1);
	tg->floor = get_tile(tg->mlx, tg, FLOOR_PATH, 2);
	tg->coin = get_tile(tg->mlx, tg, COLLECT_PATH, 3);
	tg->exit = get_tile(tg->mlx, tg, EXIT_PATH, 4);
	tg->player_up = get_tile(tg->mlx, tg, PLAYER_PATH_U, 5);
	tg->player_down = get_tile(tg->mlx, tg, PLAYER_PATH_D, 6);
	tg->player_left = get_tile(tg->mlx, tg, PLAYER_PATH_L, 7);
	tg->player_right = get_tile(tg->mlx, tg, PLAYER_PATH_R, 8);
	tg->game_state = initiated_images;
}
