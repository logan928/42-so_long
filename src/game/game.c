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

#include	"so_long.h"


void    initialize_game(t_game *tg, char ***map, t_map_size mz, t_map_details *md)
{
    tg->mlx = NULL;
    tg->win = NULL;
    tg->width = 0;
    tg->height = 0;
    tg->path_count = 0;
    tg->game_state = started;
    tg->map = *map;
    tg->mz = mz;
    tg->md = md;
    /*
    tg->player_up = NULL;
    tg->player_down = NULL;
    tg->player_left = NULL;
    tg->player_right = NULL;
    tg->wall = NULL;
    tg->floor = NULL;
    tg->coin = NULL;
    tg->exit = NULL;
    */
}

void    end_game(t_game *tg, int game_state)
{
    printf("%d \n", game_state);
    if (game_state == 0)
    {
        free_map(tg->map, tg->mz.rows);
        return;
    }
    else if (game_state == 1)
        mlx_destroy_display(tg->mlx);
    else if (game_state == 2)
        mlx_destroy_window(tg->mlx, tg->win);
    else if (game_state == 3)
        free_images(tg->mlx, tg, 8);

    end_game(tg, --game_state);
    
     //handle logic here.
}

void    init_game(t_game *tg, char  ***map, t_map_details *md, t_map_size mz)
{
    initialize_game(tg, map, mz, md);
    tg->mlx = mlx_init();
    if(!(tg->mlx))
    {
        end_game(tg, tg->game_state);
        print_error("Error creating game handle");
    }
    tg->height = mz.rows;
    tg->width = mz.cols;
    tg->game_state = initiated_mlx;
    tg->win = mlx_new_window(tg->mlx, (tg->width) * TILE_SIZE, (tg->height) * TILE_SIZE, "Pac 42");
    if(!(tg->win))
    {
        end_game(tg, tg->game_state);
        print_error("Error creating game window");
    }
    tg->game_state = initiated_window;
}
