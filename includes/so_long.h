/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:40:37 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/07 12:40:44 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#   define  SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "mlx.h"
#include "gnl.h"
#include "libft.h"
#include "ft_printf.h"

# define TILE_SIZE      32
# define WALL_PATH		"assets/Walls/wall.xpm" 
# define FLOOR_PATH		"assets/Walls/black.xpm" 
# define COLLECT_PATH	"assets/collectibles/pacdot_food.xpm"
# define EXIT_PATH	    "assets/Portal/portal.xpm"
# define PLAYER_PATH_R	"assets/pac-man/pac_semi_right.xpm"
# define PLAYER_PATH_L	"assets/pac-man/pac_semi_left.xpm"
# define PLAYER_PATH_U	"assets/pac-man/pac_semi_up.xpm"
# define PLAYER_PATH_D	"assets/pac-man/pac_semi_down.xpm"

enum e_direction
{
	left = 1,
	right = 2,
	up = 3,
	down = 4,
};

enum e_game_state
{
	started = 0,
	initiated_mlx = 1,
	initiated_window = 2,
	initiated_images = 3,
    redndered = 4,
    aborted = 5,
    ended = 6,
};

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map_size
{
    int rows;
    int cols;
}   t_map_size;

typedef struct s_map_details
{
    int walls;
    int floors;
    int exits;
    int collects;
    int players;
    int invalid;
    int is_rect;
    int is_enclosed;
    int p_x;
    int p_y;
    int e_x;
    int e_y;
    int f_count;
}   t_map_details;

typedef struct  s_image
{
    void    *img_ptr;
    int     img_size; 
}   t_image;

typedef struct s_game
{
    char    **map;
    t_map_size  mz;
    t_map_details   *md;
    void    *mlx;
    void    *win;
    int     width;
    int     height;
    int     path_count;
    int     game_state;
    t_image player_up;
    t_image player_down;
    t_image player_left;
    t_image player_right;
    t_image wall;
    t_image floor;
    t_image coin;
    t_image exit;
}   t_game;


void    init_map_size(t_map_size *mz, int r, int c);
void    free_map(char **map, int row_count);
void    init_map(char   *f_name, char ***map, t_map_size *mz, t_map_details *md);
void    init_map_details(t_map_details *md);
void    update_map_details(t_map_details *md, char element);
void    parse_map(char **map, t_map_size mz, t_map_details *md);
void    build_map(int fd, char ***map, char **f_line, t_map_size *mz);
void    update_start_pos(t_map_details *md, char element, int row, int col);
void    update_exit_pos(t_map_details *md, char element, int row, int col);
void    flood_fill(char **tab, t_map_size size, t_map_details md);
char    **copy_matrix(char **matrix, t_map_size mz);

void    print_error(char    *msg);
void    free_print(char **map, t_map_size mz, char *msg);
void    validate_file_name(char *f_name);
void    validate_f_empty(int fd, char **line);
void    validate_empty_lines(char **map_line);
void    parse_validate(char **map, t_map_size mz, t_map_details md);
void    check_playability(char **map, t_map_size mz, t_map_details md);
int     check_valid_exit(char **map, int e_row, int e_col, t_map_size mz);

void    init_game(t_game *tg, char  ***map, t_map_details *md, t_map_size mz);
void	init_images(t_game	*tg);
void    free_images(void *mlx, t_game *tg, int img_no);
void    end_game(t_game *tg, int game_state);

void print_map(char **map, t_map_size mz); //remove before submission

#endif

